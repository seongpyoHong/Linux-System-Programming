#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
	if(argc<3)
		perror("There ins't enough argument");

	FILE* read_stream;
	FILE* write_stream;
	char* origin_file = argv[1];
	char* copy_file = argv[2];

	read_stream = fopen(origin_file,"rb");
	if(read_stream==NULL)
		perror("read file open error");
	write_stream = fopen(copy_file,"wb");
	if(write_stream==NULL)
		perror("write file open error");
	
	char buffer[128];
	int num_r;
	int num_w;
	while(!feof(read_stream)){
		num_r = fread(buffer,sizeof(buffer),1,read_stream);
		num_w= fwrite(buffer,sizeof(buffer),1,write_stream);
	}

	close(read_stream);
	close(write_stream);
}
