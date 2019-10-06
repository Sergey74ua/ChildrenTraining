::     Batch-прогрмамма "Камень-ножницы-бумага", написана 26.06.2018 г.
::  Написана с целью обучения детей основам программирования, с чем они
::  и справились, но каждый по своему ...
::     Автор: Покидько Сергей Алексеевич.
@echo off
chcp 1251
title Камень - ножницы - бумага.
mode con cols=60 lines=16
color 0b
set GAMET= УДАЧИ В ИГРЕ
:1
cls
echo                                    %date% %time%
echo:
echo   ————————————————   —————————————————   ————————————————
echo   [  1 - КАМЕНЬ  ]   [  2 - НОЖНИЦЫ  ]   [  3 - БУМАГА  ]
echo   ————————————————   —————————————————   ————————————————
echo:
echo  Всего игр: %GAME%   Победы: %WIN%   Поражения: %LOSE%   Ничьи: %DRAW%
echo:
echo  Игрок выбрал     - %KNBT%
echo  Компьютер выбрал - %RNDT%
echo:
echo %GAMET%
echo:
choice /c 123 /n /m " Введите (1, 2, 3): "
set KNB=%ERRORLEVEL%
if %KNB%==1 (set KNBT=КАМЕНЬ)
if %KNB%==2 (set KNBT=НОЖНИЦЫ)
if %KNB%==3 (set KNBT=БУМАГА)
set /a RND=1+3*%random%/32767
if %RND%==1 (set RNDT=КАМЕНЬ)
if %RND%==2 (set RNDT=НОЖНИЦЫ)
if %RND%==3 (set RNDT=БУМАГА)
set /a GAME=%GAME%+1
if %KNB%==%RND% (set GAMET=    НИЧЬЯ & set /a DRAW=%DRAW%+1 & goto 1)
if %KNB%==1 (if %RND%==2 (goto 2))
if %KNB%==2 (if %RND%==3 (goto 2))
if %KNB%==3 (if %RND%==1 (goto 2))
set /a LOSE=%LOSE%+1
set GAMET=    ПРОИГРЫШ
goto 1
:2
set /a WIN=%WIN%+1
set GAMET=    УРА! ПОБЕДА
goto 1