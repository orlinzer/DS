#!/bin/bash

# To link the library
# gcc src/main.c -L"lib" -l"DS" -o bin/main

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")" || exit

# Build Libraries:
echo "Build Libraries:"
if [ -d "../obj/" ]; then
  # Make lib diractory
  mkdir -p "../lib"

  # Build a static library
  ar rcs "../lib/libDS.a" "../obj/*.o"

  # Build a shared library
  gcc -shared "../obj/*" -o "../lib/libDS.so"
fi

# Return to the old path
cd "$OLD_PATH" || exit
