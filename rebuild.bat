@REM CREAMOS BUILD SI NO EXISTE
if exist build (rmdir /s /q build)
mkdir build
cd build

@REM SELECCIONAMOS COMPILADOR: MinGW (Antes cmake ..) 
cmake -G "MinGW Makefiles" ..

@REM COMPILAMOS
if errorlevel 1 (
    exit /b 1
)
cmake --build .