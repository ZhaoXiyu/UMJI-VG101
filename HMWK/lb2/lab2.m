function lab2(~)
   disp(zc([28,2,2001]));
end

function strday=zc(inpdate)
    d=inpdate(1);
    m=inpdate(2)-2;
    if m<=0;
        m=m+12;
        inpdate(3)=inpdate(3)-1;
    end;
    c=floor(inpdate(3)/100);
    y=mod(inpdate(3),100);
    %Preprocessing the inputs
    day=1+mod((d+floor((13*m-1)/5)+y+floor(y/4)+floor(c/4)-2*c),7);
    %The actual function
    switch day
        case 0
            strday='Saturday';
        case 1
            strday='Sunday';
        case 2
            strday='Monday';
        case 3
            strday='Tuesday';
        case 4
            strday='Wednsday';
        case 5
            strday='Thursday';
        case 6 
            strday='Friday';
        otherwise
            strday=['Error,',num2str(day)];
    end;
    %Preparing user-friendly output.
    return;
end

