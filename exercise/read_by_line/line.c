#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	if(argc<3)
		perror("There is no enough argument");	
	
	off_t bytes = atoi(argv[1]);
	char str[255];
	FILE *stream;
	char* filename = argv[2];
	char* output;
	stream = fopen(filename,"r");
	if(!stream)
		perror("fopen error");
	while( !feof(stream ) )
	{
		output = fgets( str, sizeof(str), stream );
		printf( "%s", output );
	}
	fclose(stream );
	
}
