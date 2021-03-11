::Больше - меньше
@echo off
chcp 1251
title Больше - меньше!
mode con cols=48 lines=16
color 0a
set T=Удачи в игре
:01
cls
set N=0
set /a R=%random% %%1000+1
:02
cls
echo:
echo  %T%
echo:
echo  Всего попыток: %N%
set /a N+=1
echo:
set /p S=·Угадай число (1-1000): 
echo:
if %S% == %R% (set T=УГАДАЛ c %N% попыток.  Новая игра ... & goto 01)
if %S% gtr %R% (set T=МЕНЬШЕ & goto 02)
if %S% lss %R% (set T=БОЛЬШЕ & goto 02)