@echo off
chcp 1251 >nul
title Компиляция CS-кода
mode con cols=64 lines=16
color 0a

echo %TIME% - Compilation
"C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe" HelloWorld.cs
