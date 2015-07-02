#include "set.h"
#define MCHNK 64
#define byte unsigned char
#define CARD (set->card)
#define ELEM (unsigned char*)(set->elem)
#define TYPE (set->type)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* umalloc(size_t);
void* urealloc(void*,size_t);
int bcmp(unsigned char*,unsigned char*,size_t);
void resizeSet(uset*,int);

int main(){
	uset intset;
	newSet(&intset,CHAR);
	int i;
	for(i=0;i<2000;i++){
		//printf("%d %d \n",i,intset.card);
		addElem(&i,&intset);
	}
	for(i=2500;i>1500;i--){
		//printf("%d %d \n",i,intset.card);
		remElem(&i,&intset);
	}
	deletSet(&intset);
	return 0;
}

void addElem(void *elem, uset *set){
	byte* i;
	int currsize=CARD*TYPE;
	for(i=ELEM;(i-ELEM)<currsize;i+=TYPE)
		if(bcmp(elem,i,TYPE))return;//Same element already exist
	printf("Adding:%d %d\n",*(int*)elem,CARD);
	resizeSet(set,currsize+TYPE);//resize the set to hold another elem
	memcpy(ELEM+currsize,elem,TYPE);//add to the set.
		//source,start byte+size,length
	CARD++;//inc card by 1
	return;
}

void remElem(void *elem, uset *set){
	byte* i;
	printf("Removing:%d\n",*(int*)elem);
	int currsize=CARD*TYPE;
	for(i=ELEM;(i-ELEM)<currsize;i+=TYPE)
		if(bcmp(elem,i,TYPE)){
			memmove(i,i+TYPE,currsize-(i-ELEM)-TYPE+1);
			//Push all memory forward type bytes
			resizeSet(set,currsize-TYPE);//Resize to 1 elem less
			CARD--;//dec 1.
			return;//finished processing
		}
	return; //Not found,nothing to do.
}

void newSet(uset *set,int type){
	set->type=type;
	set->card=0;
	set->elem=umalloc(INITSETSIZE*type);
	return;
}

void deletSet(uset *set){
	set->type=0;
	set->card=0;
	free(set->elem);
	return;
}

void* umalloc(size_t size){
	void* ptr=malloc(size);
	if(ptr==NULL){
		fprintf(stderr,"ERROR: Calloc Failed\n");
		exit(1);
	}
	return ptr;
}

void* urealloc(void* ptr,size_t size){
	ptr=realloc(ptr,size);
	if(ptr==NULL){
		fprintf(stderr,"ERROR: Realloc Failed\n");
		system("PAUSE");
		exit(1);
	}
	return ptr;
}

int bcmp(unsigned char* ptr1,unsigned char* ptr2,size_t size){
	while(size>0){
		size--;//start from the last byte
		if(ptr1[size]!=ptr2[size])return 0;//some different;
	}
	return 1;
}

void resizeSet(uset* set,int newsize){
	int oldsize=set->card*set->type;//calculate old used mem
	int t=oldsize%(MCHNK*set->type);//calculate the used mem in the last chunk
	oldsize=oldsize-t+MCHNK*set->type;
	//calculate the mem allocated by calculating (orignal size-t+chunksize)
	t=newsize%(MCHNK*set->type);
	newsize=newsize-t+MCHNK*set->type;
	//calculate the new memory required to be allocated;
	if(oldsize!=newsize){//if newsize is not equal to old size.
		set->elem=urealloc(set->elem,newsize);//resize memory!
		printf("Resizing from %d to %d.\n",oldsize,newsize);
	}
	return;
}