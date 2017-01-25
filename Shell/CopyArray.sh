#!/bin/bash
echo Enter number of elements
read n
for i in $(seq 1 $n)
do 
read a["$i"]
b["$i"]="${a["$i"]}"
done

for i in $(seq 1 $n)
do 
echo "${b["$i"]}"
done
