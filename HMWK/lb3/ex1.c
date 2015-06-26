#include <stdlib.h>
#include <stdio.h>
#define G 6.67E-11
#define PI 3.14

int main(){
	double circ,dis,period,dens;
	printf("%e",G);
	printf("Input Circumference, Distance, Period: ");
	scanf("%lf %lf %lf",&circ,&dis,&period);
	dens=(24*PI*PI*PI*PI*dis*dis*dis)/(G*circ*circ*circ*period*period);
	printf("The density is %lf",dens);
	return 0;
}
