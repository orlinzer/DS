#!/bin/bash

CALL="$0"

if [[ ! -z "$1" ]] ; then
  CALL="$1"
fi

# Get Absolute path
WD=$(dirname "$CALL")
WD=$(cd "$WD" && pwd)

if [[ -z $WD ]] ; then
  exit 1
fi

echo "$WD"