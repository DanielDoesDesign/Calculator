@echo off

:: List of directories to clean
set DIRS=build Targets out

:: Iterate through directories and delete them
for %%D in (%DIRS%) do (
    if exist %%D (
        rmdir /s /q %%D
        echo Deleted %%D
    ) else (
        echo %%D does not exist
    )
)
