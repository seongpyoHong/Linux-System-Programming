#include <stdio.h>

main(){
	//variable type.
	char c = 'a', s[] = "hello";
	int i = 100; long l =99999;
	float f = 3.14; double d = 99.999;
	int *p = &i;
	
	//c : character, s: string, d: integer
	//#X : 16진수, %ld : long integer, %f : float or double
	//p : pointer
	printf("Output: %c %s %d %#X %ld %.4f %.21f %p\n", c,s,i,i,l,f,d,p);
	//output : a character
	putchar(c);
	//output : character array (strting)
	puts(s);
}
