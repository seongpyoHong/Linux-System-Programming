#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

//thread function
void printLower(char* name){
	FILE* src;
	char ch;
	int count =0;
	//file open
	if((src = fopen(name,"rt"))==NULL){
		perror("fopen");
		exit(1);
	}
	//check lower
	while(fread(&ch, sizeof(ch),1,src) != 0){
		if('a' <= ch && ch<= 'z')
			count ++;
	}

	//print result
	printf("%s : %d\n",name,count);
	fclose(src);	
}

int main(int argc, char *argv[]){

	//thread's id vector (MAX SIZE : 15)
	pthread_t tid[15];
	if (argc ==1){
		printf("Wrong Number of argument!\n");
	}

	//thread create and wait to finish the thread function
	for(int i=1;i<argc;i++){
		char* name = argv[i];
		//thread create
		if(pthread_create(&tid[i-1],NULL,(void *)printLower,(void *)name)<0){
			perror("pthread_create");
			exit(1);
		}
		//wait until thread function finish
		if(pthread_join(tid[i-1],NULL)<0){
			perror("pthread_join");
			exit(1);
		}
	}
}

