#!/bin/bash
read filename
list=( $(ls -l $filename) )
size=${list[4]}
echo "Size of $filename is: $size bytes"