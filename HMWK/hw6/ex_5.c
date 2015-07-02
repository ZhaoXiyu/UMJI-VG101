#include "set.h"
#define MCHNK 64
#define byte unsigned char
#define CARD (set->card)
#define ELEM (unsigned char*)(set->elem)
#define TYPE (set->type)
#include <stdlib.h>
#include <stdio.h>

void* umalloc(size_t);
void* urealloc(void*,size_t);
int bcmp(unsigned char*,unsigned char*,size_t);

int main(){
	uset intset;
	newSet(&intset,INT);
	int i;
	for(i=0;i<20000;i++){
		//printf("%d %d \n",i,intset.card);
		addElem(&i,&intset);
	}
	for(i=25000;i>15000;i--){
		//printf("%d %d \n",i,intset.card);
		remElem(&i,&intset);
	}
	deletSet(&intset);
	return 0;
}

void addElem(void *elem, uset *set){
	byte* i;
	for(i=ELEM;(i-ELEM)<CARD;i+=TYPE)
		if(bcmp(elem,i,TYPE))return;//Same element already exist
	//printf("%d %d\n",*(int*)elem,CARD);
	if(((CARD-INITSETSIZE*TYPE)%MCHNK)==0&&CARD>=INITSETSIZE*TYPE)//if the space is critical.
		set->elem=urealloc(ELEM,CARD+MCHNK);//Resize to 64 more.
	memcpy(ELEM+CARD,elem,TYPE);//add to the set.
		//source,start byte+card,length
	CARD+=TYPE;//inc card by byte
	return;
}

void remElem(void *elem, uset *set){
	byte* i;
	//printf("%d\n",*(int*)elem);
	for(i=ELEM;(i-ELEM)<CARD;i+=TYPE)
		if(bcmp(elem,i,TYPE)){
			memmove(i,i+TYPE,CARD-(i-ELEM)-TYPE+1);//Push all memory forward type bytes
			CARD-=TYPE;//dec card.
			if((CARD>INITSETSIZE*TYPE)
				&&((CARD-(INITSETSIZE*TYPE))%MCHNK))
					set->elem=realloc(ELEM,CARD);
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
