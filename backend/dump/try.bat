@echo off
cd 3
for /f %%i in ('dir /b') do set result=%%i
java %result:~0,-6%

echo %result%