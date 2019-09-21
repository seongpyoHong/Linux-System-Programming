#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
	if(argc<3)
		perror("There isn't enough argument");

	FILE* read_stream;
	FILE* write_stream;
	char* origin_file = argv[1];
	char* copy_file = argv[2];
	int byte;
	int ret;

	read_stream = fopen(origin_file,"r");
	write_stream = fopen(copy_file,"w");
	while(!feof(read_stream)){
		byte = fgetc(read_stream);
		ret = fputc(byte,write_stream);
	}
	
	close(read_stream);
	close(write_stream);
	return 0;
}
