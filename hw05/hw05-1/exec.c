#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t	pid;		//process id
	char	*argv[] = { "mycp", "exec.c", "exec2.c", NULL };	//character array instead of command line arguments.

	// execl
	// fork and error check
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	//when it's child process
	else if (pid == 0)  {
		// mycp exec.c exec2.c
		if (execl("/home/lsp46/hw03/hw03-1/mycp","mycp","exec.c","exec2.c",NULL)<0)  {
			perror("execl");
			exit(1);
		}
	}
	//wait until child process finish
	if (waitpid(pid, NULL, 0) < 0)  {
		perror("waitpid");
		exit(1);
	}

	// execv
	// fork and error check
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	//when it's child process
	else if (pid == 0)  {
		// mycp exec.c exec2.c
		if (execv("/home/lsp46/hw03/hw03-1/mycp",argv)<0)  {
			perror("execv");
			exit(1);
		}
	}
	//wait until child process finish
	if (waitpid(pid, NULL, 0) < 0)  {
		perror("waitpid");
		exit(1);
	}

	// execlp
	// fork and error check
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	//when it's child process
	else if (pid == 0)  {
		// execute 'env' from PATH
		if (execlp("env","env",NULL)<0)  {
			perror("execlp");
			exit(1);
		}
	}
	//wait until child process finish
	if (waitpid(pid, NULL, 0) < 0)  {
		perror("waitpid");
		exit(1);
	}
}
