#!/bin/bash

# Get Absolute old path
OLD_PATH=`pwd`

# Change to this directory
cd $(dirname "$0")

# Build Tests:
echo "Build Tests:"
g++ -std="c++11" -o "../bin/test/testAVLTree" -I "../include" "../src/test/testAVLTree.cpp"
g++ -std="c++11" -o "../bin/test/testKeyValue" -I "../include" "../src/test/testKeyValue.cpp"

# Return to the old path
cd "$OLD_PATH"
