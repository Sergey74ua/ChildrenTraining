@echo off
chcp 1251
title ����������
mode con cols=80 lines=20
color 0a

echo ���� ����� ����������� ������� ����� ��������

echo:
pyinstaller --onefile --icon="view\img\icon.ico" -w HUB.py
echo:

copy /Y "dist\HUB.exe" HUB.exe >nul
RD /S /Q "dist"
RD /S /Q "build"
del /Q "HUB.spec"

echo ���������� ���������

echo ���� ������� �� ������� ����� data ����� JSON � SQL
echo � ���������� ���� �������� ��� ������ �����, ������

pause >nul