#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
int main()
{
	//struct to store file's stat
	struct stat	statbuf;
	
	//load stat for bar
	if (stat("bar", &statbuf) < 0)  {
		perror("stat");
		exit(1);
	}
	/*
	 	change permission
		off : group write
	 */
	if (chmod("bar", (statbuf.st_mode & ~S_IWGRP) | S_ISUID) < 0)  {
		perror("chmod");
		exit(1);
	}

	/* S_IRUSR, S_IWUSR, S_IRGRP, S_IROTH : ON */
	if (chmod("foo",S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH))  {
		perror("chmod");
		exit(1);
	}
}
