:: %1 --> time limit

@echo off
TIMEOUT /T %1 /NOBREAK
taskkill /F /IM %2.exe /T > ../tleLog/%2n.log 2> ../tleLog/%2.log
exit