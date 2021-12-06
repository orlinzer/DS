#!/bin/bash

# Get Absolute old path
OLD_PATH=`pwd`

# Change to this directory
cd $(dirname "$0")

# Building
echo "Building"

# Return to the old path
cd "$OLD_PATH"
