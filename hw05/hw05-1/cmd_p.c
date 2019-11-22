#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define	MAX_CMD		256

//Function to print cmd input
void DoCmd(char *cmd)
{
	printf("Doing %s", cmd);
	sleep(1);
	printf("Done\n");
}


int main()
{
	//variable to store cmd input
	char	cmd[MAX_CMD];
	//process id
	int		pid;

	//CMD input
	while (1)  {
		printf("CMD> ");
		//store to STDIN buffer
		fgets(cmd, MAX_CMD, stdin);
		//break condition
		if (cmd[0] == 'q')
			break;
		//fork error check
		if ((pid = fork())<0)  {
			perror("fork");
			exit(1);
		}
		//when it's child process
		else if (pid == 0)  {
			DoCmd(cmd);
			exit(0);
		}
#if 0
		else  {
			wait(NULL);
		}
#endif
	}
	return 0;
}
