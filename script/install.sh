#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")/.." || exit

# "local" | "user" | "global"
MODE="local"

# Install:
echo "Install:"
if [[ $MODE == "global" ]]; then
  ./script/install.global.sh
elif [[ $MODE == "user" ]]; then
  ./script/install.user.sh
else #
  ./script/install.local.sh
fi

# Return to the old path
cd "$OLD_PATH" || exit
