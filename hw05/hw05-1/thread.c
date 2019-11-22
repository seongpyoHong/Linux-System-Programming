#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//Function to pring msg
void PrintMsg(char *msg)
{
	printf("%s", msg);
	//thread exit 
	pthread_exit(NULL);
}

int main()
{
	//thread id
	pthread_t	tid1, tid2;
	//character variable to print
	char		*msg1 = "Hello, ";
	char		*msg2 = "World!\n";

	/* Thread ID: tid1, Thread function: PrintMsg, Thread argument: msg1 */
	if (pthread_create(&tid1, NULL, (void *)PrintMsg, (void *)msg1) <0)  {
		perror("pthread_create");
		exit(1);
	}
	// Thread ID: tid2, Thread function : PrintMsg, Thread argument : msg2
	if (pthread_create(&tid2, NULL, (void *)PrintMsg, (void *)msg2) < 0)  {
		perror("pthread_create");
		exit(1);
	}

	//print thread id
	printf("Threads created: tid=%d, %d\n", tid1, tid2);

	/* Wait for tid1 to exit */
	if (pthread_join(tid1,NULL) < 0)  {
		perror("pthread_join");
		exit(1);
	}
	//Wait for tid2 to exit
	if (pthread_join(tid2, NULL) < 0)  {
		perror("pthread_join");
		exit(1);
	}

	//print that the all thread is terminated 
	printf("Threads terminated: tid=%d, %d\n", tid1, tid2);
}
