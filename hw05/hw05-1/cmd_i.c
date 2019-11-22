#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define	MAX_CMD		256

//Function to print "Doing" & "Done"
void DoCmd(char *cmd)
{
	printf("Doing %s", cmd);
	sleep(1);
	printf("Done\n");
}

int main()
{
	//variable to store user input string
	char	cmd[MAX_CMD];

	//loop until user input's first charater is 'q'.
	while (1)  {
		printf("CMD> ");
		//store the content of STDIN buffer to cmd array. 
		fgets(cmd, MAX_CMD, stdin);	
		//break condition
		if (cmd[0] == 'q')
			break;
		//execute DoCmd Function
		DoCmd(cmd);
	}
}
