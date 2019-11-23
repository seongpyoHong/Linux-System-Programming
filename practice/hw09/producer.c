#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "prodcons.h"
#include <stdlib.h>
int main()
{
	//Bounded Buffer
	BoundedBufferType	*pBuf;
	//shared memory id, index, data variable
	int					shmid, i, data;

	//create shared memory
	if ((shmid = shmget(SHM_KEY, SHM_SIZE, SHM_MODE)) < 0)  {
		perror("shmget");
		exit(1);
	}
	//attach the shared memeory
	if ((pBuf = (BoundedBufferType *)shmat(shmid, 0, 0)) == (void *) -1)  {
		perror("shmat");
		exit(1);
	}
	srand(0x8888);
	//doing loop by defined NLOOPS
	for (i = 0 ; i < NLOOPS ; i++)  {
		//check full condition
		if (pBuf->counter == MAX_BUF)  {
			printf("Producer: Buffer full. Waiting.....\n");
			//wait until buffer is not full
			while (pBuf->counter == MAX_BUF)
				;
		}
		
		printf("Producer: Producing an item.....\n");
		//make data randomly
		data = (rand()%100)*10000;

		pBuf->buf[pBuf->in].data = data;
		pBuf->in = (pBuf->in + 1) % MAX_BUF;
		pBuf->counter++;

		usleep(data);
	}
	//print the number of produced items
	printf("Producer: Produced %d items.....\n", i);
	sleep(2);
	//print the number of items in buffer
	printf("Producer: %d items in buffer.....\n", pBuf->counter);
	
	//remove shared memory
	if (shmctl(shmid, IPC_RMID, 0) < 0)  {
		perror("shmctl");
		exit(1);
	}
}
