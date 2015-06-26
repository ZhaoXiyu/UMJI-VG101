clear all;
clc;
n = input('Input a year number: ');
while n<=0||floor(n)~=n;
    n = input('Illeagle input,please input again: ');
end;
if (n/4~=floor(n/4)) || (n/100 == floor(n/100) && n/400~=floor(n/400));
    disp('Not a leap year!');
else
    disp('A leap year!');
end;
