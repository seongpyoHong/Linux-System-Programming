#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	//file stat struct
	struct stat	statbuf;
	//variable to store file's mode
	char		*mode;
	int			i;
	
	//load stat of all arguments.
	for (i = 1 ; i < argc ; i++)  {
		printf("%s: ", argv[i]);
		if (lstat(argv[i],&statbuf)!=0)  {
			perror("lstat");
			continue;
		}
		//check is it regular file
		if (S_ISREG(statbuf.st_mode))
			mode = "regular";
		//check is it directory
		else if (S_ISDIR(statbuf.st_mode))
			mode = "directory";
		//check is it character special file
		else if (S_ISCHR(statbuf.st_mode))
			mode = "character special";
		//check is it block special file
		else if (S_ISBLK(statbuf.st_mode))
			mode = "block special";
		//check is it FIFO
		else if (S_ISFIFO(statbuf.st_mode))
			mode = "FIFO";
		//check is it symbolic link
		else if (S_ISLNK(statbuf.st_mode))
			mode = "symbolic link";
		//chekc is it socket
		else if (S_ISSOCK(statbuf.st_mode))
			mode = "socket";
		//print file's type
		printf("%s\n", mode);
		//print file's stat
		printf("\tst_mode = %d\n", statbuf.st_mode);
		printf("\tst_ino = %ld\n", statbuf.st_ino);
		printf("\tst_dev = %ld\n", statbuf.st_dev);
		printf("\tst_rdev = %ld\n", statbuf.st_rdev);
		printf("\tst_nlink = %ld\n", statbuf.st_nlink);
		printf("\tst_uid = %d\n", statbuf.st_uid);
		printf("\tst_gid = %d\n", statbuf.st_gid);
		printf("\tst_size = %ld\n", statbuf.st_size);
		printf("\tst_atime = %ld\n", statbuf.st_atime);
		printf("\tst_mtime = %ld\n", statbuf.st_mtime);
		printf("\tst_ctime = %ld\n", statbuf.st_ctime);
		printf("\tst_blksize = %ld\n", statbuf.st_blksize);
		printf("\tst_blocks = %ld\n", statbuf.st_blocks);
	}
	return 0;
}
