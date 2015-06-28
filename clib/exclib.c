#include <stdlib.h>
#include <stdio.h>
void mempeek(void*,int);
void* printint(int);
void PS();

void* ucalloc(size_t,size_t);
void* umalloc(size_t);

FILE* ufopen(const char*,const char*);
int getFileLen(FILE*);

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

void* ucalloc(size_t blocks,size_t size){
	void* ptr=calloc(blocks,size);
	if(ptr==NULL){
		fprintf(stderr,"ERROR: Calloc Failed\n");
		exit(1);
	}
	return ptr;
}

void* umalloc(size_t size){
	void* ptr=malloc(size);
	if(ptr==NULL){
		fprintf(stderr,"ERROR: Calloc Failed\n");
		exit(1);
	}
	return ptr;
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

FILE* ufopen(const char* fname,const char* mode){
	FILE* file=fopen(fname,mode);
	if(file==NULL){
		printf("ERROR:fopen on \"%s\" failed.",fname);
		exit(2);
	}
	return file;
}

int getFileLen(FILE* fptr){
	int curr=ftell(fptr);
	fseek(fptr,0,SEEK_END);
	int len=ftell(fptr);
	fseek(fptr,curr,SEEK_SET);
	return len;
}