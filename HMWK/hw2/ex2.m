clear all;
clc;
n = 4* ceil(input('Input an integer: ')/4)+1;
if n<5;n=5;end;
while any(mod(n,[3:2:floor(sqrt(n))])==0);
    n=n+4;
end;%got the prime, now we decompose it
sqr = floor(sqrt(n));
vecsub=[2:2:sqr].^2;
vecans=sqrt(n-vecsub);
index=find(vecans==floor(vecans));
display(['The next specified prime is: ', num2str(n)]);
display(['First sqaured: ', num2str(vecsub(index)),'=',num2str(sqrt(vecsub(index))),'^2']);
display(['Second sqaured: ', num2str(n-vecsub(index)),'=',num2str(sqrt(n-vecsub(index))),'^2']);