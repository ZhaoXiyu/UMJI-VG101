#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

float mean(float*,int);
float median(float*,int);
float variance(float*,int);
float stddev(float*,int);

int main(){
	float score[10];
	int i;
	printf("Input 10 scores: ");
	for(i=0;i<10;scanf("%f",score+i++));
	printf("The mean is %g \n",mean(score,10));
	printf("The median is %g \n",median(score,10));
	printf("The variance is %g \n",variance(score,10));
	printf("The standard deviation is %g \n",stddev(score,10));
	return 0;
}

float mean(float* a,int size){
	float s=0;int i=0;
	for(i=0;i<size;i++)s+=a[i];
	return s/size;
}

float median(float* a,int size){
	int i=0;int j=0;
	float x,y=0;
	for(i=0;i<size;i++){
		int tab=0;
		for(j=0;j<size;j++)
			if(a[j]<=a[i])tab++;
		tab--;
		if(tab==4)x=a[i];
		if(tab==5)y=a[i];
	}
	return 0.5 * (x+y);
}

float variance(float* a,int size){
	float s=0;
	float med=mean(a,size);
	int i;
	for(i=0;i<size;i++)
		s+=(a[i]-med)*(a[i]-med);
	return s/size;
}

float stddev(float* a,int size){
	return sqrt(variance(a,size));
}