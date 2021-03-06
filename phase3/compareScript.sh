#!/bin/sh
chdir testers
for i in *
do
  echo "comparing test $i"
  diff ../output/output$i.atf ../output/$i.etf
done