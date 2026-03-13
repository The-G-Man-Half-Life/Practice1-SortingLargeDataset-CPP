@echo off
echo Compiling the project 1...

:: Creates the file build if it does not exist.
if not exist build mkdir build

:: Compiles all the files .cpp of the folder src.
:: -I include : Tells the compiler to look for the .hpp in the folder include.
:: -O3        : Activates the maximum optimization.
:: -mconsole  : Indicates that this file must be executed in the console.
:: -std=c++17 : Uses the modern standard of C++.
g++ -std=c++17 -O3 -mconsole -I include src\*.cpp -o build/sortingMethods.exe

::Takes care of inidicating the user if the proccess was executed succesfully
::or no, and in case it worked tells the user how to proceed.
if %errorlevel% neq 0 (
    echo There were errors in the compilation
) else (
    echo Successfully compiled the project. 
    echo Use "build/sortingMethods.exe" to execute the program.
)