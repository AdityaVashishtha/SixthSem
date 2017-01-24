#!/bin/bash
read filename
output=$(tail -3 $filename)
echo $output