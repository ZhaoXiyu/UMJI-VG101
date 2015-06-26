#include <stdio.h>
int gcd(int,int);

int main(){
	int a,b;
	printf("Input a and b: ");
	scanf("%d %d",&a,&b);
	printf("Greatest Common Dividor: %d",gcd(a>b?b:a,a>b?a:b));
	return 0;
}

int gcd(int a,int b){return (a%b==0)?b:gcd(b,a%b);}
	