#!/bin/sh
string=""
read string
output=`echo $string | wc -c`
if [ $(($output-1)) -gt 10 ]
then 
echo String Greater than 10
else 
echo String is Less than 10
fi

