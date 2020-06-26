:: %1 = RUN_ID


@echo off
cd ../
cd submissionsExec
mkdir %1
cd ../
javac -d submissionsExec/%1 submissions/%1.java 2> compilationLog/%1.log
exit