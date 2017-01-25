#!/bin/bash
echo enter your percentage
read p
case $p in
	[0-9]|[0-3][0-9]|[4][0-4]) echo Zero Division;;
	[4][5-9]|[5][0-9]) echo Third Division ;;
	[6][0-9]|[7][0-5]) echo Second Division ;;
	[7][6-9]|[8-9][0-9]|[1][0][0]) echo Hurray you pass 1st division ;;
	*) echo "Wrong choice"
esac
