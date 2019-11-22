#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "synclib.h"
#include <stdlib.h>
#define	NLOOPS	10
#define	SIZE	sizeof(long)

//update function
int update(long *ptr)
{
	return ((*ptr)++);
}

int main()
{
	
	int		fd, i, counter;
	pid_t	pid;
	caddr_t	area;

	//"dev/zero file open"
	if ((fd = open("/dev/zero", O_RDWR)) < 0)  {
		perror("open");
		exit(1);
	}
	//mapping the file which is pointed by fd
	if ((area = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0))
			== (caddr_t) -1)  {
		perror("mmap");
		exit(1);
	}
	close(fd);

	//setting the shared memory
	TELL_WAIT();

	//fork process
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	//when process is parent process
	else if (pid > 0)  {
		for (i = 0 ; i < NLOOPS ; i += 2)  {
			if ((counter = update((long *) area)) != i)  {
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
			if ((counter = update((long *) area)) != i)  {
				fprintf(stderr, "Counter mismatch\n");
				exit(1);
			}
			printf("Child : counter=%d\n", counter);
			TELL_PARENT();
		}
	}
}
