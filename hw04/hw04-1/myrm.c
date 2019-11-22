#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int		i;
	//check arguments
	if (argc == 1)  {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(1);
	}

	//remove all arguments
	for (i = 1 ; i < argc ; i++)  {
		if (remove(argv[i]) < 0)  {
			perror("remove");
			exit(1);
		}
	}
	return 0;
}
