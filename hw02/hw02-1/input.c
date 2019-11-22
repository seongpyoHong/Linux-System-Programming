#include <stdio.h>

main(){
	char c , s[80];
	int i; long l;
	float f; double d;
	//array is already pointer. So, there is no '&' in s.
	scanf("%c %s %d %ld %f %lf", &c,s,&i,&l,&f,&d);
	printf("Output: %c %s %d %ld %.f %.21lf\n ",c,s,i,l,f,d);

	//input : a character
	c= getchar();
	putchar(c);

	//input : string
	gets(s);
	puts(s);
}
