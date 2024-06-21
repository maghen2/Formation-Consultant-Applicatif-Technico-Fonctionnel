#!/bin/bash
nomrep=$1  # nom du repertoire
nbrep=$2  # nombre de repertoire
nomfichier=$3  # nom du fichier
nbrfichier=$4  # nombre de fichier

# commande d'aide.   mettre des commentaires 

echo $#
echo $@
echo $0

if [ "$1" == "-h" ]; then
  echo "Utilisation : $0 nomrep nbrep nomfichier nbrfichier"
  echo " nbrep et nbrfichier doivent être un nombre"
  exit 0
fi



#test
re='^[0-9]+$'
if ! [[ $2 =~ $re ]] ; then
   echo "error:  $2 is Not a number" >&2; exit 1
fi
re='^[0-9]+$'
if ! [[ $4 =~ $re ]] ; then
   echo "error: $4 is Not a number" >&2; exit 1
fi




if ! [ "$5" == "-c" ]
then
    for ((i=1;i<=$2;i=i+1));
    do 
            mkdir $1$i;
            cd $1$i;
            for ((j=1; j<=$4;j++));
            do 
            touch $3_$j;
        done
        cd ..
    done

else [ "$5" == "-c" ]
    for ((i=1;i<=$2;i=i+1));
    do 
            rm -Rf $1$i;
            cd $1$i;

    done

fi
