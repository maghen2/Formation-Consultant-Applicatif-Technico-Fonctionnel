#!/usr/bin/bash
# $0 #chemin du script appelé
#echo $# #nombre d'arguments
# $@ ou $* #liste des arguments
# $? #savoir si la derniere commande a été un succes
# $USER #affiche le nom d'utisateur

# SCRIPT DE CALCUL
#on demande à l'utilisateur de choisir
printf '1) Si vous voulez faire une somme entrez la lettre "s" \n2) Si vous voulez faire une moyenne entrez la lettre "m"\nAlors "s" ou "m"?\n'
read -p '' choix 
 #on verifie le choix
if [ "$choix" = "s" ]
then 
	source somme.sh
elif [ "$choix" = "m" ]
 then source moyenne.sh
else echo 'Vous devez choisir entre "somme" ou "moyenne"'
fi

