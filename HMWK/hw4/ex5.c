#include <stdio.h>
#define SWAP(a,b) ((a^=b),(b^=a),(a^=b))

int main(){
	int a,b;
	printf("Input 2 integers: ");
	scanf("%d %d",&a,&b);
	printf("ORINGINAL:\ta=%d\tb=%d.\n",a,b);
	SWAP(a,b);
	printf("SWAPPED:\ta=%d\tb=%d.\n",a,b);
	return 0;
}