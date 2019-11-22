#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()  {
	//declare file descriptor
	int fd[2];
	//id of child process 
	pid_t child;

	//create pipe
	if(pipe(fd)<0)  {
		perror("pipe");
		exit(1);
	}

	//fork child process
	child = fork();
	
	//fork error check
	if(child == (pid_t)(-1))  {
		perror("fork");
		exit(1);
	}
	
	//case when process is child
	else if(child == (pid_t)0) {
		//close STDOUT
		close(1);
		//close read file descriptor
		close(fd[0]);

		//duplicate write file descriptor with STDOUT(1)
		if(dup(fd[1])<0)  {
			perror("dup");
			exit(1);
		}
		//exec "ls -l"
		if((execlp("ls", "ls", "-l", NULL)) == -1)  {
			perror("execlp");
			exit(1);
		}
	} 
	
	//case when process is parent
	else {
		//close STDIN
		close(0);
		//close write file descriptor
		close(fd[1]);
		//duplicate STDIN with read file descriptor
		if(dup(fd[0])<0)  {
			perror("dup");
			exit(1);
		}
		//exec "more"
		if((execlp("more", "more", NULL)) == -1)  {
			perror("execlp");
			exit(1);
		}
	}

	return 0;
}
