#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")" || exit

# Build Tests:
echo "Build Tests:"
if [ -d "../src/test/" ]; then
  mkdir -p "../bin/test/"
fi
g++ -std="c++11" -o "../bin/test/AVLTree.test" -I "../include" "../src/test/AVLTree.test.cpp"
g++ -std="c++11" -o "../bin/test/KeyValue.test" -I "../include" "../src/test/KeyValue.test.cpp"

# Return to the old path
cd "$OLD_PATH" || exit
