#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")" || exit

# Clean:
echo "Clean:"
# ./clean.test.sh
# ./clean.cli.sh
./clean.obj.sh
./clean.bin.sh

# Return to the old path
cd "$OLD_PATH" || exit
