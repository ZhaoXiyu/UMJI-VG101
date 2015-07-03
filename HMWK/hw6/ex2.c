#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	int data[]={1,234,544,899,34,89,743,165,123,147,260,700};
	int max=0;int* ptr=0;
	for(ptr=data;(ptr-data)<(sizeof(data)/sizeof(int));ptr++)
		if(*ptr>max)max=*ptr;
	srand(time(NULL));
	int r=rand()%max;
	printf("r=%d: ",r);
	for(ptr=data;(ptr-data)<(sizeof(data)/sizeof(int));ptr++)
		if(*ptr>r)printf("%d ",*ptr);
	return 0;
}
