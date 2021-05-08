#!/bin/bash
# Bikrsm Kohli (bsk4uaa)
# averagetime.sh

read input
if [ $input == "quit" ];
then
	exit
fi

sum=0

for((i=0; i<=4; i++));
do
	runTime=`./a.out $input`
	echo $runTime
	sum=`expr $runTime + $sum`
done

avg=`expr $sum / 5`
echo "$avg"
