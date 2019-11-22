#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
//SIGALRM signal handler
void SigAlarmHandler(int signo)
{
	/* nothing to do, just return to wake up the pause */
	return;
}

unsigned int mysleep(unsigned int nsecs)
{
	/* SIGALRM signal handler: SigAlarmHandler */
	if (signal(SIGALRM,SigAlarmHandler)==SIG_ERR)  {
		return nsecs;
	}

	alarm(nsecs);

	pause();

	return alarm(2);
}

int main (){
	printf("Wait for 5 seconds...\n");

	int ret = mysleep(5);
	printf("return : %d ",ret);
	return 0;
}
