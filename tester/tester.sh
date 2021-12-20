#!/bin/bash

Blue='\033[0;34m'
Purple='\033[0;35m'
Cyan='\033[0;36m'
BYellow='\033[1;33m'
white='\033[1;37m'
green='\033[0;32m'
red='\033[0;31m'
yell='\033[0;33m'
reset='\033[0m'

if [ $# -lt 2 ] | [ $# -gt 3 ]
then
    if [ $# -gt 3 ]
    then
        echo -e "${red}many args${reset}" >&2; exit
    else
        echo -e "${red}few args${reset}" >&2 ; exit
    fi
fi

if ! [ -f "$1" ]
then
	echo -e "${red}Error : ${white}push_swap ${reset}" >&2 ; exit
fi

if ! [ -f "$2" ]
then
    echo -e "${red}Error : ${white}checker ${reset}" >&2 ; exit
fi 

if [ $# -eq 3 ]
then
	re='^[0-9]+$'
	if ! [[ $3 =~ $re ]] ; then
	   echo -e "${red}Error: ${white}Arg3 Not a number" >&2; exit 1
	fi
fi

test_100 () {
	if [ "$2" == "2" ]
	then
		if [ $1 -le 1 ]
        then
            echo -en "${green}$1"
        else
            echo -en "${red}$1"
		fi
	else if [ "$2" == "3" ]
	then
		if [ $1 -le 3 ]
        then
            echo -en "${green}$1"
        else
            echo -en "${red}$1"
		fi
	else if [ "$2" == "5" ]
	then
		if [ $1 -le 12 ]
		then
			echo -en "${green}$1"
		else
			echo -en "${red}$1"
		fi
	else if [ "$2" == "100" ]
	then
		if [ $1 -le 700 ]
		then
			echo -en "${green}$1"
		else if [ $1 -le 900 ]
			then
				echo -en "${yell}$1"
		else if [ $1 -le 1100 ]
			then
				echo -en "${Cyan}$1"
		else if [ $1 -le 1300 ]
			then
				echo -en "${Purple}$1"
		else if [ $1 -le 1500 ]
			then
				echo -en "${Blue}$1"
		else
			echo -en "${red}$1"
		fi fi fi fi fi
	else
		if [ $1 -le 5500 ]
        then
            echo -en "${green}$1"
        else if [ $1 -le 7000 ]
            then
                echo -en "${yell}$1"
        else if [ $1 -le 8500 ]
            then
                echo -en "${Cyan}$1"
        else if [ $1 -le 10000 ]
            then
                echo -en "${Purple}$1"
        else if [ $1 -le 11500 ]
            then
                echo -en "${Blue}$1"
        else
            echo -en "${red}$1"
        fi fi fi fi fi 
	fi fi fi fi
}

if [ $# -eq 2 ] 
then
	times=1
else if [ $3 -lt 1 ]
then
	times=1
else
	times=$3
fi fi 

rm -rf tests
mkdir -p tests
echo -e "\n${green}<____________________________________Tester___________________________________>${reset}"
echo -e "\n${white}Rmandom of${red} Two${white} Numbers :${reset}"
mkdir -p tests/gen_2
avr=0
for ((j = 0 ; j < times ; j++ ))
do

	rand=($(seq 0 100 | shuf))
	for ((i = 0 ; i < 2 ; i++ ))
	do
	    echo -n "${rand[i]} " >> tests/gen_2/gen_2_$j.txt
	done
	res=$(./$1 `cat tests/gen_2/gen_2_$j.txt` | ./$2 `cat tests/gen_2/gen_2_$j.txt`)
	count=($(./$1 `cat tests/gen_2/gen_2_$j.txt` | wc -l))
	echo -en "${yell}checher ${green}${res} : ${reset}"
	test_100 "$count" 2
	echo -e "${reset} Instruction."
	avr=$(($avr + $count))
done
echo -en "${BYellow}average : "
test_100 "$(($avr / $times))"
echo ""

avr=0
echo -e "\n${white}Random of ${red}3 ${white}Numbers :${reset}"
mkdir -p tests/gen_3
for ((j = 0 ; j < times ; j++ ))
do
	rand=($(seq 0 100 | shuf))
	for ((i = 0 ; i < 3 ; i++ ))
	do
	    echo -n "${rand[i]} " >> tests/gen_3/gen_3_$j.txt
	done
	res=$(./$1 `cat tests/gen_3/gen_3_$j.txt` | ./$2 `cat tests/gen_3/gen_3_$j.txt`)
	count=($(./$1 `cat tests/gen_3/gen_3_$j.txt` | wc -l))
	echo -en "${yell}checher ${green}${res} : ${reset}"
	test_100 "$count" 3
	echo -e "${reset} Instruction."
	avr=$(($avr + $count))
done
echo -en "${BYellow}average : "
test_100 "$(($avr / $times))"
echo ""

avr=0
echo -e "\n${white}Random of ${red}5 ${white}Numbers :${reset}"
mkdir -p tests/gen_5
for ((j = 0 ; j < times ; j++ ))
do
	rand=($(seq 0 100 | shuf))
	for ((i = 0 ; i < 5 ; i++ ))
	do
	    echo -n "${rand[i]} " >> tests/gen_5/gen_5_$j.txt
	done
	res=$(./$1 `cat tests/gen_5/gen_5_$j.txt` | ./$2 `cat tests/gen_5/gen_5_$j.txt`)
	count=($(./$1 `cat tests/gen_5/gen_5_$j.txt` | wc -l))
	echo -en "${yell}checher ${green}${res} : ${reset}"
	test_100 "$count" 5
	echo -e "${reset} Instruction."
	avr=$(($avr + $count))
done
echo -en "${BYellow}average : "
test_100 "$(($avr / $times))"
echo ""

avr=0
echo -e "\n${white}Random of ${red}100 ${white}Numbers :${reset}"
mkdir -p tests/gen_100
for ((j = 0 ; j < times ; j++ ))
do
	rand=($(seq 0 200 | shuf))
	for ((i = 0 ; i < 100 ; i++ ))
	do
	    echo -n "${rand[i]} " >> tests/gen_100/gen_100_$j.txt
	done
	res=$(./$1 `cat tests/gen_100/gen_100_$j.txt` | ./$2 `cat tests/gen_100/gen_100_$j.txt`)
	count=($(./$1 `cat tests/gen_100/gen_100_$j.txt` | wc -l))
	echo -en "${yell}checher${green}${res} : ${reset}"
	test_100 "$count" 100
	echo -e "${reset} Instruction."
	avr=$(($avr + $count))
done
echo -en "${BYellow}average : "
test_100 "$(($avr / $times))"
echo ""

avr=0
echo -e "\n${white}Random of ${red}500 ${white}Numbers :${reset}"
mkdir -p tests/gen_500
for ((j = 0 ; j < times ; j++ ))
do
	rand=($(seq 0 600 | shuf))
	for ((i = 0 ; i < 500 ; i++ ))
	do
	    echo -n "${rand[i]} " >> tests/gen_500/gen_500_$j.txt
	done
	res=$(./$1 `cat tests/gen_500/gen_500_$j.txt` | ./$2 `cat tests/gen_500/gen_500_$j.txt`)
	count=($(./$1 `cat tests/gen_500/gen_500_$j.txt` | wc -l))
	echo -en "${yell}checher ${green}${res} : ${reset}"
	test_100 "$count" 500
	echo -e "${reset} Instruction."
	avr=$(($avr + $count))
done
echo -en "${BYellow}average : "
test_100 "$(($avr / $times))"
echo ""
echo ""
