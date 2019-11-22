#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
//function to print a character at a time.
void CharAtaTime(char *str)
{
	
	char	*ptr;	//store to character
	int		c, i;	//index variable

	//clear stdout buffer 
	setbuf(stdout, NULL);
	//make race condition
	for (ptr = str ; c = *ptr++ ; )  {
		for(i = 0 ; i < 999999 ; i++)
			;
		putc(c, stdout);
	}
}
//while race.c file prints the contents in race condition, it prints without race condition because of wait function. 
int main()
{
	//process id
	pid_t	pid;

	//fork and error check
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	//when it's a child process
	else if (pid == 0)  {
		//child's print funtion
		CharAtaTime("output from child\n");
	} 
	//when it's a parent process
	else  {
		//wait until the child process finish
		wait(NULL);
		//parent's print funtion
		CharAtaTime("output from parent\n");
	}
}
