#!/bin/bash

# Colors
NC='\033[0m'
GREEN='\033[0;32m'
LGREEN='\033[1;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
LCYAN='\033[1;36m'
YELLOW='\033[0;33m'

HEADER_COLOR=$LCYAN
INPUT_COLOR=$CYAN

make -C ex00 re
make -C ex01 re
make -C ex02 re

EX00=ex00/megaphone
EX01=ex01/
EX02=ex02/

TEST_DIR=tests
EX00_TESTS=$TEST_DIR/ex00
EX01_TESTS=$TEST_DIR/ex01
EX02_TESTS=$TEST_DIR/ex02

# EX00 TESTS

echo -e ${HEADER_COLOR}"\nEX00 TESTS\n"${NC}

while read -r line
do
	echo -e ${INPUT_COLOR}in: "$line"${NC}
	eval $EX00 "$line" | cat -e
	#leaks -q --atExit -- $EX00 $line
	echo ""
done < $EX00_TESTS
