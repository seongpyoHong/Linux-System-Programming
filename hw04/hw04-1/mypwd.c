#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define	MAX_BUF	256

int main(int argc, char *argv[])
{
	//variable to store current directory
	char	buf[MAX_BUF];
	//get current working directory
	if (getcwd(buf,MAX_BUF) == NULL)  {
		perror("getcwd");
		exit(1);
	}

	printf("%s\n", buf);
return 0;
}
