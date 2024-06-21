#!/usr/bin/bash
# $0 #chemin du script appelé
#echo $# #nombre d'arguments
# $@ ou $* #liste des arguments
# $? #savoir si la derniere commande a été un succes
# $USER #affiche le nom d'utisateur


# CALCUL DE LA MOYENNE
re="^[0-9]+$"
j=0
for i in "$@" # on obtient la liste des argent en i
do 
	if ! [[ $i =~ $re ]]
	then
	 echo  "Le paramètre \"$i\" doit être un entier" 
 	 exit 1
	else
	j=$(echo "$j+$i" |bc -l) # on obtient la somme
	fi
done
j=$(echo "$j/$#" |bc -l) #on clacul la moyenne en affichant les décimales
 
echo "La moyenne est $j " #on affiche le resultat


