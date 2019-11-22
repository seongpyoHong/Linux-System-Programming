#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]){

	//argument error check
	if(argc != 2){
		printf("Wrong Number of Arguments.");
		exit(1);
	}

	//input is converted to int
	int input = atoi(argv[1]);
	//result vector
	int result[1024];
	//result_index
	int result_index=0;
	
	//intializing the result vector
	for(int i=0;i<1024;i++)
	{
		result[i] = -1;
	}

	int index;
	while(1){
		//end case
		if(input == 1){
			index = 1;
			result[result_index] = index;
			break;
		}
		else if(input == 0 ){
			index = 0;
			result[result_index] = index;
			break;
		}

		//update index,input,result vector
		index = input % 2;
		result[result_index] = index;
		input = input/2;
		result_index ++;
	}

	//print in reverse order
	for(int i=1023;i>=0;i--){
		if(result[i] != -1 )
			printf("%d",result[i]);
	}
	printf("\n");

}
