#!/bin/bash

# Colors
NC='\033[0m'
GREEN='\033[0;32m'
LGREEN='\033[1;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
LCYAN='\033[1;36m'
YELLOW='\033[0;33m'

INPUT_COLOR=$CYAN

make

TEST_INPUT_FILE=./test_inputs

while read -r line
do
	echo -e ${INPUT_COLOR}echo "./convert $line"${NC}
	./convert $line
	echo
done < $TEST_INPUT_FILE
