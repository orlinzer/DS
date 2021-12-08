#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")" || exit

# Clean Tests:
echo "Clean Tests:"
rm -rf "../bin/test/"

# Return to the old path
cd "$OLD_PATH" || exit
