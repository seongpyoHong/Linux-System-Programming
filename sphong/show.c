#include <stdio.h>

int main(){
	int max = 9;
	while(max >=1 ){
		for(int i=0;i<=max;i++){
			printf("%d ",i);
		}
		printf("\n");
		max -= 1;
	}
}
