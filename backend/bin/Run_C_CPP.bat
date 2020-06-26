::%1 --> runid, %2 --> quesid, %3 --> timelimit

@echo off
call "cmd /c start KILL_C_CPP.bat %3 %1 "
cd ../submissionsExec
::echo here
%1 < ../testCases/%2.txt > ../codeOut/%1.txt
::echo here1
exit