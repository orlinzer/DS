#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")" || exit

# Clean Tests:
echo "Clean CLIs:"
rm -rf "../bin/cli/"

# Return to the old path
cd "$OLD_PATH" || exit
