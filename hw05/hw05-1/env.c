#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[], char *envp[])
{
	//variable to access the argc
	int			i;
	//pointer to access the environment pointer
	char		**p;
	//enviroment pointer
	extern char	**environ;

	//print the command-line arguments
	printf("List command-line arguments\n");

	//print to argument
	for (i = 0 ; i < argc ; i++)  {
		printf("%s\n", argv[i]);
	}

	printf("\n");
	printf("List environment variables from environ variable\n");
#if 1
	//print enviroment variable from environment pointer.
	for (i = 0 ; environ[i] != NULL ; i++)  {
		printf("%s\n", environ[i]);
	}
#else
	for (p = environ ; *p != NULL ; p++)  {
		printf("%s\n", *p);
	}
#endif

	printf("\n");
	printf("List environment variables from envp variable\n");
#if 1
	//print enviroment variable from arguments.
	for (i = 0 ; envp[i] != NULL ; i++)  {
		printf("%s\n", envp[i]);
	}
#else
	for (p = envp ; *p != NULL ; p++)  {
		printf("%s\n", *p);
	}
#endif
}
