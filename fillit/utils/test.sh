#!/bin/bash

LOGS=./logs.txt
VALID=./maps_fillit/valid/*
INVALID=./maps_fillit/invalid/*

{ //echo -e '\nMAKE TEST\n'

//make
//make clean

echo -e '\nNORMINETTE\n'

norminette -R CheckForbiddenSourceHeader ../project

echo -e '\nVALID MAPS CHECKING\n'

for file in $VALID
do
	echo -e $(basename $file)'\n'
	../project/fillit $file
	echo -e '\n>>>>>>>>>>>>>>>>>\n'
done

echo -e 'INVALID MAPS CHECKING\n'

for file in $INVALID
do
	echo -e $(basename $file)'\n'
	../project/fillit $file
	echo -e '\n>>>>>>>>>>>>>>>>>\n'
done } > $LOGS 2>&1

echo -e 'END TESTS\ncheck logs.txt for results'
