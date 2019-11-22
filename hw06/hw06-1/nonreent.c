/*
 multithread program or using signal program have to use the nonreent function
 */


#include <stdio.h>
#include <signal.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//SIGALRM Handler
void MyAlarmHandler(int signo)
{
	struct passwd	*rootptr;

	signal(SIGALRM, MyAlarmHandler);
	alarm(2);

	printf("in signal handler\n");
	if ((rootptr = getpwnam("root")) == NULL)  {
		perror("getpwnam");
		exit(1);
	}

	return;
}


int main()
{
	struct passwd	*ptr;

	signal(SIGALRM, MyAlarmHandler);
	alarm(2);

	for ( ; ; )  {
		if ((ptr = getpwnam("cjs")) == NULL)  {
			perror("getpwnam");
			exit(1);
		}
		if (strcmp(ptr->pw_name, "cjs") != 0)  {
			printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
			exit(0);
		}
	}
}
