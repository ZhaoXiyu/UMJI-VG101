%% Fun Main
function []=ex1(~)
    clear all;
    clc;
    n =233;
    clear all;
    clc;
    n = input('Input an integer: ');
    if n~=0;
        disp(read(n));
    else
        disp('zero');
    end;
end
%% Fun Read
function str=read(num)
    idiv=@(x,d)floor(x/d);
    if num>=1000000;
        if mod(num,1000000)<100 ;
            str=[read(idiv(num,1000000)),'million and ',read(mod(num,1000000))];
        else
            str=[read(idiv(num,1000000)),'million ',read(mod(num,1000000))];
        end
    elseif num>=1000;
        if mod(num,1000)<100;
            str=[read(floor(num/1000)),'thousand and ',read(mod(num,1000))];
        else
            str=[read(floor(num/1000)),'thousand ',read(mod(num,1000))];
        end;
    elseif num>=100;
        if mod(num,100)~=0;
            str=[read(idiv(num,100)),'hundred and ',read(mod(num,100))];
        else
            str=[read(idiv(num,100)),'hundred ',read(mod(num,100))];
        end
    elseif num>20;
        str=[getTens(idiv(num,10)),read(mod(num,10))];
    else
        str=directRead(num);
    end;
end
%% Fun GenTens
function string=getTens(num)
    if num ==0;string='';return;end;
    constants={'','twenty ','thirty ','fourty ','fifty ','sixty ','seventy ','eighty ','ninty '};
    string = constants{num};
    return;
end

function string=directRead(num)
    if num==0;string='';return;end;
    constants={'one ','two ','three ','four ','five ','six ','seven ', ...
        'eight ','nine ', 'ten ', 'eleven ','twelve ','thirteen ', ...
        'fourteen ','fifteen ','sixteen ','seventeen ','eighteen ', ...
        'nineteen ','twenty '};
    string =(constants{num});
    whos str
    return;
end