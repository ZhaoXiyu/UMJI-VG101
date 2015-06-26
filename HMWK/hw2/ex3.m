 clear all;
clc;
inventory(1:3)= struct('Type',' ','Color',' ','Quantity',0,'BoughtDate',[]);
%===================Importing Original data=================
[inventory(1:3).Type]=deal('Jumpers');
[inventory(4:6).Type]=deal('Trousers');
[inventory(7:11).Type]=deal('T-shirts');
pause;
[inventory(1:11).Color]=deal('Blue','Brown','Green','Black','Grey','White', ...
                            'Blue','Green','Red','White','Yellow');
[inventory(1:11).Quantity]=deal(2,3,5,3,2,1,1,2,3,2,1);
[inventory(1:11).BoughtDate]=deal( ... 
                           datenum('04/2005','mm/yyyy'), ...
                           datenum('02/2013','mm/yyyy'), ...
                           datenum('01/2015','mm/yyyy'), ...
                           datenum('06/2012','mm/yyyy'), ...
                           datenum('04/2011','mm/yyyy'), ...
                           datenum('12/2013','mm/yyyy'), ...
                           datenum('05/2010','mm/yyyy'), ...
                           datenum('09/2014','mm/yyyy'), ...
                           datenum('01/2012','mm/yyyy'), ...
                           datenum('03/2008','mm/yyyy'), ...
                           datenum('11/2012','mm/yyyy'));
%===================Imported Original data=================
[m,index]=max([inventory(:).Quantity]);
fprintf('The maximum quatity: %s, %s \n',inventory(index).Type,inventory(index).Color);
datenumavg=sum([inventory(:).BoughtDate].*[inventory(:).Quantity])/sum([inventory(:).Quantity]);
disp(['The average age of the stack(Rounded Down):',num2str(floor(yearfrac(datenumavg,now)))]);
