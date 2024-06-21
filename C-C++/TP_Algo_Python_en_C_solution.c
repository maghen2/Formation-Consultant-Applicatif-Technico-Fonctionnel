#include <stdio.h>
#include <strings.h>


#define TAB_SIZE    100

void exo_3(int *tab, int size);
void exo_4(int *tab, int  size);
void exo_5(int *tab, int size);
void exo_6(int *tab, int size);
void exo_7(int *tab, int size);
void exo_8(int *tab, int size);


int main() {
    printf("Le nombre de valeur est limité à %d Nbre de valeur", TAB_SIZE);

    // Initialisation de la taille et limitation à 100
    int tabSize = 0;
    scanf("%d", &tabSize);
    if (tabSize > TAB_SIZE) {
        tabSize = TAB_SIZE;
    }
    // Initialisation du tableau
    // int *tab = malloc(tabSize * sizeof(int));
    int tab[tabSize];
    memset(tab, 0, tabSize);

    printf(" ============= Exercice 3 ============= \n");
    exo_3(tab, tabSize);
    printf("\n\n ============= Exercice 4 ============= \n");
    exo_4(tab, tabSize);
    printf("\n\n ============= Exercice 5 ============= \n");
    exo_5(tab, tabSize);
    printf("\n\n ============= Exercice 6 ============= \n");
    exo_5(tab, tabSize);
    printf("\n\n ============= Exercice 7 ============= \n");
    exo_5(tab, tabSize);
    printf("\n\n ============= Exercice 8 ============= \n");
    exo_5(tab, tabSize);
    return 0;
}

// Utilitaires
void print_tab(int *tab, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void scanf_tab(int *tab, int size) {
    for (int i = 0; i < size; ++i) {
        int val = 0;
        scanf("%d", &val);
        tab[i] = val;
    }
}

void ordre_croissant(int *tab, int size) {
    for (int i = 0; i < size-1; ++i) {
        printf("i = %d  === tab == ", i);
        print_tab(tab,size);
        if (tab[i] > tab[i+1]) {
            int c = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = c;
            i = -1;
        }
    }
}

// ########################################################################################
// EXERCICE 3
// ########################################################################################

void exo_3(int *tab, int tabSize) {
    scanf_tab(tab, tabSize);
    print_tab(tab, tabSize);
    ordre_croissant(tab, tabSize);
    print_tab(tab, tabSize);
}

// ########################################################################################
// EXERCICE 4
// ########################################################################################
void exo_4(int *tab, int size) {
    int valeur;
    printf("Entrer le nombre à rechercher par dichotomie");
    scanf("%d", &valeur);
    int start = 0;
    int end = size - 1;

    print_tab(tab, size);

    while (end != start) {

        int middle = start + (end - start)/2;
        printf(" start = %d , end = %d, middle = %d \n", start, end, middle);
        if (tab[middle] == valeur) {
            end = middle;
            break;
        } else if (tab[middle] < valeur) {
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }
    print_tab(tab, size);
    printf(" Valeur %d à l'index %d", tab[end], end);

}

// ########################################################################################
// EXERCICE 5
// ########################################################################################


void exo_5(int *tab, int size) {

}


// ########################################################################################
// EXERCICE 6
// ########################################################################################
void exo_6(int *tab, int size) {

}

// ########################################################################################
// EXERCICE 7
// ########################################################################################
void exo_7(int *tab, int size) {

}

// ########################################################################################
// EXERCICE 8
// ########################################################################################
void exo_8(int *tab, int size) {

}