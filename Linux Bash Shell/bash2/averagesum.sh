#!/usr/bin/bash
# $0 #chemin du script appelé
#echo $# #nombre d'arguments
# $@ ou $* #liste des arguments
# $? #savoir si la derniere commande a été un succes
# $USER #affiche le nom d'utisateur

# CALCUL DE LA SOMME
function somme(){
for i in "$@" # on obtient la liste des arguments en i
do 
	if ! [[ $i =~ $re ]]
	then
	 echo  "Le paramètre \"$i\" doit être un entier" 
 	 exit 1
	else
	j=$(echo "$j+$i" |bc -l) # on obtient la somme
	fi
done
}


# CALCUL DE LA MOYENNE
function moyenne(){
somme $@ #on appelle la fonction somme et on lui passe les paramètres
j=$(echo "$j/$#" |bc -l) #on calcul la moyenne en affichant les décimales
}

# SCRIPT DE CALCUL
re="^[0-9]+$"
j=0
#on demande à l'utilisateur de choisir OBLIGATOIREMENT entre s et m
printf '1) Si vous voulez calculer une somme entrez la lettre "s" \n2) Si vous voulez calculer une moyenne entrez la lettre "m"\nAlors "s" ou "m"?\n'
read -p '' choix 
while [ "$choix" != "s" -a "$choix" != "m" ]
do
  printf 'Erreur: vous devez choisir entre "somme" ou "moyenne"\nAlors "s" ou "m"?\n'
	read -p '' choix 
done
 #on verifie le choix
if [ "$choix" = "s" ]
then 
	somme $@ # on apppelle la fonction somme et on lui transmet les paramètres saisis par l'utilisateur
	echo "La somme est $j " #on affiche le resultat
elif [ "$choix" = "m" ]
 then 
 	moyenne $@  # on apppelle la fonction moyenne et on lui transmet les paramètres saisis par l'utilisateur
 	echo "La moyenne est $j " #on affiche le resultat
else echo 'Vous devez choisir entre "somme" ou "moyenne"'
fi

#deplacement d'un fichier
mv fichier.csv bash2/
#sed et head, deux commandes pour afficher les n premieres ligne
sed -n 1,5p fichier.csv
head -n 5 fichier.csv | cut -f 1 -d ,
sed -n 1,$4p $2
#recuperer le contenu d'une fonction dans une variable
colonne=`sed -n 1,1p insurance.csv`
colonne=$(sed -n 1,1p fichier.csv)
{$colonne}

# Comment se connecter à un serveur distant et effectuer des manipulation de fichiers
chmod 400 privkey.pem # Autoriser le telechargement du fichier
ssh -i "privkey.pem" ubuntu@ec2-13-38-75-162.eu-west-3.compute.amazonaws.com # se connecter à la console d'un serveur distant
scp -i "privkey.pem" -r fichier1.csv ubuntu@ec2-13-38-75-162.eu-west-3.compute.amazonaws.com:/home/ubuntu/group3/fichier1.csv # copier un fichier/dossier sur un serveur distant

scp -i "bash2/privkey.pem" -r bash2/ ubuntu@ec2-13-38-75-162.eu-west-3.compute.amazonaws.com:/home/ubuntu/group3/

chmod +r group3
1 - première étape : envoyer le contenu de son script dans un fichier
2 - lire la commande scp et ssh
vous avez déjà un exemple ssh ci dessus


# afficher une colonne dont le nom est passé en paramètre et le convertir en numero 
cat $2 | awk -F"," '{print $1 }' | head -$5
cat insurance.csv | awk -F"," '{print $1 }' | head -6


