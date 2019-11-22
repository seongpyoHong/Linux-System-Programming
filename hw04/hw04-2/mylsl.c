#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

//convert mode_t to string
char* convertPermission(mode_t perm){
	char *modeval = malloc(sizeof(char) * 9 + 1);
		modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
		modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
		modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
		modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
		modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
		modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
		modeval[6] = (perm & S_IROTH) ? 'r' : '-';
		modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
		modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
		modeval[9] = '\0';
		return modeval;     
}

//convert uid to string
char* convertUId(uid_t uid){
	
	struct passwd *pwd;	
	pwd = getpwuid(uid);
	return pwd->pw_name;
}

//convert gid to string
char* convertGId(gid_t gid){
	struct group *g;
	g = getgrgid(gid);
	return g->gr_name;
}

//main function
int main(){

	DIR  *dp; 	//Directory Pointer
	struct dirent *dep;	//Directory Entry
	struct stat mystat;	//Struct to store file stat.

	//Directory open
	if ((dp = opendir(".")) == NULL)  {
		perror("opendir");
		exit(0);
	}

	//read contents of directory
	while (dep = readdir(dp))  {
		char* file_name = dep->d_name;	//file name
		if (lstat(file_name, &mystat)<0)		//load file stat
		{
			perror("lstat");
			exit(1);
		}
		
		off_t file_size = mystat.st_size;	//file size
		
		uid_t uId = mystat.st_uid;		//file user id
		char* uname = convertUId(uId);	//file user name

		gid_t gId = mystat.st_gid;		//file group id
		char* gname = convertGId(gId);	//file gruop name

		nlink_t linkNum = mystat.st_nlink;	//Number of hard links.
		
		time_t m_time = mystat.st_mtime;	//Last modified time
		struct tm *	timeinfo = localtime (&m_time);	//struct to store localtime for m_time 
		char strtime[20]; 							//string of time
		strftime(strtime, 20, "%b %d %H:%M", timeinfo); //convert time to string 
		
		mode_t permission = mystat.st_mode; //Permission of File
		char* strperm = convertPermission(permission);	//string of permission

		char Isdir;							//Check which it is directory or file.
		if(S_ISDIR(permission))
			Isdir = 'd';
		else 
			Isdir = '-';
	
		//print
		printf("%c%s %ld %s %s %6ld %12s %s\n", Isdir,strperm,linkNum,uname,gname,file_size,strtime,file_name);
	}
	return 0;
}


