#!/bin/bash

factorial() {
    if [ "$1" -le "1" ] 
    then
        echo 1
    else
        a=`expr $1 - 1`
        num=`factorial $a`
        b=`expr $num \* $1`
        echo "$b"
    fi
}

echo "Enter number :"
read num
factorial $num
