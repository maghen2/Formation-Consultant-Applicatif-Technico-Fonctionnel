# TP_Algo_Python_en_C
# TP : Gestion de document et analyse logique (Jour 2)
# Rostand MAGHEN

import math, random, csv, tools;

#0 - Generer un tableau aléatoire pour tester les fonctions
# from math import pi, circle permet de n'importer que les constatntes dont nous avons besoin dans le module math
# Définition des constantes globales
import sys

MAX_TAB_SIZE = 100  # borne inférieure de l'intervalle
MATRICE_TAB_SIZE = 10  # borne supérieure de l'intervalle


# EXO:1) Genrateur de tableau de dimension MATRICE_TAB_SIZE x MATRICE_TAB_SIZE
def tableauGenerateur(dimension=1):
    if(dimension<=1):
        tableau = [0] * random.randrange(MAX_TAB_SIZE);
        for i in range(len(tableau)):
            tableau[i] = random.randrange(MAX_TAB_SIZE);
           # print(tableau[i]);
    else:
        tableau = [0]*MATRICE_TAB_SIZE;
        for i in range(MATRICE_TAB_SIZE):
            tableau[i] = [0]*MATRICE_TAB_SIZE;
            for j in range(MATRICE_TAB_SIZE):
                tableau[i][j] = random.randrange(MAX_TAB_SIZE);
                #print(tableau[i][j]);
    return tableau;

tableauNumerique = tableauGenerateur(1);
print(tableauNumerique)

# 1 – Créer un programme qui calcule la somme de toute les paramètres qu’on lui passe.
def somme(tableauNumerique):
    somme=0;
    for i in tableauNumerique:
        if(isinstance(i,int)): # 3 – Ajouter un contrôle chaque sur les paramètres pour vérifier qu’ils sont bien des entiers.
            somme+=i
    return somme;
print("La somme de la variable tableauNumerique = ", somme(tableauNumerique))

# 2 – Créer un second programme qui calcule la moyenne des paramètres qu’on lui passe.
def moyenne(tableauNumerique):
    moyenne=0;
    moyenne= somme(tableauNumerique) / len(tableauNumerique)
    return moyenne;
print("La moyenne de la variable tableauNumerique = ", moyenne(tableauNumerique))

#4 – Créer un nouveau script qui à 2 options : average et sum qui fait appel au 2 précédents scripts.
#5 – Créer un nouveau programme en fusionnant les 2 précédents scripts en un seul, vous devez transformer chaque script en fonction Average() et Sum()
def averageSum(tableauNumerique, averageSum):
    if(averageSum==0):
        averageSum=somme(tableauNumerique)
    elif(averageSum==1):
        averageSum = moyenne(tableauNumerique)
    else :
        print("Vous devez choisir averageSum=0 pour effectuer une somme et averageSum=1 pour la moyenne")

# 6 – Déplacer le fichier insurrance.csv dans votre répertoire de travail.
# 7 – Ajouter une nouvelle option à votre script qui va lire le fichier et afficher les 5 premières lignes du fichier
# 8 – Ajouter une nouvelle option à votre script qui va donner le nombre de lignes à afficher. Attention si le nombre de ligne est inferieur à l’option, on s’affichera tout le fichier et rien d’autre. Attention si l’option file n’est pas active, alors col n’est pas non plus accessible Exemple :
# 9 – Créer un nouveau script à partir du précédent en lui ajoutant 1 nouvelle option col. Cette option devra filtrer ce qu’affiche l’option file. Attention si l’option file n’est pas active, alors col n’est pas non plus accessible

def csvreader(csvFileName, limit, colName):
    with open(csvFileName, newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
        file = csv.DictReader(csvfile)

        if(colName in file.fieldnames):
            print(file.fieldnames)
            print(colName)
            for i, col in enumerate(file):
                print(col[colName]) #colonne.append(col[colNumber])
                if(i>=limit):
                    break
        else :
            for row in spamreader:
                print(', '.join(row))
                if(spamreader.line_num>limit):
                    break
csvreader("insurance.csv", 9, "bmi")

# Exemple: extraire le contenu de la table category et la sauvegarder dans un fichier texte csv
def sql2csv():
    # Recuperation du resultat de la requete
    sql = "select * from `category`"
    myresults = tools.database(sql)

    # Parcours des resultats et enregistrement dans le fichier csv
    with open('category.csv', 'w',  newline='') as csvfile:
        writer = csv.writer(csvfile)
        for row in myresults :
            writer.writerow(row)
        csvfile.close()
sql2csv()
print(sys.argv)