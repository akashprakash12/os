#! /bin/bash
if [ "$#" -ne 2 ];then
echo "usage: $0<num1><num2>"
exit 1
fi
num1="$1"
num2="$2"
sum=$((num1+num2))
product=$((num1*num2))
if [ "$num2" -eq 0 ];then
echo "can't devide by zero"
exit 1
fi
quatient=$(bc <<< "scale = 2;$num1/$num2")

echo "sum $sum"
echo "product $product"
echo "quatient $quatient"
