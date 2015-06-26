#include <stdlib.h>
#include <stdio.h>

int main(){
	int i,j,k;
	char* TYPE[]={"Spade","Heart","Diamond","Club"};
	char* NUMB[]={"2","3","4","5","6","7","8","9",
					"10","Jack","Queen","King","Ace"};
	int card[52][2];
	for(k=0;k<52;k++){
		j=k%13;i=(k-j)/13;
		card[k][1]=i;
		card[k][2]=j;
		printf("%d\t%d\t%d\t%s\t%s\n",k,i,j,TYPE[card[k][1]],NUMB[card[k][2]]);		
	}
	mempeek(card,sizeof(card));
	for(k=0;k<52;k++){
		printf("%d\t%s\t%s\n",k,TYPE[card[k][1]],NUMB[card[k][2]]);
	}
	return 0;
}
