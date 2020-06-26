::%1 --> runid, %2 --> quesid, %3 --> timelimit

@echo off
call "cmd /c start KILL_JAVA.bat %3 %1 "
cd ../submissionsExec/%1

for /f %%i in ('dir /b') do set mainclass=%%i

java %mainclass:~0,-6% > ../../codeOut/%1.txt 2> ../../runtimeLog/%1.log
exit