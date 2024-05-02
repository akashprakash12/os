#!/bin/bash
if [ "$#" -ne 1 ];then
echo "usage. &0<directory>"
exit 1
fi
	directory="$1"
		if [ !  -d "$directory" ];then
		echo "directory does not exist"
		exit 1
fi
	zip -r "$directory zip" "$directory"
	echo "directory" $directory" compressed into $directory.zip"
	 
