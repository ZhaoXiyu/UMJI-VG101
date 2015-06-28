#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int n=0;
	printf("Input an integer, n: ");
	scanf("%d",&n);
	char *flag=(char*)calloc(n+1,sizeof(int));
	int i,j;
	for(i=2;i<=sqrt(n);i++)
		if(flag[i]==0)
			for(j=(i<<1);j<=n;j+=i)flag[j]=1;
	for(i=2;i<(n+1);i++)
		if(flag[i]==0)printf("%d ",i);
	free(flag);
	return 0;
}