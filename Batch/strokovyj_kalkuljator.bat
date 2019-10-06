@echo off
chcp 1251 >nul
:01
echo:
set /p X=Введите уравнение: 
set /a X=%X%
echo Результат: %X%
goto 01