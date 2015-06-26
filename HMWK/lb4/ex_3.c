#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
double foo(double);
int main(){
	#define A 75
	#define B 85
	double x1=A;
	double x2=B;
	double t;
	while(fabs(x1-x2)>FLT_EPSILON){
		t=0.5*(x1+x2);
		if(foo(x1)*foo(t)<=0){
			x2=t;
		}else{
			x1=t;
		}
	}
	printf("%g",t/(15*sqrt(3)));
	return 0;
}

double foo(double x){
	#define v0 30.0
	#define g 9.81
	#define theta (1.0/6.0*3.1415926)
	return 1.5+ tan(theta)*x-g/(2*v0*v0*cos(theta)*cos(theta))*x*x;
}