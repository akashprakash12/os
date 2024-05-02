# !bin/bash
echo "1 currently logged user and his logname"
whoami
echo "2 current shell"
echo $SHELL
echo "3 home directory"
echo $HOME
echo "4 operating system type"
echo $OSTYPE
echo "5 current path"
echo $PATH
echo "6 current working directory"
pwd
echo "7 number of user currently logger in" 
who -a
echo "8 os version,relese Number,kernal version"
uname -a
echo "9 show all available shell"
cat /etc/shells
echo "10 cpu information and speed"
lscpu
echo "11 memmory information "
cat /proc/meminfo
echo "12 hard disk information"
df -H
echo "13 file mounteds"
cat /proc/mounts
