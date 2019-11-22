#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include "synclib.h"
#include <stdlib.h>
#define	NLOOPS	10
#define	SIZE	sizeof(long)
#define	SHM_SIZE	1024
#define	SHM_MODE	(SHM_R | SHM_W | IPC_CREAT)

//update function
int update(long *ptr)
{
	return ((*ptr)++);
}

int main()
{
	
	int		fd, i, counter;
	pid_t	pid;
	int 	shmid;
	char 	*ptr;

	//make shared memory
	if((shmid = shmget(IPC_PRIVATE,SHM_SIZE,SHM_MODE)) <0){
		perror("shmget");
		exit(1);
	}
	//attach to shared memory
	if((ptr = shmat(shmid,0,0)) ==(void *)-1){
		perror("shmat");
		exit(1);
	}

	//create pipe
	TELL_WAIT();

	//fork process
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}

	//when process is parent process
	else if (pid > 0)  {
		for (i = 0 ; i < NLOOPS ; i += 2)  {
			if ((counter = update((long *)ptr)) != i)  {
				printf("Error Count : %d\n",counter);
				fprintf(stderr, "Counter mismatch\n");
				exit(1);
			}
			printf("Parent: counter=%d\n", counter);
			TELL_CHILD();
			WAIT_CHILD();
		}
	}
	
	//when process is child process
	else  {
		for (i = 1 ; i < NLOOPS ; i += 2)  {
			WAIT_PARENT();
			if ((counter = update((long *)ptr)) != i)  {
				printf("Error Count : %d\n",counter);
				fprintf(stderr, "Counter mismatch\n");
				exit(1);
			}
			printf("Child : counter=%d\n", counter);
			TELL_PARENT();
		}
	}
	
	//remove shared memory
	if (shmctl(shmid,IPC_RMID,0) <0){
		perror("shmctl");
		exit(1);
	}
	return 0;
}

