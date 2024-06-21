# TP_Algo_Python_en_C
# TP : Gestion de document et analyse logique (Jour 1)
# Rostand MAGHEN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

# definition de constantes
#define MAX_TAB_SIZE 100
#define MATRICE_TAB_SIZE 10

# declaration des fonctions
# fonction saisieFloat demande un Float à l'utilisateur et retourne sa valeur
double saisieFloat();
# fonction saisieInt demande un Entier à l'utilisateur et retourne sa valeur
def saisieInt();
# fonction saisieChar demande une chaine de caractere à l'utilisateur et retourne sa valeur
char saisieChar();
# fonction de manipulation de tableaux d'entiers classement, tri du tabeau selon l'ordre croissant, décroissant, etc
def tableauGenerateur(def tableau[MATRICE_TAB_SIZE][MATRICE_TAB_SIZE]);
def tableauAfficher(def tableau[MAX_TAB_SIZE]);
def tableauPlusPetitElt(def tableau[MAX_TAB_SIZE]);
def tableauPlusGrandElt(def tableau[MAX_TAB_SIZE]);
def tableauIndex(def tableau[MAX_TAB_SIZE]);
def tableauDivisible(def tableau[MAX_TAB_SIZE]);
def tableauCroissant(def tableau[MAX_TAB_SIZE]);
def tableauDecroissant(def tableau[MAX_TAB_SIZE]);
def tableauCumule(def tableau[MAX_TAB_SIZE]);

# 3.	Écrire un programme qui prend en entrée des nombres et retourne un tableau ordonné.  Exemple :  J’entre      1 4 2 7 12 4 9   Il retourne       	1 2 4 4 7 9 12
def sainsiesaisieInt2Array();
# 7.	Écrire un algorithme qui prend en entrée le résultat de l’exercice 6 et un autre nombre que fourni l’utilisateur. Celui-ci sélectionne tous les éléments qui sont dans la même dizaine que celui entrée par l’utilisateur en donnant aussi leur position dans le tableau.
def tableauMemeDizaine(def choix, def tableau[MATRICE_TAB_SIZE][MATRICE_TAB_SIZE]);

# Declarartion des variables globales
def nombreDeEntiers=0;

def main() :
saisieInt2Array();
   return 0;


# IMPLEMENTATION DES FONCTIONS
# EXO:1) Genrateur de tableau
def tableauGenerateur(def tableau[MATRICE_TAB_SIZE][MATRICE_TAB_SIZE]):
    srand(time( NULL ));
    for (i = 0; i < MATRICE_TAB_SIZE; i++):
        for(j=0; j<MATRICE_TAB_SIZE; j++):
        tableau[i][j]=rand()%100;
        
    

# EXO:2) Afficheur de tableau
def tableauAfficher(def tableau[nombreDeEntiers]) :
    prdeff("STRUCTURE DU TABLEAU\n");
    for (i = 0; i < nombreDeEntiers; i++) :
        prdeff("[%d]=%d; ", i,tableau[i]);
    
    prdeff("\n");

# EXO:3) Afficher le plus petit element du tableau
def tableauPlusPetitElt(def tableau[nombreDeEntiers]):
    def min=tableau[0];
    index=-1;
    for (i = 0; i < nombreDeEntiers; i++) :
        if(min>tableau[i]):
          min=tableau[i];
          index=i;
        
    
    prdeff("Le plus petit element du tableau a pour valeur %d avec pour index %d\n", min,index);

# EXO:4) Afficher le plus grand element du tableau
def tableauPlusGrandElt(def tableau[nombreDeEntiers]):
    def max=tableau[0];
    index=-1;
    for (i = 0; i < nombreDeEntiers; i++) :
        if(max<tableau[i]):
          max=tableau[i];
          index=i;
        
    
    prdeff("Le plus grand element du tableau a pour valeur %d avec pour index %d\n", max,index);


# EXO:5) Ecrire une fonction qui renvoit l'index dans le tableau du nombre passé en parametre
def tableauIndex(def tableau[nombreDeEntiers]):
    index=-1;
    i = 0;
    prdeff("Choisissez la valeur dont vous voulez rechercher l'index dans le tableau\n");
    def valeur=saisieInt();

    # afin d'aller plus vite l'on fait une dichotomie
    def moitieIndex = 0;
    if(nombreDeEntiers%2==0)
        moitieIndex = nombreDeEntiers/2;
    else
       moitieIndex  = (nombreDeEntiers+1)/2;
if(tableau[moitieIndex]<=valeur):
    for (i = moitieIndex; i < nombreDeEntiers; i++):
        if(valeur==tableau[i]):
          index=i;
          break;
        
    
 else:
    for (i = 0; i < moitieIndex; i++):
        if(valeur==tableau[i]):
          index=i;
          break;
        
    


    if (index!=-1):

        prdeff("La valeur %d du tableau a pour index %d\n", valeur,index);
     else:

        prdeff("La valeur %d n'existe pas dans le tableau\n", valeur);
    


# EXO:6) Ecrire une fonction recherchant les valeurs du tableau divisibles par le nombre en parametre
def tableauDivisible(def tableau[nombreDeEntiers]):
     prdeff("Choisissez le nombre dont vous voulez rechercher les valeurs divisibles dans le tableau\n");
     def diviseur=saisieInt();
     def valeur=-1;
     index=-1;
    for (i = 0; i < nombreDeEntiers; i++):
        if((tableau[i]%diviseur)==0):
          valeur=tableau[i];
          index=i;
          prdeff("Le nombre %d est un diviseur de la valeur %d du tableau qui a pour index %d\n", diviseur,valeur,index);
        
    


# EXO:7.1) Ecrire une fonction ordonne le tableau de facon croissante
def tableauCroissant(def tableau[nombreDeEntiers]):
i,j,k;
for(j=1;j<=nombreDeEntiers;j++) # pour faire l'operation N fois
    for(i=0;i<nombreDeEntiers-1;i++)
        if ( tableau[i] > tableau[i+1] ) :
                k=tableau[i];
                tableau[i]=tableau[i+1];
                tableau[i+1]=k;
        
prdeff("TABLEAU CROISSANT\n");
tableauAfficher(tableau);

# EXO:8) Ecrire une fonction de cumule la valeur avec celle de l'index suivant
def tableauCumule(def tableau[nombreDeEntiers]):
    for (i = 1; i < nombreDeEntiers-1; i++)
    tableau[i]+=tableau[i-1];
    prdeff("TABLEAU CUMULE\n");
    tableauAfficher(tableau);

# EXO:7.2) Ecrire une fonction ordonne le tableau de facon décroissante
def tableauDecroissant(def tableau[nombreDeEntiers]):
i,j,k;

for(j=1;j<=nombreDeEntiers;j++) # pour faire l'operation N fois
    for(i=0;i<nombreDeEntiers-1;i++)
        if ( tableau[i] < tableau[i+1] ) :
                k=tableau[i];
                tableau[i]=tableau[i+1];
                tableau[i+1]=k;
        
prdeff("TABLEAU DECROISSANT\n");
tableauAfficher(tableau);

# fonction saisieFloat demande un Float à l'utilisateur et retourne sa valeur
double saisieFloat():
double r=0.0;
prdeff("Entrer votre nombre decimal\n");
scanf("%lf", &r);
return r;

# fonction saisieInt demande un Entier à l'utilisateur et retourne sa valeur
def saisieInt():
def r=0;
prdeff("Entrer votre nombre entier\n");
scanf("%d", &r);
return r;

# fonction saisieChar demande une chaine de caractere à l'utilisateur et retourne sa valeur
char saisieChar():
char r=:"\0";
prdeff("Entrer votre mot\n");
scanf("%s", &r);
return r;


# 7.	Écrire un algorithme qui prend en entrée le résultat de l’exercice 6 et un autre nombre que fourni l’utilisateur. Celui-ci sélectionne tous les éléments qui sont dans la même dizaine que celui entrée par l’utilisateur en donnant aussi leur position dans le tableau.
def tableauMemeDizaine(def choix, def tableau[MATRICE_TAB_SIZE][MATRICE_TAB_SIZE]):
    def min = 0;
    def max = 0;
#while(1):
    choix = saisieInt();
    min = (choix/10)*10;
    max = min + 10;

    prdeff("STRUCRURE DU TABLEAU MATRICE %dx%d DES ELEMENTS ENTRE [%d, %d]\n", MATRICE_TAB_SIZE, MATRICE_TAB_SIZE, min, max);
    for (i = 0; i < MATRICE_TAB_SIZE; i++):
        for(j=0; j<MATRICE_TAB_SIZE; j++):
            if(tableau[i][j]>=min && tableau[i][j]<max)
            prdeff("tableau[%d][%d]=%d ", i,j, tableau[i][j]);
        
    prdeff("\n");
    
    prdeff("\n");

# 3.	Écrire un programme qui prend en entrée des nombres et retourne un tableau ordonné.  Exemple :  J’entre      1 4 2 7 12 4 9   Il retourne       	1 2 4 4 7 9 12
def saisieInt2Array():
    i=0;
    j = 0;

    prdeff("Combien de nombres entiers naturels voulez-vous entrez (entre 0 et 100 nombres)\n");
    nombreDeEntiers=saisieInt();
    def tableauDeEntiers[nombreDeEntiers];
    for(i=0; i<nombreDeEntiers; i++):
        prdeff("%d/%d Entrer un nombre entier naturel compris entre 0 et 100, Exemple : 1 4 2 7 12 4 9 \n", i+1,nombreDeEntiers);
        tableauDeEntiers[i]=saisieInt();
    
    tableauAfficher(tableauDeEntiers);
    tableauCroissant(tableauDeEntiers);
    tableauIndex(tableauDeEntiers);


    def tableau[MATRICE_TAB_SIZE][MATRICE_TAB_SIZE]=:0;
    tableauGenerateur(tableau);
    prdeff("STRUCRURE DU TABLEAU MATRICE %dx%d\n", MATRICE_TAB_SIZE, MATRICE_TAB_SIZE);
    for (i = 0; i < MATRICE_TAB_SIZE; i++):
        for(j=0; j<MATRICE_TAB_SIZE; j++):
            prdeff("tableau[%d][%d]=%d ", i,j, tableau[i][j]);
        
    prdeff("\n");
    
    prdeff("\n");


# 7.	Écrire un algorithme qui prend en entrée le résultat de l’exercice 6 et un autre nombre que fourni l’utilisateur. Celui-ci sélectionne tous les éléments qui sont dans la même dizaine que celui entrée par l’utilisateur en donnant aussi leur position dans le tableau.
    prdeff("Choisissez un nombre dont seront selectionne tous les elements qui sont dans la meme dizaine en donnant aussi leur position dans le tableau.\n");
    def choix = saisieInt();
    tableauMemeDizaine(choix, tableau);

    prdeff("_ _\n_| _|\n|_ _|\n");


