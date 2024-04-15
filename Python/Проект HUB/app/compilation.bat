@echo off
chcp 1251
title Компилятор
mode con cols=64 lines=16
color 0a

echo Надо вынести во внешнюю папку data файлы JSON и SQL
echo и подключить файл ресурсов для иконок формы, кнопок

echo:
pyinstaller --onefile --icon="view\img\icon.ico" -w HUB.py
echo:

copy /Y "dist\HUB.exe" HUB.exe >nul
RD /S /Q "dist"
RD /S /Q "build"
del /Q "HUB.spec"

echo Компиляция завершена
pause >nul