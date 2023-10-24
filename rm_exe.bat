REM Description: remove all exe under folder
@echo off
cd /d "%~dp0"
for /f "delims=" %%a in ('dir /b /s *.exe') do (
    del /f /q "%%a"
)