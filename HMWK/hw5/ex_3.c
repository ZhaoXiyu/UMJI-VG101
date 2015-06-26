#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SWAP(a,b) ((a^=b),(b^=a),(a^=b))

int carddiff(int*,int*);

int main(){
	char* faction[]={"Spade","Heart","Diamond","Club"};
	char* card[]={"2","3","4","5","6","7","8","9",
					"10","Jack","Queen","King","Ace"};
	int deck[52][2];
	int i,j;
	printf("The deck before shuffled\n");
	for(i=0;i<4;i++)
		for(j=0;j<13;j++){
			int curr=13*i+j;
			deck[curr][0]=i;
			deck[curr][1]=j;
			printf("%s of %s\n",card[deck[curr][1]]
							 ,faction[deck[curr][0]]);
		}
	srand(time(NULL));
	for(i=0;i<52;i++){
		int des=rand()%52;
		SWAP(deck[i][0],deck[des][0]);
		SWAP(deck[i][1],deck[des][1]);
	}
	printf("\nThe shuffled deck:\n");
	for(i=0;i<52;i++)
		printf("%s of %s\n",card[deck[i][1]],faction[deck[i][0]]);
	for(i=0;i<52;i++)
		for(j=0;j<52-i;j++)
			if(carddiff(deck[j],deck[j+1])>0){
				SWAP(deck[j][0],deck[j+1][0]);
				SWAP(deck[j][1],deck[j+1][1]);
			}
	printf("\nThe sorted deck:\n");
	for(i=0;i<52;i++)
		printf("%s of %s\n",card[deck[i][1]],faction[deck[i][0]]);
	return 0;
}

int carddiff(int* cardx,int* cardy){
	int nx=cardx[0]*13+cardx[1];
	int ny=cardy[0]*13+cardy[1];
	return nx-ny;
}