/*
pipe.c 에 추가하여 child도 parent에게 메시지를 전달하도록 변경
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define	MAX_BUF	128

int main()
{
	/* Declare file descriptor and variable to store bytes for reading.
	 * Cfd	:	Client -> Parent
	 * Pfd	:	Parent -> Clinet
	 */
	int		n, Cfd[2], Pfd[2];
	pid_t	pid;				//process Id
	char	buf[MAX_BUF];		//Buffer to store string

	//create two pipe
	if (pipe(Cfd)<0 || pipe(Pfd)<0)  {
		perror("pipe");
		exit(1);
	}

	//fork child process
	if ((pid = fork()) < 0)  
		perror("fork");
		exit(1);
	}

	//when process is child process
	if (pid == 0)  {
		printf("Child : Wait for parent to send data\n");
		
		//read from pipe(parent's write file descriptor) : go to line 60
		if ((n=read(Pfd[0],buf,MAX_BUF))<0)  {
			perror("read");
			exit(1);
		}
		
		printf("Child : Received data from parent: ");
		
		//make stdout empty 
		fflush(stdout);
		
		//write to stdout from buf
		write(STDOUT_FILENO, buf, n);
		
		//write to buf
		strcpy(buf,"\tChild -> Parent\n");
		
		//write to pipe (child write pipe)
		write(Cfd[1],buf,strlen(buf)+1);
		printf("Child : Send data to parent.\n");
	}

	//when process is parent process
	else  {
		//string copy to buf
		strcpy(buf, "\tParent -> Child\n");
		printf("Parent: Send data to child\n"); 
		
		//write to buf 
		write(Pfd[1], buf, strlen(buf)+1);
		
		//wait to read from child process	
		printf("Parent : Wait for child to send data\n");	
		if((n=read(Cfd[0],buf,MAX_BUF))<0) {
			perror("read");
			exit(1);
		}
		printf("Parent : Received data from child:");
		
		//make stdout empty
		fflush(stdout);
		
		//write to STDOUT from buf.
		write(STDOUT_FILENO,buf,n);
	}

	exit(0);
}
