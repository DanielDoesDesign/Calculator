@echo off

:: Force kill any instances of game
taskkill /F /IM powershell.exe
taskkill /F /IM msbuild.exe

:: List of directories to clean
set DIRS=Targets\Debug\bin Targets\Debug\lib 
::Targets\Debug\CMakeFiles

:: Iterate through directories and delete them
for %%D in (%DIRS%) do (
    if exist %%D (
        rmdir /s /q %%D
        echo Deleted %%D
    ) else (
        echo %%D does not exist
    )
)

@echo off

:: Clean Cmake cache
:: Path to the file you want to delete
set FILE_PATH=Targets\Debug\CMakeCache.txt

:: Check if the file exists and delete it
if exist "%FILE_PATH%" (
    del "%FILE_PATH%"
    echo Deleted %FILE_PATH%
) else (
    echo %FILE_PATH% does not exist
)

