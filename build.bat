@echo off
setlocal

REM Configuración de carpetas
set "build_dir=%~dp0build"

REM Crear carpeta build si no existe
if not exist "%build_dir%" (
    mkdir "%build_dir%"
)

cd /d "%build_dir%"

REM Generar configuración CMake
cmake -G "MinGW Makefiles" ..

REM Compilar
mingw32-make

endlocal
