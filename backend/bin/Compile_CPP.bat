:: %1 = RUN_ID


@echo off
cd ../
g++ -std=c++14 -o submissionsExec/%1 submissions/%1.cpp 2> compilationLog/%1.log
exit