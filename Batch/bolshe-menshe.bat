::������ - ������
@echo off
chcp 1251
title ������ - ������!
mode con cols=48 lines=16
color 0a
set T=����� � ����
:01
cls
set N=0
set /a R=%random% %%1000+1
:02
cls
echo:
echo  %T%
echo:
echo  ����� �������: %N%
set /a N+=1
echo:
set /p S=������� ����� (1-1000): 
echo:
if %S% == %R% (set T=������ c %N% �������.  ����� ���� ... & goto 01)
if %S% gtr %R% (set T=������ & goto 02)
if %S% lss %R% (set T=������ & goto 02)