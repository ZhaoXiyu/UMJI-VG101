clear all;
clc;
dprofit=10000;
p=zeros(1,20);
p(1)=10000/((1-1.024^10)/(1-1.024));
for i=1:20
    p(i)=round(p(1)*(1.024^(i-1))*100)/100;
end
fd=fopen('profit.out','w+');
for i=1:20
    fprintf(fd,'%d\t%f\n',i+1995,p(i));
end
fclose(fd);