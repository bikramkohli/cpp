#!/bin/bash

echo 'input dictionary'
read dictionary

echo 'input grid'
read grid

r1=`./a.out $dictionary $grid tail -1`
r2=`./a.out $dictionary $grid tail -1`
r3=`./a.out $dictionary $grid tail -1`
r4=`./a.out $dictionary $grid tail -1`
r5=`./a.out $dictionary $grid tail -1`

total=$((r1 + r2 + r3 + r4 + r5))
echo $((total))

