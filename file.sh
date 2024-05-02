#!/bin/bash
if [ "$#" -ne 1 ];then
	echo "usage $0<file>"
	exit 1
fi
file="$1"
if [ ! -e "$file" ];then
	echo "file not found"
	exit 1
fi
echo "content of file $file"
cat "$file"
