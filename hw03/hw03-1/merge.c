#include <stdio.h>
#include <stdlib.h>
#define	MAX_BUF	1024

int main(int argc, char *argv[])
{
	//declare source 1,2 / destination file.
	FILE	*src1, *src2, *dst;
	//declare buffer to store content which read to src.
	char	buf[MAX_BUF];
	//declare count variable.
	int		count;

	//argument check
	if (argc != 4)  {
		fprintf(stderr, "Usage: %s source1 source2 dest\n", argv[0]);
		exit(1);
	}

	//open souce 1 file with read/ binary mode.
	if ((src1 = fopen(argv[1], "rb")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	//open souce 2 file with read/ binary mode.
	if ((src2 = fopen(argv[2], "rb")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	//open destination file with write/binary mode.
	if ((dst = fopen(argv[3], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	//read at source 1 and write to destination.
	while ((count = fread(buf,1,MAX_BUF,src1))>0)  {
		fwrite(buf, 1, count, dst);
	}

	//continue to reading at source 2
	while ((count = fread(buf,1,MAX_BUF,src2))>0)  {
		fwrite(buf, 1, count, dst);
	}

	//close the file pointers 
	fclose(src1);
	fclose(src2);
	fclose(dst);
}
