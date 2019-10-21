# !/bin/bash

echo "Enter a number"
read n
ct=0

for((c = 1; c <= $n; c++))
do
	if(($n % $c == 0))
	then
		ct=$((ct+1))
	fi
done
if(($ct == 2))
then
	echo "$n is a prime"
else
	echo "$n is not prime"
fi


