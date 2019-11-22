#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>


#define	MY_ID		0
#define	SHM_KEY		(0x9000 + 46)
#define	SHM_SIZE	1024
#define	SHM_MODE	(SHM_R | SHM_W | IPC_CREAT)
char	Array[ARRAY_SIZE];


int main()
{
	//shared memory id
	int		shmid;
	char	*ptr, *shmptr;

	//dynamic allocation for ptr
	if ((ptr = (char *)malloc(MALLOC_SIZE)) == NULL)  {
		perror("malloc");
		exit(1);
	}

	//create shread memory
	if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, SHM_MODE)) < 0)  {
		perror("shmget");
		exit(1);
	}
	//attach to shared memory
	if ((shmptr = shmat(shmid, 0, 0)) == (void *) -1)  {
		perror("shmat");
		exit(1);
	}
	//check global variable address
	printf("Array[] from %p to %p\n", &Array[0], &Array[ARRAY_SIZE]);
	//check local variable address
	printf("Stack around %p\n", &shmid);
	//check dynamic allocation variable address
	printf("Malloced from %p to %p\n", ptr, ptr+MALLOC_SIZE);
	//shared memory address
	printf("Shared memory attached from %p to %p\n", shmptr, shmptr+SHM_SIZE);

	//remove shared memory
	if (shmctl(shmid, IPC_RMID, 0) < 0)  {
		perror("shmctl");
		exit(1);
	}
}
