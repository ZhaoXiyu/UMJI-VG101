#include <stdio.h>
#include <math.h>
int main(){
	printf("Input Coefficients of ax^2+b*x+c {a b c}: ");
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a==0){
		printf("NOT A QUADRATIC EQUATION");
		return 0;
	}
	double alpha = b*b -4*a*c;
	if(alpha<0){
		printf("NO ROOT IN REAL_NUMBERS");
		return 0;
	}
	if(alpha==0){
		double x=-b/(2*a);
		printf("1 Root:%lg",x);
		return 0;
	}
	double x1=(-b+sqrt(alpha))/(2*a);
	double x2=(-b-sqrt(alpha))/(2*a);
	printf("2 Roots:x1=%lg,x2=%lg",x1,x2);
	return 0;
}