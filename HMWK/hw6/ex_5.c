#include "set.h"
#define MCHNK 64
#define byte unsigned char
#include <stdlib.h>
#include <stdio.h>

void* umalloc(size_t size);
int bcmp(unsigned char*,unsigned char*,size_t);

int main(){
	return 0;
}

void addElem(void *elem, uset *set){
	int i=0;
	for(i=0;i<set->card;i+=set->type)
		if(bcmp((byte*)elem,(byte*)set->elem+i,set->type))return;//Same element already exist
	if(((set->card)%MCHNK)==0)//if the space is critical.
		realloc(set->elem,set->card+MCHNK);//Resize to 64 more.
	memcpy(elem, (byte*)set->elem+(1+set->card), set->type);//add to the set.
		//source,start byte+(card+1),length
	set->card+=set->type;//inc card by byte
}

void remElem(void *elem, uset *set){
	int i,j=0;
	for(i=0;i<set->card;i+=set->card)
		if(bcmp(elem,set->elem,set->type)){//find corresponding element.
			for(j=i;j<card;j++) //move elements after it foward
				byte tptr=(char*)set->
				=olem[j+1];
			card--;//dec card.
			if((card>INITSETSIZE)&&(card%INITSETSIZE))realloc(set->elem,card);
			//if new cardinal>64 and 64n then desize to the new cardinal
			return; //finished processing
		}
	//Not found,nothing to do.
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
}

void* umalloc(size_t size){
	void* ptr=malloc(size);
	if(ptr==NULL){
		fprintf(stderr,"ERROR: Calloc Failed\n");
		exit(1);
	}
	return ptr;
}

int bcmp(unsigned char* ptr1,unsigned char* ptr2,size_t size){
	while(size>0){
		size--;//start from the last byte
		if(ptr1[size]!=ptr2[size])return 0;
	}
	return 1;
}