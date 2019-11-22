#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char* argv[]){

	DIR *dp;
	struct dirent *dep;
	struct stat mystat;
	if(argc !=2){
		printf("Wrong Number of Argument.");
		exit(1);
	}
	int size = atoi(argv[1]);	
	if((dp = opendir("."))==NULL){
		perror("opendir");
		exit(0);
	}
	while (dep = readdir(dp)){
		char* name = dep->d_name;
		if(lstat(name,&mystat)<0){
			perror("lstat");
			exit(1);
		}
		off_t file_size = mystat.st_size;
		if(file_size >= size && !S_ISDIR(mystat.st_mode)){
			printf("%s\n",name);
		}
	}
	return 0;
}
