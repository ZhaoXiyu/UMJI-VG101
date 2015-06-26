#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	int bound=0;
	printf("Input a bound(integer): ");
	scanf("%d",&bound);
	srand(time(NULL));
	int r=rand()%bound;
	int win=0;
	for(;;){
		printf("Input a guess(Integer): ");
		int guess=0;
		scanf("%d",&guess);
		if(guess==r)break;
		if(guess>r)printf("Smaller\n");
		if(guess<r)printf("Larger\n");
	}
	printf("Win!");
	return 0;
}