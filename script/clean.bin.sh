#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")" || exit

# Clean Objects:
echo "Clean Binary:"
rm -rf "../bin/"

# Return to the old path
cd "$OLD_PATH" || exit
