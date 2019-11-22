#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#define	MAX_PATH	256

void JustDoIt(char *path)
{
	//directory pointer
	DIR				*dp;
	//directory entry pointer
	struct dirent	*dep;
	//file stat struct
	struct stat		statbuf;
	//variable to store full path of file
	char			fullpath[MAX_PATH];

	//open directory
	if ((dp = opendir(path)) == NULL)  {
		perror("opendir");
		exit(0);
	}

	//print path
	printf("\n%s:\n", path);
	//read directory
	while (dep = readdir(dp))  {
		//current directory and parent directory exception
		if (strcmp(".", dep->d_name) == 0 || strcmp("..", dep->d_name) == 0)
			continue;
		//print director name
		printf("%s\n", dep->d_name);
	}
	
	//reset directory pointer offset 
	rewinddir(dp);
	//read directory
	while (dep = readdir(dp))  {
		//current directory and parent directory exception
		if (strcmp(".", dep->d_name) == 0 || strcmp("..", dep->d_name) == 0)
			continue;
		//create full path of file.
		strcpy(fullpath, path);
		strcat(fullpath, "/");
		strcat(fullpath, dep->d_name);
		
		if (lstat(fullpath, &statbuf) < 0)  {
			perror("lstat");
			exit(1);
		}
		//if it's diretory, reculsive call
		if (S_ISDIR(statbuf.st_mode))  {
			JustDoIt(fullpath);
		}
	}
	//close directory
	closedir(dp);
}

int main()
{
	//call reculsive ls function
	JustDoIt(".");
	return 0;
}
