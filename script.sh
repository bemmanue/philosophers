#!/bin/bash

NUMBER=70
T_LIVE=100
T_EAT=100
T_SLEEP=100
COUNT=0

for i in {1..1000}
do
	if ./philo "$NUMBER" "$T_LIVE" "$T_EAT" "$T_SLEEP" | grep -q dead
	then
		echo "someone died!"
		echo $NUMBER $T_LIVE $T_EAT $T_SLEEP
		echo $((COUNT=$((COUNT + 1))))
	else
		echo "lived succesfully!"
		echo $COUNT $NUMBER $T_LIVE $T_EAT $T_SLEEP
	fi
done
echo $COUNT
