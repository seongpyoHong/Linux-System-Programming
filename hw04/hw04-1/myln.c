//update the link file
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	//check arguments
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destinaion\n", argv[0]);
		exit(1);
	}

	//create hard link. (source : argv[1], link : argv[2])
	if (link(argv[1],argv[2]) < 0)  {
		perror("link");
		exit(1);
	}
	return 0;
}
