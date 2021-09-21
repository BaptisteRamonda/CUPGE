#! /bin/sh
#Autre Solution Primitive : grep 'linfg' liste.txt | cut -f 1 -d " " > listeNoms.txt
echo "Il y a `tail -n +6 liste.txt | cut -f1 -d " " | grep ".\{'$1'\}" | grep -v ".\{'$2'\}" | wc -l ` étudiants dont le nom comporte entre $1 et $2 caracteres."
