@echo off
set "exe_path=%~dp0build\TestingLlama.exe"

if exist "%exe_path%" (
    echo Ejecutando...
    "%exe_path%"
) else (
    echo Error: No se encontró el ejecutable.
    echo Asegúrate de haber ejecutado build.bat primero.
    exit /b 1
)
