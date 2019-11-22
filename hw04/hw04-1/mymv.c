#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	//check arguments
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s old new\n", argv[0]);
		exit(1);
	}

	//rename argv[1] to argv[2]
	if (rename(argv[1],argv[2])<0)  {
		perror("rename");
		exit(1);
	}
	return 0;
}
