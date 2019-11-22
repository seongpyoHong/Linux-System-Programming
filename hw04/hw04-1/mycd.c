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

	//change directory to argv[1]
	if (chdir(argv[1])<0)  {
		perror("chdir");
		exit(1);
	}
	return 0;
}
