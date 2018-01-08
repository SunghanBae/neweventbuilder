#!/bin/bash
brips=1193
eurica=1408
aida=1208

for((i=1;i<8;i++))
do

#name=R${aida}_${i}_packed_eventbuild

#if [ -e $AIDADIR/$name.root ]; then
#        echo "$name.root exist"
#else

./newevent $aida $i $brips $eurica
#./newevent $aida $i $eurica
#fi

done

