#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_CMD		256
//global variable to store argument size
int size = 1;

//function to count blank in input string
int countBlank(char* cmd){
	int blank_cnt=0;
	while(*cmd){
		if (*cmd == ' ')
			blank_cnt++;
		*cmd++;
	}
	return blank_cnt;
}

//function to perform the same operation with system
int mysystem(char* cmd){
	//process id
	int p_id;
	//arguments vector
	char *argv[size];
	
	//process fork and check the error
	if((p_id = fork())<0){
		perror("fork");
		exit(1);
	}

	//when it's child process
	else if (p_id == 0){
		int index = 0;
		//split the input string by blank
		char* arg = strtok(cmd," ");
		while(arg != NULL){
			//append to argument vector
			argv[index] = arg;
			index ++;
			arg = strtok(NULL," ");
		}
		//append NULL to last index in argument vector 
		argv[size-1] = '\0';
		//call the execvp
		if(execvp(argv[0],argv)<0){
			perror("execvp");
			exit(1);
		}
	}
	else {
	//wait until the child process finish
	if(waitpid(p_id,NULL,0)<0) {
		perror("waitpid");
		exit(1);
		}
	}
	return 0;
}

int main(){
	//variable to store user input string
	char cmd[MAX_CMD];
	//pointer to delete \n
	char* delPtr;
	//status variable
	int status;
	printf("CMD> ");
	//store the stdin buffer's content to cmd
	fgets((char *)cmd,MAX_CMD,stdin);
	//delete \n
	if ((delPtr = (char *)strchr(cmd, '\n')) != NULL)
		*delPtr = '\0';
	//allocate size
	size = countBlank(cmd)+2;
	//mysystem error check
	if((status = mysystem(cmd)) != 0 )
		printf("My System Error");
}
