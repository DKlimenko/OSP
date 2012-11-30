#!/bin/sh
touch memory.c && make MIN="MIN_FREE=$1" LOTS="LOTS_FREE=$2" &> /dev/null  && ./OSP par.high -d &&  cat simulation.run | egrep "referenc|of pagefault" | awk '{print $NF}' | tail -n3 | head -n2| while read l; do echo -n "$l "; done | sed s', ,\/,' | tr -d [:cntrl:] | xargs echo 'scale=4;' |bc
