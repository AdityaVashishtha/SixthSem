#!/bin/bash
read dirname
list=`ls -C $dirname`
for i in $list
do
    echo $i
done