clear all;
clc;
LapsPerLap = uint32(400);
L=uint32(input('Input length to run in meters: '));
R=mod(L,LapsPerLap);
Laps= (L-R)/LapsPerLap;
if R==0 
    fprintf('Number of Laps: %d Lap(s), No Remainder.\n', Laps);
else
    fprintf('Number of Laps: %d Lap(s). Extra %dM to reach next lap.\n', Laps, LapsPerLap - R);
end
