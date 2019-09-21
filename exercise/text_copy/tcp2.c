#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	
	if(argc<3)
		perror("There isn't enough argument.");

	FILE* read_stream;
	FILE* write_stream;
	char* origin_file= argv[1];
	char* copy_file = argv[2];

	read_stream = fopen(origin_file,"r");
	if(read_stream)
	write_stream = fopen(copy_file,"w");

	char* ch;
	char str[255];
	int ret;
	while(!feof(read_stream)){
		ch = fgets(str,sizeof(str),read_stream);
		ret = fputs(ch,write_stream);
	}

	close(read_stream);
	close(write_stream);
}
