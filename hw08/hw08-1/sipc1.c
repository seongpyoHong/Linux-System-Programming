#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm.h"
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int		shmid;
	char	*ptr, *pData;
	int		*pInt;

	/* SHM_KEY, SHM_SIZE, SHM_MODE in shm.h */
	if ((shmid = shmget(SHM_KEY,SHM_SIZE,SHM_MODE)) < 0)  {
		perror("shmget");
		exit(1);
	}
	if ((ptr = shmat(shmid,0,0))==(void *)-1)  {
		perror("shmat");
		exit(1);
	}

	pInt = (int *)ptr;
	while ((*pInt) == 0)
		;

	pData = ptr + sizeof(int);
	printf("Received request: %s.....", pData);
	sprintf(pData, "This is a reply from %d.", getpid());
	*pInt = 0;
	printf("Replied.\n");

	sleep(1);

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
