#!/bin/bash

frequency() {
    output=`tr -s ' ' '\n' < $1 | grep -c $2`
    echo $output
}
frequency $1 $2