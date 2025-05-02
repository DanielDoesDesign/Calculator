@echo off

rem output directory
set target="Targets\%1"

rem install conan dependencies
rem conan install . --output-folder %target% --build missing -s build_type=%1 -c tools.system.package_manager:mode=install --profile arm64_x86crosscompile

rem generate cmake build files
cmake -S . -B %target% -DCMAKE_BUILD_TYPE=%1 -A win32

rem compile cmake build files
cmake --build %target% --config %1 

rem one day setup conan with build profile settings:
rem conan install . --profile cross-x86
