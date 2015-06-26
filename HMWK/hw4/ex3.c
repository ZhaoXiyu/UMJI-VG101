#include <stdio.h>
#include <stdlib.h>

int main(){
	char s[20]={0};
	printf("Input ONE character: ");
	scanf("%s",s);
	char c=s[0];
	if(c>'Z')c-='z'-'Z';
	if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
		printf("It is a vowel.\n",c);
	}else{
		printf("It is a consonant.\n",c);
	}
	return 0;
}