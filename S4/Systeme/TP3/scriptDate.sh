#! /bin/sh
#On traduit le jour en français
Day=`date -R | cut -f1 -d ","`
case $Day in
    "Mon")
        Jour="Lundi"
        ;;
    "Tue")
        Jour="Mardi"
        ;;
    "Wed")
        Jour="Mercredi"
        ;;
    "Thu")
        Jour="Jeudi"
        ;;
    "Fri")
        Jour="Vendredi"
        ;;
    "Sat")
        Jour="Samedi"
        ;;
    "Sun")
        Jour="Dimanche"
        ;;
    "*")
        Jour="ERREUR, JOUR INVALIDE"
        ;;
esac
#On traduit le mois en français
Month=`date -R | cut -f3 -d " "`
case $Month in
    "Jan")
        Mois="Janvier"
        ;;
    "Feb")
        Mois="Fevrier"
        ;;
    "Mar")
        Mois="Mars"
        ;;
    "Apr")
        Mois="Avril"
        ;;
    "May")
        Mois="Mai"
        ;;
    "Jun")
        Mois="Juin"
        ;;
    "Jul")
        Mois="Juillet"
        ;;
    "Aug")
        Mois="Aout"
        ;;
    "Sep")
        Mois="Septembre"
        ;;
    "Oct")
        Mois="Octobre"
        ;;
    "Nov")
        Mois="Novembre"
        ;;
    "Dec")
        Mois="Decembre"
        ;;
    "*")
        Mois="ERREUR MOIS INVALIDE"
        ;;
esac
#On affiche la date en français
echo "$Jour `date -R | cut -f2 -d " "` $Mois `date -R | cut -f4,5 -d " "`"   
