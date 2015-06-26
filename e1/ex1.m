clear all;
clc;
disp('Try testing it with about 200 for best visual :)');
n=input('input number of points: ');
points=rand(2,n);
[points(:,1)]=0;
for i=1:n 
    for j=1:n
        distance(i,j)=sqrt(sum(([points(:,i)]-[points(:,j)]).^2));
    end
end
hold on;
for i=1:n
     plot([points(1,i)],[points(2,i)],'-sk');
end;
for i =1:n
    if mod(i,2)==0;
        [dis,j]=min([distance(i,1:(i-1)),Inf,distance(i,(i+1):end)]);
    else
        [dis,j]=max([distance(i,1:(i-1)),0,distance(i,(i+1):end)]);
    end;
    plot([points(1,i) points(1,j)],[points(2,i) points(2,j)]);
    drawnow
end;
plot([points(1,n),points(1,1)],[points(2,n),points(2,1)]);
hold off;
    
