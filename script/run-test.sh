#!/bin/bash

# Get Absolute old path
OLD_PATH=`pwd`

# Change to this directory
cd $(dirname "$0")

# Running Tests:
echo "Running Tests:"
../bin/test/testAVLTree
../bin/test/testKeyValue

# Return to the old path
cd "$OLD_PATH"
