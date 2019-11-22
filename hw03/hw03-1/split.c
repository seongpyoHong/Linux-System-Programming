#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define	MAX_BUF	1024

//return file size
long filesize(FILE *fp)
{
	long	cur, size;
	//current file offset
	cur = ftell(fp);
	//set the file offset to end of file.
	fseek(fp, 0L, SEEK_END);
	//allocate the size of fp.
	size = ftell(fp);
	//reset the file offset current offset
	fseek(fp, cur, SEEK_SET);
	//return size of file.
	return(size);
}

int main(int argc, char *argv[])
{
	//declare source/destination1,2 file pointer.
	FILE	*src, *dst1, *dst2;
	//declare buf to store content which is read.
	char	buf[MAX_BUF];
	//declare count and size variable.
	int		count, size;
	
	//check arguments
	if (argc != 4)  {
		fprintf(stderr, "Usage: %s source dest1 dest2\n", argv[0]);
		exit(1);
	}
	//open the source file with read/binary mode.
	if ((src = fopen(argv[1], "rb")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	//open destination 1 file with write/binary mode.
	if ((dst1 = fopen(argv[2], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//open destination 2 file with write/binary mode.
	if ((dst2 = fopen(argv[3], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//To split two files, each size of destination file is half of origin's size.
	size = filesize(src) / 2;

	//loop until size is same or smaller than 0.
	while (size > 0)  {
		//if size>MAX_BUF, count is MAXBUF. Else, count is size.
		count = (size > MAX_BUF) ?  MAX_BUF : size;
		//size is 1 bytes, number of object is count
		fread(buf, 1, count, src); 
		//write the content which read to src.
		fwrite(buf,1,count,dst1);
		size -= count;
	}
	//At this time, file offset points the half of file size.
	
	//rest part of file.
	while ((count = fread(buf, 1, MAX_BUF, src)) > 0)  {
		//until file offset points the end of file, wrtie to destination 2 file.
		fwrite(buf,1,count,dst2);
	}

	//all file pointer close.
	fclose(src);
	fclose(dst1);
	fclose(dst2);
}
