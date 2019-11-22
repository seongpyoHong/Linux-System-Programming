#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
static unsigned int	AlarmSecs;

void SigAlarmHandler(int signo)
{
	if (signal(SIGALRM,SigAlarmHandler) == SIG_ERR)  {
		perror("signal");
		exit(1);
	}

	alarm(AlarmSecs);

	/* Do something */
	printf(".");
	fflush(stdout);

	return;
}

int SetPeriodicAlarm(unsigned int nsecs)
{
	if (signal(SIGALRM,SigAlarmHandler) == SIG_ERR) {
		return -1;
	}

	AlarmSecs = nsecs;

	alarm(nsecs);

	return 0;
}

int main()
{
	printf("Doing something every one seconds\n");

	SetPeriodicAlarm(1);

	for ( ; ; )
		pause();
}
