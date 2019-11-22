#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	//check arguments
	if (argc != 2)  {
		fprintf(stderr, "Usage: %s dirname\n", argv[0]);
		exit(1);
	}

	// make directory with 755 permission
	if (mkdir(argv[1],0755))  {
		perror("mkdir");
		exit(1);
	}
return 0;
}
