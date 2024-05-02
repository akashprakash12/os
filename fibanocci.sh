# !/bin/bash
function fibano(){
	limit=$1
	a=0
	b=1
	echo "fibanocci series"
	echo -n "$a ,$b"
	for ((i=0;i<limit-2;i++ ))
	do
	c=$((a+b))
	echo -n ",$c"
	a=$b
	b=$c
	done
	


}
echo "how many number of terms"
read n
fibano $n
