#!/bin/bash
# Bikrsm Kohli (bsk4uaa)
# averagetime.sh

read dictionary
read grid

r1=`./a.out "$dictionary" "$grid" | tail -1`
r2=`./a.out "$dictionary" "$grid" | tail -1`
r3=`./a.out "$dictionary" "$grid" | tail -1`
r4=`./a.out "$dictionary" "$grid" | tail -1`
r5=`./a.out "$dictionary" "$grid" | tail -1`


total=`expr $r1 + $r2`
total=`expr $total + $r3`
total=`expr $total + $r4`
total=`expr $total + $r5`

avg=`expr $total / 5`
echo "$avg"

