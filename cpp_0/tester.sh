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

make -C ex00
make -C ex01
make -C ex02

EX00=ex00/megaphone
EX01=ex01/
EX02=ex02/tests

TEST_DIR=tests
EX00_TESTS=$TEST_DIR/ex00

# EX00 TESTS

echo -e ${HEADER_COLOR}"\nEX00 TESTS\n"${NC}

while read -r line
do
	echo -e ${INPUT_COLOR}in: "$line"${NC}
	eval $EX00 "$line" | cat -e
	#leaks -q --atExit -- $EX00 $line
	echo ""
done < $EX00_TESTS

echo -e ${HEADER_COLOR}"\nEX02 TESTS\n"${NC}

$EX02 | awk '{print $2}' > out1
cat ex02/19920104_091532.log | awk '{print $2}' > out2
DIFF=$( diff out1 out2 )
WC_DIFF=$( diff out1 out2 | wc -l )
if [ $WC_DIFF -eq 0 ]
then
	echo -e ${GREEN}"OK"${NC}
else
	echo -e ${RED}"KO"${NC}
	echo "$DIFF"
fi

rm -f out1
rm -f out2

echo ""