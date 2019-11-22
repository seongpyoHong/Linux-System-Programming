#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	//check arguments
	if (argc != 2)  {
		fprintf(stderr, "Usage: %s dirname\n", argv[0]);
		exit(1);
	}

	//remove directory 
	if (rmdir(argv[1]))  {
		perror("rmdir");
		exit(1);
	}
	return 0;
}
