#!/bin/sh
string=""
read string
output=`echo $string | wc -c`
echo $(($output-1))