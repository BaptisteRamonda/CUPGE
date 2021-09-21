#! bin/sh/
cat f_anglais.txt | while read ligne
do
    for mot in $ligne
    do
        motTraduit=`grep "^$mot" dico.txt | cut -f2 -d " "`
        phrase="$phrase $motTraduit"
    done
    echo "$phrase" >> f_francais.txt
    phrase=""
done
