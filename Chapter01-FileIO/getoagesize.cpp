#include <unistd.h>
#include <stdio.h>
#include <sys/user.h>
using namespace std;
int main(){

	int ps1;
	ps1 = getpagesize();
	printf("page size by method 1 : %d",ps1);

	int ps2;
	ps2 = PAGE_SIZE;
	printf("page size by method 2 : %d",ps2); 
return 0;
}
