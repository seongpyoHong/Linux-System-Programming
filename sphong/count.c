#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BUF 256
typedef enum{true,false} bool;
int main(int argc, char* argv[]){
	FILE	*fp;
	char	buf[MAX_BUF];
	int 	count = 0;
	int 	ch;
	if((fp = fopen(argv[1],"rt")) == NULL){
		perror("open");
		exit(1);
	}

	bool check = true;
	while((ch = fgetc(fp))!= EOF ){
		if( check==true &&((char)ch == ' ' || (char)ch == '\n'||(char)ch == '\t')){
			count++;
			check = false;
		}
		else if((char)ch != ' ' &&  (char)ch != '\n' &&  (char)ch != '\t')
			check = true;
	}
	printf("%d",count);
	fclose(fp);
}
