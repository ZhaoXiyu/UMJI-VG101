#include <stdlib.h>
#include <stdio.h>
FILE* ufopen(const char*,const char*);
int main(){
	int matA[3][3];
	int matB[3][3];
	int matsum[3][3];
	int matAB[3][3];
	int matTAB[3][3];
	FILE* infile=ufopen("matrix.txt","r");
	int i,j;
	for(i=0;i<3;i++)
		fscanf("%d %d %d\n",&matA[0][0],&matA[0][1],&matA[0][2]);
	for(i=0;i<3;i++)
		fscanf("%d %d %d\n",&matB[0][0],&matB[0][1],&matB[0][2]);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			matsum[i][j]=matA[i][j]+matB[i][j];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++){
			int k;matAB[i][j]=0;
			for(k=0;k<3;k++)
				matAB[i][j]+=matA[i][k]*matB[k][j];
		}
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			matTAB[i][j]=matAB[i][j];
	return 0;
}
FILE* ufopen(const char* fname,const char* mode){
	FILE* file=fopen(fname,mode);
	if(file==NULL){
		printf("ERROR:fopen on \"%s\" failed.",fname);
		exit(2);
	}
	return file;
}
