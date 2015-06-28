#include <stdlib.h>
#include <stdio.h>
int test();
int main(){
	int i,j,k;
	char* s1="Good Morning";
	char* s2="Hello world";
	char s7[20]={0};
	strcpy(s7,s2);
	s7[2]='L';
	mempeek(s2,20);
	strcpy(s2,s7);
	printf("%s",s2);
	char s3[10]="STRING3";
	char s6[20]="STRING6";
	
	int card[52][2];
	test();
	printf("233");
	return 0;
}

int test(){
	char* s4="GOOD LUCK";
	exit(50);
}
