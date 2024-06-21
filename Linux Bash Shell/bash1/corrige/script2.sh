#!/usr/bin/bash

# # [ $# -eq 0 ] && { echo "Usage: $0 nomdir nbdirs nomfichier nbfichiers"; exit 1; }
Help()
{
   echo "Usage: $0 nomdir nbdirs nomfichier nbfichiers"
   echo
   echo "nomdir nom du répertoire"
   echo "nbdirs un nombre > 0: nomre de répertoires"
   echo "nomfichier nom de base du fichier"
   echo "nbfichiers nombre de fichier"
   echo
}

while getopts "h:" option; do
   case $option in
      h) Help
         exit;
   esac
done


numerique='^[0-9]+$'

if ! [[ "$2" =~ $numerique ]]; then
    echo "le paramètre 2 n'est pas un nombre > 0"
    exit 1
fi

if ! [[ $4 =~ $numerique ]]; then
    echo "le paramètre 4 n'est pas un nombre > 0"
    exit 1
fi

for (( i=1; i <= $2 ; i++ ))
do

# Becareful of Hardcoded value.  $HOME
    if [ ! -d $HOME/bin/${1}${i} ]; then
        mkdir $HOME/bin/${1}${i} 
    fi

    for (( j=1; j <= $4 ; j++ ))

    do

        if [ ! -f $HOME/bin/${1}${i}/${3}${j} ]; then
 $HOME/bin/${1}${i}/${3}${j}
        fi

    done
done
