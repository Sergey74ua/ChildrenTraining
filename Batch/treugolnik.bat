::������� �������� �����������.
@echo off
chcp 1251 >nul
title �������.
mode con cols=150 lines=35
color 0a
:01
set /p S=������� ������� ������������: 
echo:
echo ##
set X=2
:02
if not %X% geq %S% (
	<nul set /p =##
	for /L %%A in (3,1,%X%) do <nul set /p =..
	<nul set /p =##
	set /a X+=1
	echo:
	goto 02)
for /L %%A in (1,1,%S%) do <nul set /p =##
echo:
pause >nul
cls
goto 01