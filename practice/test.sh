#!/bin/bash

cd fold
for i in *
do
	wc -l "$i"
done
