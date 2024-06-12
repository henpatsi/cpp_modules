#!/bin/bash

make

run_test()
{
	echo "./convert $INPUT"
	./convert $INPUT
	echo
}

INPUT=a
run_test
INPUT=42
run_test
INPUT=123.123
run_test
INPUT=22f
run_test
INPUT=nanf
run_test
INPUT=-inff
run_test
INPUT=+inff
run_test
INPUT=nan
run_test
INPUT=-inf
run_test
INPUT=+inf
run_test

INPUT=abc
run_test
INPUT=abf
run_test
INPUT=12.a
run_test
INPUT=10ff
run_test
INPUT=1a2.0
run_test
INPUT=...
run_test
