#include <stdio.h>
#include <stdlib.h>
/*Make a text-copy program using character-at-a-time I/O stream*/
int main(int argc, char *argv[])
{
	//declare source/destination file pointer
	FILE	*src, *dst;
	//declare variable to store a chracter.
	int		ch;

	//argument check
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	//source file open (read/text mode)
	if ((src = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//destination file open (write/text mode)
	if ((dst = fopen(argv[2], "wt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//read character-at-a-time I/O stream
	while ((ch = fgetc(src)) != EOF)  {
		fputc(ch, dst);
	}

	fclose(src);
	fclose(dst);
}
