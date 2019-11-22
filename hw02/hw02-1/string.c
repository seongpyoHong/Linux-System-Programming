#include <stdio.h>

//return the input's length using pointer.
int strlen_p(char* str){
	int len =0;
	//string's final points the NULL. 
	//So, use str++ for calculating length except NULL(final pointer).
	while(*(str++))
		len++;

return len;
}

//return the input's length using array
int strlen_a(char* str){
	int i;

	for (i = 0 ; str[i] != '\0' ; i++)
				;
return i;
}

//copy the src string to destination string using pointer.
void strcpy_p(char *dst,char *src){
	//loop until *src isn't NULL.
	while(*src){
		//*src assign in *dst.
		*dst++ = *src++;
	}
	*dst = *src;
}

//copy the src string to destination string using array.
void strcpy_a(char dst[],char src[]){
	int i;
	//loop until src[i] isn't NULL.
	for(i=0; src[i]!='\0';i++){
		dst[i]=src[i];
	}
	dst[i]= src[i];
}

//merge two input parameter using pointer.
void strcat_p(char* dst, char* src){
	//first increase *dst.
	while (*dst++);
	//At this time, *dst is NULL. So, we need to decrease the *dst.
	*dst--;
	while (*src){
		*dst++ = *src++;
	}
	*dst = *src;
}

//merge two input parameter using array.
void strcat_a(char dst[], char src[]){
	int i,j;
	for (i=0;dst[i]!='\0' ; i++)
		;
	for (j=0;src[j]!='\0';j++){
		dst[i+j] = src[j];
	}
	dst[i+j] = src[j];
}

int main(){
	//length variables
	int		len1, len2;
	//character arrays.
	char	str1[20], str2[20];

	//caculate the string's length.
	len1 = strlen_p("Hello");
	//caculate the string's length.
	len2 = strlen_a("Hello");
	printf("strlen: p=%d, a=%d\n", len1, len2);

	//copy Hello in str1,str2.
	strcpy_p(str1, "Hello");
	strcpy_a(str2, "Hello");
	printf("strcpy: p=%s, a=%s\n", str1, str2);

	//merge two string str1(str2) with , World!
	strcat_p(str1, ", World!");
	strcat_a(str2, ", World!");
	printf("strcat: p=%s, a=%s\n", str1, str2);
	
return 1;
}

