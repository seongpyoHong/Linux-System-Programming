#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int		pid;
	//execute fork
	if ((pid = fork())<0)  {
		perror("fork");
		exit(1);
	}

	//if pid (fork's return value) is zero, it's child process
	else if (pid == 0)  {
		/* child */
		printf("I am %d. My parent is %d.\n", getpid(), getppid());
	}

	//if pid (fork's return value is not zero, it's parent process)
	else  {
		/* parent */
		printf("I am %d. My child is %d.\n", getpid(), pid);
	}

	return 0;
}
