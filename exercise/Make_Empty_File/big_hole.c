#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
	
	//argument number check
	if(argc<3){
		perror("There is no enough argument.");
	}
	//file's name to make
	char* filename = argv[1];
	//file's bytes
	off_t bytes = atoi(argv[2]);
	//file descriptor
	int fd;
	
	//create file
	fd = creat(filename, 0644);
	if(fd == -1){
		perror("creat");
		return 0;
	}

	//Move offset
	off_t ret;
	ret = lseek(fd,(off_t)bytes-1,SEEK_END);
	if(ret == (off_t) -1)
		perror("lseek error");
	
	//write file
	if(write(fd," ",1)==-1){
		perror("write");
	}
	
	close(fd);

}

