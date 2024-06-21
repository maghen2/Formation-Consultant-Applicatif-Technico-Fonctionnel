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
