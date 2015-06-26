#include <stdlib.h>
#include <stdio.h>

typedef struct Complex_dbl{
	double re;
	double im;
}complex;

complex complexAdd(complex,complex);
complex complexMul(complex,complex);

int main(){
	complex c1={0,0};
	complex c2={0,0};
	printf("Input Complex number c1 (a+bi): ");
	scanf("%lf+%lfi,",&c1.re,&c1.im);
	printf("Input Complex number c2 (c+di): ");
	scanf("%lf+%lfi,",&c2.re,&c2.im);
	printf("Specify Operation: {ADD|MUL}:");
	char s[4];	scanf("%s",s);
	complex result={0,0};
	if(s[0]=='A'){
		result=complexAdd(c1,c2);
	}else{
		result=complexMul(c1,c2);
	}
	printf("Result: %lg + %lg i\n",result.re,result.im);
	return 0;
}

complex complexAdd(complex a,complex b){
	a.re+=b.re;a.im+=b.im;
	return a;
}

complex complexMul(complex a,complex b){
	complex t={0,0};
	t.re=a.re*b.re-a.im*b.im;
	t.im=a.re*b.im+a.im*b.re;
	return t;
}