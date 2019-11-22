#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//print chracter at a time
void CharAtaTime(char *str)
{
	//for storing the characters
	char	*ptr;
	int		c, i;
	//empty the stdout buffer.
	setbuf(stdout, NULL);
	//for over the process's time quantom, perform the loop 999999 times.
	for (ptr = str ; c = *ptr++ ; )  {
		for(i = 0 ; i < 999999 ; i++)
			;
		//put a character to stdout buffer.
		putc(c, stdout);
	}
}

int main()
{
	pid_t	pid; 		//process Id

	//fork error check
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}

	//when it's a child process
	else if (pid == 0)  {
		CharAtaTime("output from child\n");
	} 

	//when it's a parent process.
	else  {
		CharAtaTime("output from parent\n");
	}
	return 0;
}
