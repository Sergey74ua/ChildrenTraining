::     Batch-���������� "������-�������-������", �������� 26.06.2018 �.
::  �������� � ����� �������� ����� ������� ����������������, � ��� ���
::  � ����������, �� ������ �� ������ ...
::     �����: �������� ������ ����������.
@echo off
chcp 1251
title ������ - ������� - ������.
mode con cols=60 lines=16
color 0b
set GAMET= ����� � ����
:1
cls
echo                                    %date% %time%
echo:
echo   ����������������   �����������������   ����������������
echo   [  1 - ������  ]   [  2 - �������  ]   [  3 - ������  ]
echo   ����������������   �����������������   ����������������
echo:
echo  ����� ���: %GAME%   ������: %WIN%   ���������: %LOSE%   �����: %DRAW%
echo:
echo  ����� ������     - %KNBT%
echo  ��������� ������ - %RNDT%
echo:
echo %GAMET%
echo:
choice /c 123 /n /m "�������� (1, 2, 3): "
set KNB=%ERRORLEVEL%
if %KNB%==1 (set KNBT=������)
if %KNB%==2 (set KNBT=�������)
if %KNB%==3 (set KNBT=������)
set /a RND=1+3*%random%/32767
if %RND%==1 (set RNDT=������)
if %RND%==2 (set RNDT=�������)
if %RND%==3 (set RNDT=������)
set /a GAME=%GAME%+1
if %KNB%==%RND% (set GAMET=    ����� & set /a DRAW=%DRAW%+1 & goto 1)
if %KNB%==1 (if %RND%==2 (goto 2))
if %KNB%==2 (if %RND%==3 (goto 2))
if %KNB%==3 (if %RND%==1 (goto 2))
set /a LOSE=%LOSE%+1
set GAMET=    ��������
goto 1
:2
set /a WIN=%WIN%+1
set GAMET=    ���! ������
goto 1