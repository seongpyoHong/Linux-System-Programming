#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include "fifo.h"
#include <stdlib.h>

//SignalHandler to delete fifo
void SigIntHandler(int signo) {
	if (remove(SERV_FIFO) < 0)  {
		perror("remove");
		exit(1);
	}
	exit(0);
}

int main() {
	//file descriptor
	int			fd, cfd, n;
	//message Type
	MsgType		msg;

	//register signal handler of SIGINT
	if (signal(SIGINT, SigIntHandler) == SIG_ERR)  {
		perror("signal");
		exit(1);
	}

	//make server's fifo
	if (mkfifo(SERV_FIFO, 0600) < 0)  {
		if (errno != EEXIST)  {
			perror("mkfifo");
			exit(1);
		}
	}

	//open server fifo and get file descriptor
	if ((fd = open(SERV_FIFO, O_RDWR)) < 0)  {
		perror("open");
		exit(1);
	}

	while (1)  {
	//read message from server fifo
		if ((n = read(fd, (char *)&msg, sizeof(msg))) < 0)  {
			if (errno == EINTR)  {
				continue;
			}
			else  {
				perror("read");
				exit(1);
			}
		}
		printf("Received request: %s.....", msg.data);

		//write message to client own fifo.
		if ((cfd = open(msg.returnFifo, O_WRONLY)) < 0)  {
			perror("open");
			exit(1);
		}
	
		sprintf(msg.data, "This is a reply from %d.", getpid());
		write(cfd,(char*)&msg,sizeof(msg));
		//close cilent's file descriptor
		close(cfd);
		printf("Replied.\n");
	}
}
