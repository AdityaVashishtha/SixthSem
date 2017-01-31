#!/bin/bash
read file
[ -r $file ] && b="yes" || b="no"
echo file is readable : $b
[ -w $file ] && b="yes" || b="no"
echo file is writable : $b
[ -x $file ] && b="yes" || b="no"
echo file is executable : $b
