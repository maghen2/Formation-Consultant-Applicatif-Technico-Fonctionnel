# TP_Algo_Python_en_C
# TP : Gestion de document et analyse logique (Jour 3)
# Rostand MAGHEN

import sys, collections, math, random, csv, tools;

# Étape 1 : Écrire une fonction vous permetant de lire les arguments d'un programme python et affiche ceux ci
def arguments():
    # creation d'un dictionnaire des differents arguments
    arguments={}
    i=1
    while(i<len(sys.argv)-1):
        if sys.argv[i] == "--output" :
            while("=" in str(sys.argv[i+1])):
                i+=1
                output = sys.argv[i].split("=")
                arguments[output[0]] = output[1]
            i+=1
        else:
            arguments[str(sys.argv[i]).replace("--","")]=sys.argv[i+1]
            i+=2
    # Trie du dictionnaire
    arguments = dict(sorted(arguments.items()))
    return arguments
#print(arguments())
argument = arguments()

# Étape 2 : Une option sera "--output". Si elle est presente, elle sera sous la forme --output file=file.csv screen=true (edited)
# Affichage des paramètres passés au script à l'aide de la fonction arguments()
# python TP_Algo_Python_en_C_maghen3.py --option2 val2 --output file=file.csv screen=true --option3 val3 --option1 val1
def afficheArguments():
    txt=""
# on rempli la variable du texte
    for cle, valeur in argument.items() :
        txt+=str(cle)+" = "+str(valeur)+"\n"

# on écrit le fichier des arguments
    f=open("arguments.txt", "w")
    f.write(txt)
    f.close
# si screen est true on affiche le texte
    if argument["screen"] == "true":
        print(txt)
afficheArguments()

#écrit le resultat d'une requete sql dans un fichier csv
def sql2csv(myresults):
    # Parcours des resultats et enregistrement dans le fichier csv
    with open(argument["file"] , 'w',  newline='') as csvfile:
        writer = csv.writer(csvfile)
        for row in myresults :
            writer.writerow(row)
    csvfile.close()
# Affiche le resultat d'une requete sql ou d'un tableau
def sql2print(myresults):
    for row in myresults:
        print(row)
#Étape 3 : Implémenter une option "--showTable". Elle va prendre en compte le nom de la table à traiter.
#Étape. 4 : Ajouter une nouvelle option "--limit" qui défini la limite des elements à extraire de la base de données.
def showTable():
    sql = "select * from "
    if ("showTable" in argument):
        tableName = argument["showTable"]
        sql += "`"+str(tableName)+"`"
        if ("limit" in argument):
            tableLimit = argument["limit"]
            sql += " limit "+str(tableLimit)
        print("sql="+sql)
        # Recuperation du resultat de la requete puis aficchage et/ou enregistrement selon les parametres passés
        myresults = tools.database(sql)
        if ("screen" in argument) and (argument["screen"] == "true"):
            sql2print(myresults)
        if ("file" in argument) and (argument["file"] != ""):
            sql2csv(myresults)
showTable();

#Étape 5 : Ajouter l'option "--actor" qui prendra le nom de l'acteur (colonne : LAST_NAME) et
print("#Étape 5 : Ajouter l'option '--actor' qui prendra le nom de l'acteur (colonne : LAST_NAME) et")