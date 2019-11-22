#include <stdio.h>
#include <stdlib.h>

int main()
{
	//variable to store status
	int		status;

	//execute "date" command
	if ((status = system("date")) < 0)  {
		perror("system");
		exit(1);
	}
	//exit check
	printf("exit status = %d\n", status);

	//execute "nosuchcommand"
	if ((status = system("nosuchcommand")) < 0)  {
		perror("system");
		exit(1);
	}
	//exit check
	printf("exit status = %d\n", status);

	// execute "$ who; exit 44" command 
	if ((status = system("who; exit 44"))<0)  {
		perror("system");
		exit(1);
	}
	//exit check
	printf("exit status = %d\n", status);
return 0;
}

