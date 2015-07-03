#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926

typedef struct{
	double re;
	double im;
}ComplexCart;

typedef struct{
	double rad;
	double ang;
}ComplexPol;

int cart2pol(ComplexCart*,ComplexPol*,int);
int pol2cart(ComplexPol*,ComplexCart*,int);

int main(){
	ComplexCart zcs[]={{3,4.0/5.0},{0,log(4)},{45.245,0.235}};
	ComplexPol zcd[sizeof(zcs)/sizeof(ComplexCart)]={0};
	ComplexPol zps[]={{3.0,PI/17.0},{4,PI/9},{1,PI/12}};
	ComplexCart zpd[sizeof(zps)/sizeof(ComplexPol)]={0};
	cart2pol(zcs,zcd,sizeof(zcs)/sizeof(ComplexCart));
	pol2cart(zps,zpd,sizeof(zps)/sizeof(ComplexPol));
	return 0;
}

int cart2pol(ComplexCart *source,ComplexPol *dest,int size){
	int i;
	for(i=0;i<size;i++){
		dest[i].rad=sqrt(source[i].re*source[i].re+source[i].im*source[i].im);
		dest[i].ang=acos(source[i].re/dest[i].rad);
		if(source[i].im<0)dest[i].ang=-dest[i].ang+2*PI;
	}
	return 0;
}

int pol2cart(ComplexPol *source,ComplexCart *dest,int size){
	int i;
	for(i=0;i<size;i++){
		dest[i].re=source[i].rad*cos(source[i].ang);
		dest[i].re=source[i].rad*sin(source[i].ang);
	}
	return 0;
}