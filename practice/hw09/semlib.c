#include <stdio.h>
#include "semlib.h"
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
/*
 *	create semaphore
 */
int semInit(key_t key)
{
	//semaphore id
    int     semid;
	//create semaphore with key
    if ((semid = semget(key, 1, 0600 | IPC_CREAT)) < 0)  {
		perror("semget");
        return -1;
    }
    return semid;
}
 /*
  *	Set the initia value of semaphore	
  */
int semInitValue(int semid, int value)
{
	//union of semaphore value
    union semun {
            int     val;
    } semun;
	//set the value of semaphore
    semun.val = value;
    if (semctl(semid, 0, SETVAL, semun) < 0)  {
		perror("semctl");
        return -1;
    }
 
    return semid;
}
 /*
  *		Wait until semaphore is positive value.	
  */
int semWait(int semid)
{
    struct sembuf   semcmd;
 	//semaphore's number
    semcmd.sem_num = 0;
	//semaphore's operation
    semcmd.sem_op = -1;
	//wait until this thread can used the shared memory
    semcmd.sem_flg = SEM_UNDO;
   	//doing semaphore operation 
	if (semop(semid, &semcmd, 1) < 0)  {
		perror("semop");
        return -1;
    }
    return 0;
}
 
/*
 *	it's similar with semWait, but it's the async mode.
 */
int semTryWait(int semid)
{
	//semaphore buffer
    struct sembuf   semcmd;
 	//Just use a semaphore because of thread.
    semcmd.sem_num = 0;
	//semaphore operation
    semcmd.sem_op = -1;
	//add the IPC_NOWAIT option to async
    semcmd.sem_flg = IPC_NOWAIT | SEM_UNDO;
    if (semop(semid, &semcmd, 1) < 0)  {
		perror("semop");
        return -1;
    }
    return 0;
}
/*
 *	semaphore signal function
 */
int semPost(int semid)
{
	//semaphore buffer
    struct sembuf   semcmd;
 	//use a semaphore because of thread
    semcmd.sem_num = 0;
	//semaphore operation
    semcmd.sem_op = 1;

	//prevent deadlock
    semcmd.sem_flg = SEM_UNDO;
    //do semaphore operation
	if (semop(semid, &semcmd, 1) < 0)  {
		perror("semop");
        return -1;
    }
    return 0;
}

/*
 * 	get semaphore
 */
int semGetValue(int semid)
{
    union semun {
            int     val;
    } dummy;
 
	//return semaphore value
    return semctl(semid, 0, GETVAL, dummy);
}
 
//delete semaphore
int semDestroy(int semid)
{
    union semun {
            int     val;
    } dummy;
 	//remove semaphore by IPC_RMID flag
    if (semctl(semid, 0, IPC_RMID, dummy) < 0)  {
		perror("semctl");
        return -1;
    }
    close(semid);
    return 0;
}
