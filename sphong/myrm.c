#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	int 	i;
	if(argc ==1){
		fprintf(stderr,"Need More Arguments");
		exit(1);
	}

	for(i=1;i<argc;i++){
		if(remove(argv[i])<0){
			perror("remove");
			exit(1);
		}
	}
	return 0;
}
