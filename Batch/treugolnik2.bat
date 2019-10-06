::Выводим заданный треугольник.
@echo off
chcp 1251 >nul
title Задания.
mode con cols=150 lines=35
color 0a
:01
set /p S=Введите сторону треугольника: 
echo:
for /L %%A in (1,1,%S%) do <nul set /p =#
echo:
set /a S1=%S%+1
for /L %%A in (4,1,%S1%) do (
	<nul set /p =#
	for /L %%A in (%S%,-1,%%A) do <nul set /p =.
	<nul set /p =#
	echo:
	)
echo #
echo:
pause >nul
cls
goto 01