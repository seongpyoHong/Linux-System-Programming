#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	
	pid_t	pid;		//process id
	int		status;		//status variable

	//fork -> when error is raised.
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}

	//when it's child process
	else if (pid == 0)  {
		printf("I'm a child\n");
		sleep(2);
	}
	//when it's parent process
	else  {
		//wait unitl child process finish
		wait(&status);
		printf("A child killed with %d status\n", status);
	}
	return 0;
}
