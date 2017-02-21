#!/bin/bash
printenv
PATH=$PATH:$1
export PATH
echo -e "______NEW PATH Variable Value_____"
echo $PATH