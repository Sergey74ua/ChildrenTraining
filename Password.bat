@echo off
chcp 1251
cls
:1
set /p Pass=Пароль:
if %Pass%==12345 (goto 2) else (echo Пароль не верный && goto 1)
:2
echo Пароль верный!
pause >nul