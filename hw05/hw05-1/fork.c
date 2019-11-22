#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//Declare global variable
int		Var = 6;
char	Buf[] = "a write to stdout\n";

//This program check the which the parent process share with child or not.
int main()
{
	int		var;
	pid_t	pid;

	//In parent process, var = 88
	var = 88;
	//write to buf
	write(STDOUT_FILENO, Buf, sizeof(Buf)-1);
	printf("Before fork\n");

	//execute fork (error check)
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	//when it's child process
	else if (pid == 0)  {
		/* child */
		Var++;
		var++;
	}
	//when it's parent process
	else  {
		/* parent */
		sleep(2);
	}

	//print var or Var in each process.
	printf("pid = %d, Var = %d, var = %d\n", getpid(), Var, var);
	return 0;
}
