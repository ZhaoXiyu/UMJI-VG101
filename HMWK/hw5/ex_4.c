#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a,b) { a ^= b; b ^= a; a ^= b; }
unsigned long int mult(unsigned long int a, unsigned long int b);
int getDigits(unsigned long int,int);

int main(){
	srand(time(NULL));
	unsigned long int a, b;
#ifndef TEST
	#ifndef TESTC
	a=rand(); b=rand();
	printf("%ld*%ld=%ld %ld\n",a,b,mult(a,b), RAND_MAX);
	#endif
#endif
#ifdef TEST
	int i;
	for(i=0; i< 10000; i++) {
		a=rand(); b=rand();
		if(mult(a,b)!=a*b)
			fprintf(stderr,"Error (%d): a=%ld, b=%ld, a*b=%ld, k(a,b)=%ld\n",i,a,b,a*b,mult(a,b));
	}
#endif
#ifdef TESTC
	#define ITER 100000000
	int n,i,j;
	char* digit1=malloc(ITER);
	char* digit2=malloc(ITER);
	unsigned long int* data=malloc(ITER*sizeof(long));
	for(j=0;j<ITER;j++)data[j]=rand();
	clock_t t0=clock();
	for(j=0;j<ITER;j++)
		for(digit1[j]=-1, i = 1; i <= data[j]; i<<=1, digit1[j]++);
	clock_t t1=clock();	
	for(j=0;j<ITER;j++)digit2[j]=getDigits(j,sizeof(unsigned long));
	clock_t t2=clock();
	printf("%g,%g",(t1-t0)/(double)(CLOCKS_PER_SEC),(t2-t1)/(double)(CLOCKS_PER_SEC));
	free(digit1);free(digit2);free(data);
#endif
	return 0;
}

unsigned long int mult(unsigned long int a, unsigned long int b){
	int i, n, N;
	unsigned long int x0,y0,z0,z1=1;//z1:highest bit of a and b
	if(a<b) SWAP(a,b);//make sure a>b
	if(b==0) return 0;// the special case (b==0);also the end of recursion.
	n=getDigits(b,8*sizeof(unsigned long))-1; /* not optimal */
	//count the digit of the smaller number b,subtract 1, stored in n
	//for(N=n; i <= a; i<<=1, N++);
	N=getDigits(a,8*sizeof(unsigned long))-1;
	//count the digit of the larger number a,subtract 1 stored in N
	//since a>b thus we can assume N>n
	y0=b&((1<<n)-1);
	//Acquire the lower n-1 bits of b,stored in y0
	x0=a&((1<<N)-1);
	//Acquire the lower N-1 bits of a, stored in x0
	z0=mult(x0,y0);
	//recurisvely calculate y0*x0
	i=N+n;
	//the highest bit of the result
	return ((z1<<i)+(x0<<n)+(y0<<N)+z0);
	//calculation of the end result.
	//(denote yh=xh=1 as the highest0digit of a,b )
	// r=(yh*2^N+y0)(xh*2^n+x0)
	// r=yh*xh*2^(N+n)+yh*x0*2^N+y0*xh*2^n+x0*y*0
	// r=1<<(N+n)+x0<<N+y0<<n+z0
}

int getDigits(unsigned long int n, int bits){
	int digits=0;
	while(bits!=0){
		bits>>=1;
		unsigned long int nh=n>>bits;
		if(nh>0){n=nh;digits+=bits;}
	}
	return digits+1;
}
