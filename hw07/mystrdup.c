#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char*  mystrdup(const char* s){
	//source length
	int len = strlen(s);
	//dynamic allocation
	char *dest = malloc(len+1);
	//string copy & return destination address
	return strcpy(dest,s);
}
int main(){

	char str1[] = "Hello World!";
	char *str2 = mystrdup(str1);
	puts(str2);

	if(str1 != str2){
		printf("Str1 and Str2 has diffrent address\n");
	}
}
