#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"

int main(int argc, char *argv[])
{
	//declare source/destination file pointer.
	FILE	*src, *dst;
	//declare record type instance
	Record	rec;

	//check arguments
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source dest\n", argv[0]);
		exit(1);
	}

	//source file open with read/text mode.
	if ((src = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	//destination file open with write binary mode.
	if ((dst = fopen(argv[2], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	
	//get Student name 
	while (fgets(rec.stud, SMAX, src))  {
		//delete \n
		*strchr(rec.stud, '\n') = '\0';
		//get student number
		fgets(rec.num, NMAX, src);
		//delete \n
		*strchr(rec.num, '\n') = '\0';
		//get dept 
		fgets(rec.dept, DMAX, src);
		//delete \n
		*strchr(rec.dept, '\n') = '\0';
		/* fwrite */
		fwrite(&rec,sizeof(rec),1,dst);
	}
	
	//close file pointers.
	fclose(src);
	fclose(dst);
}
