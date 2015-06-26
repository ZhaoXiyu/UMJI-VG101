clear all;
clc;
%This Generates an input (uint64)
output=uint64(floor(uint64(rand([1 1000])*12345927+60)/3600/24));
%This Gnerates output
%Less Then a day will NOT be counted to be a full day
%output represented in uint64