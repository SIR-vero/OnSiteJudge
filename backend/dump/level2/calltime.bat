@echo off
set t=%1
call "cmd /c start timee.bat %t% "
TIMEOUT /T 20 /NOBREAK
echo ending
TIMEOUT /T 5 /NOBREAK
exit