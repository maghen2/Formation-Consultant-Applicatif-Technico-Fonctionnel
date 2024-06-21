//
// Created by Emmanuel on 30/03/2022.
//
#include <stdio.h>
#include <stdlib.h>

// 1 définir un structure Produits
// 2 J'ai besoin d'un panier de Produits
// 3 J'ai besoin d'une fonction ajouter un produit dans mon panier
// 4 j'ai besoin besoin d'une fonction pour afficher mon panier
// 5  // une fonction qui demande l'option à l'utilisateur;

#define TAILLE_TABLEAU 50

// 1 définir un structure Produits
typedef struct StructureDeProduit Produit;

struct StructureDeProduit {
    char nom[TAILLE_TABLEAU];
    int prix;
    int quantite;
    int tva;
};
// 2 J'ai besoin d'un panier de Produits
//struct Produit panier[TAILLE_TABLEAU];
// 3 J'ai besoin d'une fonction ajouter un produit dans mon panier
void ajouterProduitDansPanier(Produit panier[TAILLE_TABLEAU]);   //Produit creerNouveauProduit()
// 4 j'ai besoin besoin d'une fonction pour afficher mon panier
void afficherFacture(Produit panier[TAILLE_TABLEAU]);
// 5 une fonction qui demande l'option à l'utilisateur
int demandeLeChoix(); // int demandeLeChoix(int option)

int main() {
    // 2 J'ai besoin d'un panier de Produits
    Produit panier[TAILLE_TABLEAU] = {0}; // variable de type Tableau d'object 

    printf("*****************************************\n");
    printf("*  Bienvenue dans la gestion de facture *\n");
    printf("*****************************************\n\n");

    while (1){

        switch (demandeLeChoix()) {
            case 1:
                ajouterProduitDansPanier(panier);
                break;
            case 2:
                afficherFacture(panier);
                break;
            case 3:
                return 0;
        }

    }
}

void ajouterProduitDansPanier(Produit panier[TAILLE_TABLEAU]){
    //Mettre votre fonction ici
}
void afficherFacture(Produit panier[TAILLE_TABLEAU]){
    //Mettre votre fonction ici
}

int demandeLeChoix() {
    int option = 0;

    printf("Veuilez choisir une option\n");
    printf("1 : Ajouter un produit\n");
    printf("2 : Afficher La facture\n");
    printf("3 : Sortir du programme\n");
    scanf("%d", &option);
    return option;
}


