::%1 --> runid, %2 --> quesid, %3 --> timelimit

@echo off
call "cmd /c start KILL_PYTHON.bat %3 %1 "
cd ../submissionsExec
python %1.py < ../testCases/%2.txt > ../codeOut/%1.txt 2> ../runtimeLog/%1.log
exit