@echo off
chcp 1251
title ����������
mode con cols=64 lines=16
color 0a

echo ���� ������� �� ������� ����� data ����� JSON � SQL
echo � ���������� ���� �������� ��� ������ �����, ������

echo:
pyinstaller --onefile --icon="view\img\icon.ico" -w HUB.py
echo:

copy /Y "dist\HUB.exe" HUB.exe >nul
RD /S /Q "dist"
RD /S /Q "build"
del /Q "HUB.spec"

echo ���������� ���������
pause >nul