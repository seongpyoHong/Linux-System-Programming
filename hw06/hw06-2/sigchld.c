#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
//Signal Handler
void SigchldHandler(int signo){
	printf("\nFinish Child Process!\n");
	printf("Send the SIGCHLD to parent process.\n");
 	exit(1);
}

int main(){
	pid_t 	pid;	//process id
	int status; 	//status variable

	signal(SIGCHLD, SigchldHandler);
	//fork & when error is raised.
	if((pid = fork()) <0){
		perror("fork");
		exit(1);
	}

	//when it's child process
	else if (pid ==0){
		printf("It's child process.\n");
		sleep(3);
	}

	//when it's parent process
	else {
		//wait until child process finish
		printf("waiting the signal of child process.\n");
		while(1){
		}
	}
	return 0;
}
