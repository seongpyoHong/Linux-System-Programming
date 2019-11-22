#include <string.h>
#include <unistd.h>
#include <stdio.h>
#define MAXSIZE 1024
void strupper(char str[]){
	for(int i=0;str[i]!='\0';i++){
		if('a'<=str[i] && str[i]<='z')
			str[i] = str[i] - 'a' + 'A'; 
	}
}
int main (){
	char  input[13] = "Hello, World!";
	strupper(input);
	printf("output : %s\n", input);
	return 0;
}
