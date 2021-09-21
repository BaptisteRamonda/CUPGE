#! /bin/sh
echo "Il y a `ls -al | grep '.txt' | wc -l` fichier(s) dont le nom se termine par .txt"
echo "Il y a `ls -al | grep '.sh' | wc -l` fichier(s) dont le nom se termine par .sh"
echo "Il y a `ls -d .* | grep '' | wc -l` fichier(s)/dossier(s) cache(s)"
