#include <stdio.h>
#include <stdlib.h>
#define	MAX_BUF	256

int main(int argc, char *argv[])
{
	//declare source/destination file pointer
	FILE	*src, *dst;
	//declare buf to store
	char	buf[MAX_BUF];

	//check arguments
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	//open source file
	if ((src = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//open destination file
	if ((dst = fopen(argv[2], "wt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//loop until fgets return NULL
	while (fgets(buf,MAX_BUF,src)!=NULL)  {
		fputs(buf, dst);
	}

	fclose(src);
	fclose(dst);
}
