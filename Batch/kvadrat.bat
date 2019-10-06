::Выводим заданный квадрат.
@echo off
chcp 1251 >nul
title Задания.
mode con cols=150 lines=40
color 0a
:01
set /a X=2
set /p S=Введите сторону квадрата: 
echo:
for /L %%A in (1,1,%S%) do <nul set /p =##
echo:
:02
if not %X% geq %S% (
	<nul set /p =##
	for /L %%A in (3,1,%S%) do <nul set /p =. 
	<nul set /p =##
	set /a X+=1
	echo:
	goto 02)
for /L %%A in (1,1,%S%) do <nul set /p =##
echo:
pause >nul
cls
goto 01