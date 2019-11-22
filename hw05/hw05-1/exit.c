#include <stdio.h>
#include <stdlib.h>

//exit handler  1
void myexit1()
{
		printf("first exit handler\n");
}

//exit handler 2
void myexit2()
{
		printf("second exit handler\n");
}

int main()
{
/*
 exit handler which is called at final executes first.
 */
	if (atexit(myexit2) != 0)  {
		perror("atexit");
		exit(1);
	}

	if (atexit(myexit1) != 0)  {
		perror("atexit");
		exit(1);
	}

	if (atexit(myexit1) != 0)  {
		perror("atexit");
		exit(1);
	}

	printf("main is done\n");

	return 0;
}
