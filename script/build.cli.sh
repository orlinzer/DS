#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")" || exit

# Build CLIs:
echo "Build CLIs:"
g++ -std="c++11" -o "../bin/cli/AVLTree.cli" -I "../include" "../src/cli/AVLTree.cli.cpp"
g++ -std="c++11" -o "../bin/cli/KeyValue.cli" -I "../include" "../src/cli/KeyValue.cli.cpp"

# Return to the old path
cd "$OLD_PATH" || exit
