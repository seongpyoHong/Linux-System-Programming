#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//thread function : sum thread's index ~ index + 50
void iteration(void *index){
	
	int sum = 0;
	//convert type
	int idx = *((int*)index);
	for(int i = idx; i<idx + 50;i++){
		sum += i;
	}
	//exit thread and return sum 
	pthread_exit((void*)sum);
}

int main(){

	//thread id
	pthread_t tid1,tid2;
	//thread 1 parameter
	int index1 = 1;
	//thread 2 parameter
	int index2 = 51;
	//variable to store thread 1 result
	int output1 = 0;
	//variable to store thread 2 result
	int output2 = 0;
	//thread 1 create , thread function : iteration, thread parameter : index1
	if((pthread_create(&tid1,NULL,(void *)iteration,(void*)&index1))<0){
		perror("pthread_create");
		exit(1);
	}
	//thread 2 create, thread function : iteration, thread parameter : index2
	if((pthread_create(&tid2,NULL,(void *)iteration,(void *)&index2))<0){
		perror("pthread_create");
		exit(1);
	}

	//wait until thread 1 finish and store the return value to output1
	if(pthread_join(tid1,(void *)&output1)<0){
		perror("pthread_join");
		exit(1);
	}
	
	//wait until thread 2 finish and store the return value to output2
	if(pthread_join(tid2,(void *)&output2)<0){
		perror("pthread_join");
		exit(1);
	}

	//sum the each output of thread
	int result = output1 + output2;
	
	//print result
	printf("Result : %d\n",result);
}

