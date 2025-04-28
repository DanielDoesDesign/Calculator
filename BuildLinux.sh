#!/bin/bash

# Output directory
target="Targets/$1"

# Activate Python env (if needed)
source ~/Desktop/Coding/Project1/pyenv/bin/activate

# Install Conan dependencies (excluding SFML)
conan install . --output-folder $target --build=missing -s build_type=$1 \
    -c tools.system.package_manager:sudo=True -c tools.system.package_manager:mode=install

# Only clear CMake cache if it's a first-time build
if [ ! -f "$target/CMakeCache.txt" ]; then
    echo "First-time build: Clearing CMake cache."
    rm -rf $target/CMakeFile s
fi

# Generate CMake build files (re-runs only if changes are detected)
cmake -S . -B $target -DCMAKE_BUILD_TYPE=$1 -DCMAKE_TOOLCHAIN_FILE="$target/conan_toolchain.cmake"

#Compile
#cmake --build $target --config $1

