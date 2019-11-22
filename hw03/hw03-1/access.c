#include <stdio.h>
#include <unistd.h>
#include "record.h"
#include <stdlib.h>
#include <string.h>

//print record function
void print_record(Record *rp)
{
	//write rp's content in stdout.
	puts(rp->stud);
	puts(rp->num);
	puts(rp->dept);
}

int main(int argc, char *argv[])
{
	//declare file pointer
	FILE	*fp;
	//declare Record type instance.
	Record	rec;

	//argument check
	if (argc != 2)  {
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(1);
	}

	//file open with read/binary mode
	if ((fp = fopen(argv[1], "r+b")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	printf("-----Ordered Record List-----\n");
	
	//read each record.
	while (fread(&rec,sizeof(rec),1,fp))  {
		print_record(&rec);
		printf("check");
	}
	//reset file offset 
	rewind(fp);
	//read a characterin stdin.
	getchar();

	printf("-----Shuffled Record List (3, 6, 2, 4, 1, 5)-----\n");

	/*
	   1. set the file offset which need to access into offset-1.
	   2. read content as record's size.
	*/
	fseek(fp, sizeof(rec)*2L, SEEK_SET);
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);

	fseek(fp, sizeof(rec)*5L, SEEK_SET);
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);

	fseek(fp, sizeof(rec)*1L, SEEK_SET);
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);

	fseek(fp,sizeof(rec)*3L,SEEK_SET);
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);

	fseek(fp, sizeof(rec)*0L, SEEK_SET);
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);

	fseek(fp, sizeof(rec)*4L, SEEK_SET);
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);
	//stdin -> return
	getchar();

	printf("-----Updated Record List-----\n");

	/*
	   1. access offset - 1
	   2. change the content.
	   3. reset the offset to offset -1
	   4. read the content wich is changed.
	 */
	fseek(fp, sizeof(rec)*2L, SEEK_SET);
	fread(&rec, sizeof(rec), 1, fp);
	strcpy(rec.dept, "Movie");
	fseek(fp,sizeof(rec)*2L,SEEK_SET);
	fwrite(&rec, sizeof(rec), 1, fp);

	fseek(fp, sizeof(rec)*5L, SEEK_SET);
	fread(&rec, sizeof(rec), 1, fp);
	strcpy(rec.dept, "Baseball");
	fseek(fp, sizeof(rec)*5L, SEEK_SET);
	fwrite(&rec, sizeof(rec), 1, fp);

	//set file offset to 0. 
	rewind(fp);
	//read the file from start offset.
	while (fread(&rec, sizeof(rec), 1, fp))  {
		print_record(&rec);
	}

	//close the file pointer.
	fclose(fp);

	return 0;
}
