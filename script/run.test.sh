#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")" || exit

# Running Tests:
echo "Running Tests:"
../bin/test/AVLTree.test
../bin/test/KeyValue.test

# Return to the old path
cd "$OLD_PATH" || exit
