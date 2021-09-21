#! /bin/sh
mkdir REP
ls *.txt *.sh>liste.txt
cp liste.txt REP/liste.txt
cp `tail -n 1 liste.txt` REP
rm liste.txt
cd REP
rm liste.txt
