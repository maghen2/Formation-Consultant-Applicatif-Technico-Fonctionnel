#$1 // nom de base du repertoire à creer aphanum
#$2 // nombre de repertoires à  créer int
#$3 // nom de base du fichier  aphanum
#$4 // nombre de fichiers par repertoire int
# test du type de variable des paramètres

if ["$1" == "-h"] 
then
echo "Usage: basename $0 [somestuff]"
exit 0
fi

if [ "$(echo $1 | grep "^[A-Za-z0-9]$")" ] 
then 
 var1=1
else echo "Le nom de base du repertoire doit être une chaîne de caractère aphanumèrique" 
fi

if [ "$(echo $2 | grep "^[ [:digit:] ]$")" ] 
then 
 var2=1
else echo "Le nombre de repertoires doit être un entier naturel" 
fi

if [ "$(echo $3 | grep "^[A-Za-z0-9]$")" ] 
then 
 var3=1 
else echo "Le nom de base du fichier doit être une chaîne de caractère aphanumèrique"
fi

if [ "$(echo $4 | grep "^[ [:digit:] ]$")" ] 
then 
 var4=1
else echo "Le nombre de repertoires doit être un entier naturel" 
fi


# Si les paramètres sont de bons types attendus, on éxècute le script
if ((var1==1 && var2==1 && var3==1 && var4==1))
then
for ((i=1; i<=$2; i++)) 
do mkdir "$1$i"
for ((j=1; j<=$4; j++))
do
touch "$1$i/$3$j"
done
done
fi