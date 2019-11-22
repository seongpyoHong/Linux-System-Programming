#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
int main()
{
	//diretory pointer
	DIR				*dp;
	//diretory entry struct
	struct dirent	*dep;

	//open directory
	if ((dp = opendir(".")) == NULL)  {
		perror("opendir");
		exit(0);
	}

	//read directory
	while ((dep = readdir(dp)) != NULL)  {
		printf("%s\n", dep->d_name);
	}
	//close directory
	closedir(dp);
	return 0;
}
