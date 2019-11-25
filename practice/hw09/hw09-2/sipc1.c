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
	//shared memory id
	int		shmid, semId;
	char	*ptr, *pData;
	
	//create shared memory
	if ((shmid = shmget(SHM_KEY,SHM_SIZE,SHM_MODE)) < 0)  {
		perror("shmget");
		exit(1);
	}
	//Shared Memory
	if ((ptr = shmat(shmid,0,0))==(void *)-1)  {
		perror("shmat");
		exit(1);
	}
	//Semaphore Init
	if((semId = semInit(SEM_KEY)) < 0){
		fprintf(stderr, "semInit Failure\n");
	}
	//wait
	if(semWait(semId)<0){
		fprintf(stderr, "semWait failure\n");
	}	
	pData = ptr + sizeof(int);
	printf("Received request: %s.....", pData);
	sprintf(pData, "This is a reply from %d.", getpid());
	printf("Replied.\n");

	sleep(1);
	//signal
	if(semPost(semId) < 0){
		fprintf(stderr, "semPost Failure\n");
	}

	/* Detach shared memory */
	if (shmdt(ptr)<0)  {
		perror("shmdt");
		exit(1);
	}

	/* Remove shared memory */
	if (shmctl(shmid,IPC_RMID,0) < 0)  {
		perror("shmctl");
		exit(1);
	}
}
