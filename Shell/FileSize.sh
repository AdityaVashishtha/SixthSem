#!/bin/bash
fileSize() {
    list=( $(ls -l $1) )
    size=${list[4]}
    echo "Size of $1 is: $size bytes"
}
read filename
fileSize $filename