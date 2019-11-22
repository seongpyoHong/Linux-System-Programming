#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum { FALSE, TRUE };

void conv(char *fname)
{
	//delcare file pointer
	FILE	*src, *dst;
	//delcare char* variable to store content.
	char	fdest[40];
	//decalre int variable to store return ch / first.
	int		ch, first;

	//open source file
	if ((src = fopen(fname, "rt")) == NULL)  {
		perror("fopen");
		return;
	}

	//copy file name to fdest.
	strcpy(fdest, fname);
	//merge fdest with ".t"
	strcat(fdest, ".t");
	//open destination file with write/text mode.
	if ((dst = fopen(fdest, "wt")) == NULL)  {
		perror("fopen");
		return;
	}

	first = TRUE;
	//read a character at a time in source file.
	while ((ch = fgetc(src)) != EOF)  {
		//if first is true and charater is \t, write the 4 blanks.
		if (first && ch == '\t')  {
			fputc(' ', dst);
			fputc(' ', dst);
			fputc(' ', dst);
			fputc(' ', dst);
		}
		//else case
		else  {
			//write charater to destination file.
			fputc(ch, dst);
			//if passing the first, it's not first until meet the '\n'.
			if (first)
				first = FALSE;
			//reset the first checking variable 
			if (ch == '\n')
				first = TRUE;
		}
	}

	fclose(src);
	fclose(dst);
}

int main(int argc, char *argv[])
{
	while (--argc)  {
		conv(argv[argc]);
	}
	return 0;
}
