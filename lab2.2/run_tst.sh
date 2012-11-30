#!/bin/sh
log=$0.log
echo -n 'LOTS_FREE:' > $log; for k in {1..15}; do echo -ne "\t   $k" >> $log; done; for i in {1..15}; do echo -en "\nMIN_FREE $i:" >> $log; for j in {1..15}; do ./tst.sh $i $j | grep -v output |sed s/^$// |xargs echo -ne "\t" >> $log ; done; done

