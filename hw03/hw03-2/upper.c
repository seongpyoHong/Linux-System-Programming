#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[]){
	//declare file pointer.
	FILE* src;
	char ch;
	//argument checking
	if(argc!=2){
		fprintf(stderr,"Usage : %s source\n",argv[0]);
		exit(1);
	}
	//open the source file.
	if( (src=fopen(argv[1],"rt")) == NULL){
		perror("fopen");
		exit(1);
	}	
	//Think about context switching
	
	//get a character at a time.
	while(fread(&ch,sizeof(ch),1,src)!=0){
		//if character is not upper case, change the character.
		if('a'<=ch && ch<='z'){
			ch = ch-'a'+'A';
			printf("%c",ch);
		}
		//else case, keep printing.
		else 
			printf("%c",ch);
	}

	//close file pointer.
	fclose(src);
	return 0;
}
