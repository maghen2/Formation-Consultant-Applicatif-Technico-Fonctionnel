#$1 #file Name
#$2 #col Name
#$3 #head Number of lignes
#./script9.sh insurance.csv age 12
entete=$(head -n 1 $1 | sed 's/\s\+$//') #On recupere la ligne d'entête du fichier en supprimant les espaces de début et fin de ligne
IFS=',' read -a listCol <<< "$entete" #on decoupe la ligne d'entête du fichier pour stockquer chaque colonne du csv dans une colonne de tableau
numCol=-1 #On intialise la variable
#On retrouve le numéro de la colonne à partir de sa valeur et on le stock dans numCol
for ((i=0; ${#listCol[@]}-i; i++))
do #echo "$i) ${listCol[$i]}"
if [ "${listCol[$i]}" = "$2" ]
then	
numCol=$(($i+1))
#echo "numCol=$numCol"
break
fi
done

#On verifie le numéro de colonne et affiche le message approprié
if [ $numCol -gt 0 ]
then
head -n $3 $1 |  cut -f $numCol -d ,
else
printf "La colonne $2 que vous avez inquiquée au script $0 n'existe pas dans le fichier $1\nMerci de choisir le nom de votre colonne parmis l'une des ${#listCol[@]} valeurs ci-dessous :\n"
echo $entete
fi

