function ex2
    clear all;
    clc;
    format long;
    disp('input a function (in the form of matlab): ');
    fun = eval(['@(x)',input('f(x)= ','s')]);
    a=input('Input x_0,make sure f(x_0)<0, x_0 = ');
    b=input('Input x_1,make sure f(x_1)>0 x_1 = ');
    p=abs(input('Input percision e.g. 0.00001 : '));
    t= rec(a,b,fun);
    while max([a,b,t])-min([a,b,t])>p;
        t= rec(a,b,fun);
        a=b;
        b=t;
    end;
    fprintf('The root: %.15f\n',t);
end

function xn=rec(xn_2,xn_1,foo)
    xn = ( xn_2 *foo(xn_1) - xn_1*foo(xn_2) ) / ( foo(xn_1) - foo(xn_2) );
    return;
end