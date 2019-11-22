#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define	MAX_CMD		256

//function to print cmd input 
void DoCmd(char *cmd)
{
	printf("Doing %s", cmd);
	sleep(1);
	printf("Done\n");

	pthread_exit(NULL);
}

int main()
{
	//variable to store cmd input
	char		cmd[MAX_CMD];
	//thread id
	pthread_t	tid;

	while (1)  {
		printf("CMD> ");
		//put the stdin to cmd buffer
		fgets(cmd, MAX_CMD, stdin);	
		//break condition
		if (cmd[0] == 'q')
			break;

		//thread create
		if (pthread_create(&tid, NULL, (void *)DoCmd, (void *)cmd) < 0)  {
			perror("pthread_create");
			exit(1);
		}

#if 0
		pthread_join(tid, NULL);
#endif
	}
}
