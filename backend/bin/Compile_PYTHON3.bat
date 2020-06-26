:: %1 = RUN_ID


@echo off
cd ../
python submissions/%1.py >nul 2> compilationLog/%1.log
exit