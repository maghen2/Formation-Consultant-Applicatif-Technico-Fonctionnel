// TP_Algo_Python_en_C
// TP : Gestion de document et analyse logique (Jour 1)
// Rostand MAGHEN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// definition de constantes
#define MAX_TAB_SIZE 100
#define MATRICE_TAB_SIZE 10

// declaration des fonctions
// fonction saisieFloat demande un Float à l'utilisateur et retourne sa valeur
double saisieFloat();
// fonction saisieInt demande un Entier à l'utilisateur et retourne sa valeur
int saisieInt();
// fonction saisieChar demande une chaine de caractere à l'utilisateur et retourne sa valeur
char saisieChar();
// fonction de manipulation de tableaux d'entiers classement, tri du tabeau selon l'ordre croissant, décroissant, etc
void tableauGenerateur(int tableau[MATRICE_TAB_SIZE][MATRICE_TAB_SIZE]);
void tableauAfficher(int tableau[MAX_TAB_SIZE]);
int tableauPlusPetitElt(int tableau[MAX_TAB_SIZE]);
int tableauPlusGrandElt(int tableau[MAX_TAB_SIZE]);
void tableauIndex(int tableau[MAX_TAB_SIZE]);
int tableauDivisible(int tableau[MAX_TAB_SIZE]);
void tableauCroissant(int tableau[MAX_TAB_SIZE]);
void tableauDecroissant(int tableau[MAX_TAB_SIZE]);
int tableauCumule(int tableau[MAX_TAB_SIZE]);

// 3.	Écrire un programme qui prend en entrée des nombres et retourne un tableau ordonné.  Exemple :  J’entre      1 4 2 7 12 4 9   Il retourne       	1 2 4 4 7 9 12
int sainsiesaisieInt2Array();
// 7.	Écrire un algorithme qui prend en entrée le résultat de l’exercice 6 et un autre nombre que fourni l’utilisateur. Celui-ci sélectionne tous les éléments qui sont dans la même dizaine que celui entrée par l’utilisateur en donnant aussi leur position dans le tableau.
void tableauMemeDizaine(int choix, int tableau[MATRICE_TAB_SIZE][MATRICE_TAB_SIZE]);

// Declarartion des variables globales
int nombreDeEntiers=0;

int main() {
saisieInt2Array();
   return 0;
}

// IMPLEMENTATION DES FONCTIONS
// EXO:1) Genrateur de tableau
void tableauGenerateur(int tableau[MATRICE_TAB_SIZE][MATRICE_TAB_SIZE]){
    srand(time( NULL ));
    for (int i = 0; i < MATRICE_TAB_SIZE; i++){
        for(int j=0; j<MATRICE_TAB_SIZE; j++){
        tableau[i][j]=rand()%100;
        }
    }
}


// EXO:2) Afficheur de tableau
void tableauAfficher(int tableau[nombreDeEntiers]) {
    printf("STRUCTURE DU TABLEAU\n");
    for (int i = 0; i < nombreDeEntiers; i++) {
        printf("[%d]=%d; ", i,tableau[i]);
    }
    printf("\n");
}

// EXO:3) Afficher le plus petit element du tableau
int tableauPlusPetitElt(int tableau[nombreDeEntiers]){
    int min=tableau[0];
    int index=-1;
    for (int i = 0; i < nombreDeEntiers; i++) {
        if(min>tableau[i]){
          min=tableau[i];
          index=i;
        }
    }
    printf("Le plus petit element du tableau a pour valeur %d avec pour index %d\n", min,index);
}

// EXO:4) Afficher le plus grand element du tableau
int tableauPlusGrandElt(int tableau[nombreDeEntiers]){
    int max=tableau[0];
    int index=-1;
    for (int i = 0; i < nombreDeEntiers; i++) {
        if(max<tableau[i]){
          max=tableau[i];
          index=i;
        }
    }
    printf("Le plus grand element du tableau a pour valeur %d avec pour index %d\n", max,index);
}

// EXO:5) Ecrire une fonction qui renvoit l'index dans le tableau du nombre passé en parametre
void tableauIndex(int tableau[nombreDeEntiers]){
    int index=-1;
    int i = 0;
    printf("Choisissez la valeur dont vous voulez rechercher l'index dans le tableau\n");
    int valeur=saisieInt();

    // afin d'aller plus vite l'on fait une dichotomie
    int moitieIndex = 0;
    if(nombreDeEntiers%2==0)
        moitieIndex = nombreDeEntiers/2;
    else
       moitieIndex  = (nombreDeEntiers+1)/2;
if(tableau[moitieIndex]<=valeur){
    for (i = moitieIndex; i < nombreDeEntiers; i++){
        if(valeur==tableau[i]){
          index=i;
          break;
        }
    }
} else{
    for (i = 0; i < moitieIndex; i++){
        if(valeur==tableau[i]){
          index=i;
          break;
        }
    }

}
    if (index!=-1){

        printf("La valeur %d du tableau a pour index %d\n", valeur,index);
    } else{

        printf("La valeur %d n'existe pas dans le tableau\n", valeur);
    }
}
