#!/bin/bash

# Get Absolute old path
OLD_PATH=$(pwd)

# Change to this directory
cd "$(dirname "$0")" || exit

# Build Tests:
echo "Build Tests:"
if [ -d "../src/test/" ]; then
  mkdir -p "../bin/test/"
fi

# inotifywait -m -e modify "../src/test/AVLTree.test.cpp"
# ../dependencies/inotify-win/inotifywait -m -e modify "../src/test/AVLTree.test.cpp"
g++ -std="c++11" -o "../bin/test/AVLTree.test" -I "../include" "../src/test/AVLTree.test.cpp" || exit

# if [ -f "../bin/test/AVLTree.test" ]; then
  # if ( `date -r "../bin/test/AVLTree.test" "+%s"` < `date -r "../src/test/AVLTree.test.cpp" "+%s"`); then
    # g++ -std="c++11" -o "../bin/test/AVLTree.test" -I "../include" "../src/test/AVLTree.test.cpp" || exit
#   fi
# else
    # g++ -std="c++11" -o "../bin/test/AVLTree.test" -I "../include" "../src/test/AVLTree.test.cpp" || exit
# fi
g++ -std="c++11" -o "../bin/test/KeyValue.test" -I "../include" "../src/test/KeyValue.test.cpp" || exit

# Return to the old path
cd "$OLD_PATH" || exit
