::Анимация спрайта в текстовом формате.
@echo off
setlocal enabledelayedexpansion
chcp 1251
title Dance
mode con cols=68 lines=41
color 0a
set F=1
:01
for /f "delims=" %%I in (dance.txt) do (
    set /a F=F+1
    echo.%%I
    if !F! gtr 40 (
        set F=1
		>nul pathping /h 1 /p 120 /q 1 /w 1 127.0.0.1
        cls
    )
)
goto 01