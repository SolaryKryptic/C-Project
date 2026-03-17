@echo off
REM Change to the desired directory

REM Run the PowerShell command
powershell.exe -NoProfile -ExecutionPolicy Bypass -Command "& { .\Connect4.exe }"

REM Optional: Add a pause to keep the window open after execution
pause
