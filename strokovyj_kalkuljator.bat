@echo off
chcp 1251 >nul
:01
echo:
set /p X=������� ���������: 
set /a X=%X%
echo ���������: %X%
goto 01