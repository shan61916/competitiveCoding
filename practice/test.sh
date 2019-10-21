#!/bin/bash

cd fold
for i in *
do
	if test -f "$i"
	then
		echo "$i is a file with words :"
	    wc -l "$i"
	else
		echo "$i is a directory"
	fi		
done

