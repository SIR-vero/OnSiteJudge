@echo off
echo timee started
set tt=%1
echo %tt%
TIMEOUT /T %tt% /NOBREAK
exit