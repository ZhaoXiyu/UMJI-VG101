#include <stdlib.h>
#include <stdio.h>
void mempeek(void *p,int size){
	printf("\nDEBUG INVOKE_MEMPEEK");	
	unsigned char* pp=(unsigned char*)p;
	int i;
	for(i=0;i<size;i++){
		if((i%8)==0)printf("\n0x%p:\t",p+i);
		if((i%8)==4)printf("\b\b\b\b|   ");
		printf("%X\t ",pp[i]);
	}
	printf("\n");
	return;
}

void showintarray(void *p,int size){
	printf("\nDEBUG INVOKE_MEMPEEK");	
	unsigned int* pp=(unsigned int*)p;
	int i;
	for(i=0;i<size;i++){
		if((i%4)==0)printf("\n0x%p:\t",p+i*4);
		if((i%1)==4)printf("\b\b\b\b|   ");
		printf("%d\t ",pp[i]);
	}
	printf("\n");
	return;
}

void printint(int int_show){
	printf("\nDEBUG SHOWINT: %d\n",int_show);
}

void PS(){
	system("PAUSE");
}