#!/usr/bin/bash
#/home/user/bin

#
#VARIABLES ET TABLEAU
#
$0 #chemin du script appelé
$# #nombre d'arguments
$@ ou $* #liste des arguments
$? #savoir si la derniere commande a été un succes
$PATH, $HOME # affiche variable d'environement
export PATH=$PATH:/opt/group3 #export rend la variable globale set personnal path of envionement
env #affiche toutes les variables d'environement
$1, $2, $3, ...., $n #récupération des n variables passées en paramètres au script
seq 1 4 #Cette fonction prend en arguments deux entiers et renvoie la liste de tous les entiers compris entre ces bornes.

#PROGRAMMATION BASH/FLUX ET REDIRECTIONS
com > fic #redirige la sortie standard de com dans le fichier fic,
com 2> fic #redirige la sortie des erreurs de com dans le fichier fic,
com 2>&1 #redirige la sortie des erreurs de com vers la sortie standard de com,
com < fic #redirige l'entrée standard de com dans le fichier fic,
com1 | com2 #redirige la sortie standard de la commande com1 vers l'entrée standard de com2.
com1 |& com2 #branche ("connecte" selon le manuel bash) la sortie standard et la sortie d'erreur de com1 sur l'entrée de com2

# Tests logique, sur les chaînes de caractères, sur les nombres (entiers), sur les objets du système de fichiers
https://fr.wikibooks.org/wiki/Programmation_Bash/Tests

# Définition et lecture des tableaux
semaine=( "Lundi" "Mardi" "Mercredi" "Jeudi" "Vendredi" "Samedi" "Dimanche" )
echo "Le ${semaine[-1]} nous allons à l'église et nous préparons le début de l'école ${semaine[0]}. Le ${semaine[2]} c'est mi-temps"
echo "les ${#semaine[@]} jours de la semaine sont :"
for i in ${semaine[@]}
do echo "$i"
done

#Modification d'un tabeau
echo ${semaine[*]}
semaine[0]="Monday"
semaine[1]="Tuesday"
semaine[2]="Wednesday"
echo ${semaine[@]}

#protection des variables par "" et {}
prefix="préfixe"
suffix="suffixe"
echo "${prefix}_milieu_${suffix}"

#recuperer le contenu d'une fonction dans une variable
col=`sed -n 1,1p fichier.csv`
col=$(sed -n 1,1p fichier.csv)
read -p 'choix' choix #demande à l'ulisateur de faire un choix et l'enregistre dans la variable $choix

#
#FICHIERS ET RÉPERTOIRES
#

#Manipulation de fichiers et dossiers
ll -R -h #afficher le contenu complet du dossier courant incluant ses sous-dossiers
cp #permet de copier des fichiers et des répertoires ;
mv #permet de déplacer ou de renommer des fichiers et des répertoires ;
rm -r -f #permet de supprimer des fichiers et des répertoires ;
mkdir #permet de créer de nouveaux répertoires.
touch scriptrepfile # créer un fichier vide
chmod +x filename.sh # change les droits d'un fichier par rxemple pour le rendre executable
sed head cat ou vim #lit et affiche le contenu d'un fichier text
head -n 5 fichier.csv | cut -f 1 -d , #cut permet de selectionner la colone filtrer une colone dans un csv
./monscript var1 var2 var3 #éxecuter un script en lui envoyant les variables var1, var2, var3
dos2unix -b refile.sh # convertir fichier text dos en linux

# Comment se connecter à un serveur distant et effectuer des manipulation de fichiers
chmod 400 privkey.pem # Autoriser le telechargement du fichier
ssh -i "privkey.pem" ubuntu@ec2-13-38-75-162.eu-west-3.compute.amazonaws.com # se connecter à la console d'un serveur distant
scp -i "privkey.pem" -r fichier1.csv ubuntu@ec2-13-38-75-162.eu-west-3.compute.amazonaws.com:/home/ubuntu/group3/fichier1.csv # copier un fichier/dossier sur un serveur distant

#Montage et démontage de partition


#recuperer le contenu d'une fonction dans une variable
colonne=`sed -n 1,1p insurance.csv`
colonne=$(sed -n 1,1p fichier.csv)



sudo apt install kde-plasma-desktop #Installe KDE desktop plasma
man # affiche la documentation


# afficher une colonne dont le nom est passé en paramètre et le convertir en numero 
cat $2 | awk -F"," '{print $1 }' | head -$5
cat insurance.csv | awk -F"," '{print $1 }' | head -6

# Comment se connecter à un serveur distant et effectuer des manipulation de fichiers
chmod 400 privkey.pem # Autoriser le telechargement du fichier
ssh -i "privkey.pem" ubuntu@ec2-13-38-75-162.eu-west-3.compute.amazonaws.com # se connecter à la console d'un serveur distant
scp -i "privkey.pem" -r fichier1.csv ubuntu@ec2-13-38-75-162.eu-west-3.compute.amazonaws.com:/home/ubuntu/group3/fichier1.csv # copier un fichier/dossier sur un serveur distant

 
