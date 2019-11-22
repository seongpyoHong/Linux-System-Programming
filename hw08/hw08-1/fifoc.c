#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "fifo.h"
#include <stdlib.h>
#include <string.h>

int main() {
	//fifo's name
	char		fname[MAX_FIFO_NAME];
	//file descriptor
	int			fd, sfd, n;
	//message type
	MsgType		msg;
	//set file name
	sprintf(fname, ".fifo%d", getpid());
	//make fifo with fname
	if (mkfifo(fname, 0600) < 0)  {
		perror("mkfifo");
		exit(1);
	}
	//open fifo file
	if ((fd = open(fname, O_RDWR)) < 0)  {
		perror("open");
		exit(1);
	}
	//open server's fifo
	if ((sfd = open(SERV_FIFO, O_RDWR)) < 0)  {
		perror("open");
		exit(1);
	}
	//copy string from fname to returnFifo
	strcpy(msg.returnFifo, fname);
	sprintf(msg.data, "This is a request from %d.", getpid());
	//write to fifo
	write(sfd, (char *)&msg, sizeof(msg));
	printf("Sent a request.....");
	
	//wait to read
	if ((n = read(fd, (char *)&msg, sizeof(msg))) < 0)  {
		perror("read");
		exit(1);
	}

	printf("Received reply: %s\n", msg.data);
	
	//close both file descriptor
	close(fd);
	close(sfd);
	
	//remove client fifo
	if (remove(fname) < 0)  {
		perror("remove");
		exit(1);
	}
}
