#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
//Signal handler
void SigIntHandler(int signo)
{
	printf("Received a SIGINT signal\n");
	printf("Terminate this process\n");

	exit(0);
}

int main()
{
	/* SIGINT signal handler: SigIntHandler */
	signal(SIGINT,SigIntHandler);

	printf("Press ^C to quit\n");

	for ( ; ; )
		pause();
return 0;
}
