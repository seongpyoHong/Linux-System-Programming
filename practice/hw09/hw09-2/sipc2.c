#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>

#include "semlib.h"
#include "setting.h"

int main()
{
	int		shmid, semId;
	char	*ptr, *pData;

	//create shared memory
	if ((shmid = shmget(SHM_KEY,SHM_SIZE,SHM_MODE))<0)  {
		perror("shmget");
		exit(1);
	}

	//attach shread memory
	if ((ptr = shmat(shmid,0,0)) == (void *)-1)  {
		perror("shmat");
		exit(1);
	}

	//semaphore Init
	if(( semId = semInit(SEM_KEY)) < 0){
		fprintf(stderr, "semInit Failure\n");	
	}
	//Set semaphore initial vaule
	if(semInitValue(semId,1) < 0) {
		fprintf(stderr, "semInitValue failure\n");
	}
	//wait
	if(semWait(semId) < 0){
		fprintf(stderr, "semWait Failure\n");
	}

	pData = ptr + sizeof(int);
	sprintf(pData, "This is a request from %d.", getpid());
	printf("Sent a request.....");

	printf("Received reply: %s\n", pData);

	if(semWait(semId) < 0){
		fprintf(stderr, "semPost Failure\n");
	}
	/* Detach shared memory */
	if (shmdt(ptr)<0)  {
		perror("shmdt");
		exit(1);
	}
}
