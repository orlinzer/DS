#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")" || exit

# Building
echo "Building"
if [ -d "../src/" ]; then
  mkdir -p "../bin/"
fi
./build.test.sh
./build.cli.sh

# Return to the old path
cd "$OLD_PATH" || exit
