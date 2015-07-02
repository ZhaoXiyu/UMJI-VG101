#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char ugetchar();
int main(){
	char s[100]={0};
	printf("Input your string: ");
	gets(s);
	printf("Specify operation? ");
	int a;
	scanf("%d",&a);
	switch(a){
		case 1: 
			printf("Replaced character? ");
			char rpc=ugetchar();
			printf("With? ");
			char nc=ugetchar();
			int i;
			for(i=0;s[i]!='\0';i++)
				if(s[i]==rpc)s[i]=nc;
			printf("New String: %s",s);
			break;
		case 2:
			printf("Deleted Character? ");
			char delc=ugetchar();
			char* ptr;
			while((ptr=strchr(s,delc))!=NULL)
				memmove(ptr,ptr+1,strlen(s)-(ptr-s));
			printf("New String: %s",s);
			break;
		default:
			printf("Illegal operation!");
			exit(1);
	}
	return 0;
}

char ugetchar(){
	fflush(stdin);
	return getchar();
}