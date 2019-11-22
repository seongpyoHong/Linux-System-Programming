#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
static unsigned int AlarmSecs;
char *banner_argv[10];
void SigAlarmHandler(int signo){
	return ;
}

int main(int argc, char* argv[]){
	//insert to banner's argument vector
	banner_argv[0] = "banner";
	int i;
	for (i=2;argv[i]!='\0';i++){
		banner_argv[i-1]=argv[i];
	}
	banner_argv[i-1]=argv[i];

	//send SIGARLM after AlarmSecs.
	AlarmSecs = atoi(argv[1]);
	
	//declare signal handler for SIGALRM
	if (signal(SIGALRM,SigAlarmHandler)==SIG_ERR){
		perror("signal");
		exit(1);
	}

	//raise SIGALRM after AlarmSecs	
	alarm(AlarmSecs);
	//wait to SIGALRM
	pause();
	
	//call execvp with banner_argv
	if(execvp(banner_argv[0],banner_argv)<0){
		perror("execvp");
		exit(1);
	}
	return 0;
}	
