#!/bin/bash


# Good practice for development, useful for debuging

  echo param:$1
  echo param:$2
  echo param:$3
  echo param:$4

# Good practice
Help()
{
   echo "Usage: $0 nomdir nbdirs nomfichier nbfichiers"
   echo
   echo "nomdir nom du répertoire"
   echo "nbdirs un nombre > 0: nombre de répertoire"
   echo "nomfichier nom de base du fichier"
   echo "nombre de fichier"
   echo
}

while getopts ":h" option; do
   case $option in
      h) Help
         exit;
esac
done
         
Clear()
{

rm -idv {$2}
}


while getopts ":c" option; do
   case $option in
      c) Clear
         exit;
   esac
done			

re="^[0-9]+$"
if ! [[ $2 =~ $re ]] ; then
 echo  "param 2 : $2 n'est pas un entier" 
 exit 1
 
fi 

re=^[0-9]+$
if ! [[ $4 =~ $re ]] ; then
 echo  "param 4 : $4  n'est pas un entier"  
 exit 1
 
fi 

for (( c=1; c<=$2; c++ ))
do  
  mkdir $1$c
  for ((i=1; i<=$4;i++))
  do
  	 touch $1$c/$3$i
  	 
  done 
done