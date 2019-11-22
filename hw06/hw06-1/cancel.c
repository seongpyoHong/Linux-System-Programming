#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
pthread_t	ThreadId[2];

void SigIntHandler(int signo)
{
	int		i;

	printf("Received a SIGINT signal by thread %d\n", pthread_self());
	printf("Terminate other threads: tid=%d, %d\n", ThreadId[0], ThreadId[1]);

	for (i = 0 ; i < 2 ; i++)  {
		/* Cancel execution of all threads */
		if (pthread_cancel(i))  {
			perror("pthread_cancel");
			exit(1);
		}
	}
	for (i = 0 ; i < 2 ; i++)  {
		if (pthread_join(ThreadId[i], NULL))  {
			perror("pthread_join");
			exit(1);
		}
	}
	printf("Threads terminated: tid=%d, %d\n", ThreadId[0], ThreadId[1]);

	exit(0);
}

void Thread1(void *dummy)
{
	printf("Thread %d created.....\n", pthread_self());

	if (pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL))  {
		perror("pthread_setcancelstate");
		pthread_exit(NULL);
	}
	if (pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL))  {
		perror("pthread_setcanceltype");
		pthread_exit(NULL);
	}

	while (1)
		;
}

void Thread2(void *dummy)
{
	printf("Thread %d created.....\n", pthread_self());

	if (pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL))  {
		perror("pthread_setcancelstate");
		pthread_exit(NULL);
	}
	if (pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL))  {
		perror("pthread_setcanceltype");
		pthread_exit(NULL);
	}

	while (1)
		;
}

int main()
{
	if (pthread_create(&ThreadId[0], NULL, (void *)Thread1, NULL) < 0)  {
		perror("pthread_create");
		exit(1);
	}
	if (pthread_create(&ThreadId[1], NULL, (void *)Thread2, NULL) < 0)  {
		perror("pthread_create");
		exit(1);
	}

	signal(SIGINT, SigIntHandler);

	printf("Press ^C to quit\n");

	for ( ; ; )
		pause();
}
