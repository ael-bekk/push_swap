#!/bin/bash 

red='\033[0;31m'
reset='\033[0m'

if [ $# -ne 3 ]
then
	if [ $# -gt 3 ]
	then
		echo -e "${red}many args${reset}"; exit
	else
		echo -e "${red}few args${reset}" ; exit
	fi
fi

rand=($(seq $1 $2 | shuf))

count=0;
for i in ${rand[*]}
do
	let "count=count+1"
done

if [ $3 -lt $count ]
then
	let "count=$3"
fi

rm -fr gen.txt

for ((i = 0 ; i < $count ; i++ ))
do 
	echo -n "${rand[i]} " >> gen.txt
done
