#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define INFILES "sentence.txt"
#define INFILEW "word.txt"
#define OUTFILE "count.txt"

FILE* ufopen(const char*,const char*);
int getFileLen(FILE*);
void* umalloc(size_t);

int main(){
	FILE* fstc=ufopen("sentence.txt","r");
	FILE* fwd=ufopen("word.txt","r");
	FILE* fout=ufopen("count.txt","w+");
	int lenwd=getFileLen(fwd);
	char* strwd=(char*)umalloc(lenwd+1);
	fgets(strwd,strwd+1,fwd);
	char c;int counter=0;
	char* tempstr=(char*)umalloc(lenwd+1);
	char* curr=tempstr;
	while( (c=fgetc(fstc)) != EOF){
			printf("%c",c);
		if(c==' '||c=='\n'||c=='.'||c=='\r'||c==','){
			curr=tempstr;
		}else{
			*curr++=c;
		}
		if((curr-tempstr)==lenwd){//The length is correct;
		*curr='\0';//form a valid string.
			curr=tempstr;//system("PAUSE");
			if(!strcmp(tempstr,strwd))counter++;
		}
	}
	free(tempstr);
	fprintf(fout,"%d",counter);
	fclose(fstc);fclose(fwd);fclose(fout);
	free(strwd);
	return 0;
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

void* umalloc(size_t size){
	void* ptr=malloc(size);
	if(ptr==NULL){
		fprintf(stderr,"ERROR: Calloc Failed\n");
		exit(1);
	}
	return ptr;
}