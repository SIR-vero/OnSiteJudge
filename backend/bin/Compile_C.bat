:: %1 = RUN_ID


@echo off
cd ../
gcc -o submissionsExec/%1 submissions/%1.c 2> compilationLog/%1.log
exit