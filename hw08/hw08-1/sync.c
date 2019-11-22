#include <unistd.h>
#include <stdio.h>
#include "synclib.h"
#include <stdlib.h>
#define	NLOOPS	5

int main()
{
	//process id
	int		i;
	pid_t	pid;
	
	//make pipe
	TELL_WAIT();
	//fork child process
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	//case whne process is parent
	else if (pid > 0)  {
		//Parent read after write
		for (i = 0 ; i < NLOOPS ; i++)  {
			TELL_CHILD();
			printf("Parent: Tell to child\n");
			printf("Parent: Wait for child to tell\n");
			WAIT_CHILD();
		}
	}
	//case when process is child
	else  {
		//Child write after read
		for (i = 0 ; i < NLOOPS ; i++)  {
			printf("Child: Wait for parent to tell\n");
			WAIT_PARENT();
			TELL_PARENT();
			printf("Child: Tell to parent\n");
		}
	}
}
