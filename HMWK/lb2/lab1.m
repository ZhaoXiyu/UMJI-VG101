function []=lab1(~)
    clear all;
    clc;
    a=-1;
    b=3;
    while abs(a-b)>0.0001;
        t=0.5*(a+b);
        if foo(t)==0;b=t;break;end;
        if foo(t)*foo(a)<0 ;
            b=t;
        else
            a=t;
        end;
    end;
    disp(b);
end

function [y]=foo(x)
    y=x^2-9;
end
