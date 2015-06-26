#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int day=0;
	int month=0;
	char s[20]="";
	printf("Input Day Month(string integer): ");
	scanf("%s %d",s,&month);
	int i;for(i=0;s[i]!='\0';i++)if(s[i]>'Z')s[i]-='z'-'Z';
	switch(s[0]+s[1]+s[2]){
		case 'S'+'U'+'N': day=0;break;
		case 'M'+'O'+'N': day=1;break;
		case 'T'+'U'+'E': day=2;break;
		case 'W'+'E'+'D': day=3;break;
		case 'T'+'H'+'U': day=4;break;
		case 'F'+'R'+'I': day=5;break;
		case 'S'+'A'+'T': day=6;break;
	}
	printf("\t\t\tCalendar of %d\n",month);
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	for(i=0;i<day;i++)printf("\t");
	int dom;
	if(month<=7){
		dom=30+(month%2);
	}else{
		dom=31-(month%2);
	}
	if(month==2)dom=28;
	for(i=1;i<=dom;i++){
		printf("%d\t",i);
		if(((i+day)%7)==0)printf("\n");
	}
	return 0;
}
	