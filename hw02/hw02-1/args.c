#include <stdio.h>

//argc : input's count
//argv : input string array
main(int argc, char *argv[]){

	int i;
	for (i=0;i<argc;i++){
		printf("argv[%d] = %s\n",i,argv[i]);
	}
}
