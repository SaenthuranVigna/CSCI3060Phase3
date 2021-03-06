#!/bin/sh
chdir testers
for i in *.txt
do
  echo "running test $i"
  .././test $i >>../output/output$i.atf
done