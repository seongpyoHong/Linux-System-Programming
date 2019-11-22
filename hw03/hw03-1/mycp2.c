#include <stdio.h>
#include <stdlib.h>
#define	MAX_BUF	1024

int main(int argc, char *argv[])
{
	//declare source/destination file pointer.
	FILE	*src, *dst;
	//declare buf to store
	char	buf[MAX_BUF];
	//count to read
	int		count;

	//check arguments
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	//source file open with read/binary mode
	if ((src = fopen(argv[1], "rb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//destination file open with write/binary mode
	if ((dst = fopen(argv[2], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	while (fread(&count,sizeof(count),1,src)!=0)  {
		fwrite(buf, 1, count, dst);
	}

	fclose(src);
	fclose(dst);
}
