#!/bin/bash

# List of directories to clean
DIRS=("build" "bin" "lib")

# Iterate through directories and delete them
for DIR in "${DIRS[@]}"; do
    if [ -d "$DIR" ]; then
        rm -rf "$DIR"
        echo "Deleted $DIR"
    else
        echo "$DIR does not exist"
    fi
done
