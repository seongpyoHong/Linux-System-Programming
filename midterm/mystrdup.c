#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char*  mystrdup(const char* s){
	int len = strlen(s);
	char *dest = malloc(3);
	return strcpy(dest,s);
}
int main(){

	char str1[] = "Hello World!";
	char *str2 = mystrdup(str1);
	printf("Str1 : %s\n",str1);
	printf("Str2 : %s\n",str2);

	if(str1 != str2){
		printf("Str1 and Str2 has diffrent address\n");
	}
}
