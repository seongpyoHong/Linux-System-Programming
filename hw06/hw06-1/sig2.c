#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/*
 Signal Handler
 */
void SigUsrHandler(int signo)
{
	//when signal number is SIGUSR1
	if (signo == SIGUSR1)  {
		printf("Received a SIGUSR1 signal\n");
	}
	//when signal number is SIGUSR2
	else if (signo == SIGUSR2)  {
		printf("Received a SIGUSR2 signal\n");
	}
	//when signal number is other signal number except above two.
	else  {
		printf("Received unknown signal\n");
		printf("Terminate this process\n");
		exit(0);
	}
}

int main()
{
	/* SIGUSR1 signal handler: SigUsrHandler */
	if (signal(SIGUSR1,SigUsrHandler)==SIG_ERR)  {
		perror("signal");
		exit(1);
	}

	/* SIGUSR2 signal handler: SigUsrHandler */
	if (signal(SIGUSR2, SigUsrHandler) == SIG_ERR)  {
		perror("signal");
		exit(1);
	}

	for ( ; ; )
		pause();
return 0;
}
