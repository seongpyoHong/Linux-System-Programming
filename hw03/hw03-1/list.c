#include <stdio.h>

#define	MAX_BUF	256

main(int argc, char *argv[])
{
	//declare file pointer and buffer and line buffer to print.
	FILE	*fp;
	char	buf[MAX_BUF];
	int		line;

	//argument check 
	if (argc != 2)  {
		printf("Usage: %s filename\n", argv[0]);
		exit(1);
	}

	//file open to read/text mode and error checking
	if ((fp = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//number to read
	line = 1;
	//loop until fgets returns NUll
	while (fgets(buf,MAX_BUF,fp))  {
		printf("%4d: %s", line++, buf);
	}
	//file pointer close
	fclose(fp);
}
