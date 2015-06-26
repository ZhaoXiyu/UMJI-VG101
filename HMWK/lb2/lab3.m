    clear all;
    clc;
    n=input('Input the lines of the triangles: ');
    mat=rot90(pascal(n));
    fid=fopen('out.txt','w+');
    for i=1:n;
        s='';
        for j=1:n-i;
            s=[s,sprintf('\t')];
        end;
        t=diag(mat,-n+i);
        for j=1:i;
            s=[s,sprintf('%d\t\t',t(j))];
        end;
        fprintf(fid,'%s\n',s);
    end;
    fclose(fid);


