#include <stdio.h>

int strlen_p(char* str){
	int len =0;
	while(*(str++))
		len++;

return len;
}

int strlen_a(char* str){
	int i;

	for (i = 0 ; str[i] != '\0' ; i++)
				;
return i;
}

void strcpy_p(char *dst,char *src){
	while(*src){
		*dst++ = *src++;
	}
	*dst = *src;
}

void strcpy_a(char dst[],char src[]){
	int i;
	for(i=0; src[i]!='\0';i++){
		dst[i]=src[i];
	}
	dst[i]= src[i];
}
void strcat_p(char* dst, char* src){
	while (*dst++);
	*dst--;
	while (*src){
		*dst++ = *src++;
	}
	*dst = *src;
}

void strcat_a(char dst[], char src[]){
	int i,j;
	for (i=0;dst[i]!='\0' ; i++)
		;
	for (j=0;src[j]!='\0';j++){
		dst[i+j] = src[j];
	}
	dst[i+j] = src[j];
}

//----------------------------Add Part-------------------------
/*
 [Function Name] : strcmp_p
 [Description] : compare two input string using pointer
 [Input] : 
 		- destination string pointer `char *dst`
 	 	- source string pointer `char *src`
 [Output] : 
 		- two string are same : 0
		- two string are different : -1
 
 */
int strcmp_p(char *dst, char *src){
	//loop until *dst is not null.
	while(*dst){
		//if *dst and *src are different, return -1
		if(*dst!=*src)
			return -1;
		*dst++;
		*src++;
	}		
	//if all characters is same, return 0 
	return 0;
}
/*
[Function Name] : strcmp_p
[Description] : compare two input string using pointer
[Input] : 
		- destination string array dst[]
		- source string array src[]
[Output] : 
		- two string are same : 0
		- two string are different : -1
 */
int strcmp_a(char dst[],char src[]){
	int i;
	//loop until dst[i] is not null
	for (i=0;dst[i]!='\0';i++){
		//if dst[i] and src[i] are different, return -1 
		if(dst[i]!=src[i])
			return -1; 
	}
	//if all characters are same, return 0
	return 0;
}


/*
 [Program Name] : Homework 02
 [Description] : Use the custom string function
 		- Use the customized function which compare two input string.
 */
int main(){
	int		len1, len2;
	char	str1[20], str2[20];

	len1 = strlen_p("Hello");
	len2 = strlen_a("Hello");
	printf("strlen: p=%d, a=%d\n", len1, len2);

	strcpy_p(str1, "Hello");
	strcpy_a(str2, "Hello");
	printf("strcpy: p=%s, a=%s\n", str1, str2);

	strcat_p(str1, ", World!");
	strcat_a(str2, ", World!");
	printf("strcat: p=%s, a=%s\n", str1, str2);
	
	//variable is assigned the result of strcmp_p(str1,"compare") 
	int is_same_p = strcmp_p(str1,"compare");
	//variable is assigned the result of strcmp_a(str1,str2)
	int is_same_a = strcmp_a(str1,str2);
	
	//return value -1 is false / 0 is true
	printf("strcmp_p result : %d (0 is same, -1 is different.)\n",is_same_p);
	printf("strcmp_a result : %d (0 is same, -1 is different.)\n",is_same_a);
	
return 1;
}

