#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAILLE_TABLEAU 50 //constante de préprocesseur définissant la TAILLE_TABLEAU
// declaration des fonctions
double saisieFloat();
int saisieInt();
void switchAge();
void facture();
void int2array();
int factureInteractive();

// définir une structure de Produits
typedef struct StructureDeProduit Produit;
struct StructureDeProduit {
    char nom[TAILLE_TABLEAU];
    int prix,quantite,tva;
};
void ajouterProduitDansPanier(Produit panier[TAILLE_TABLEAU]);   //Produit creerNouveauProduit()
// 4 j'ai besoin besoin d'une fonction pour afficher mon panier
void afficherFacture(Produit panier[TAILLE_TABLEAU]);
// 5 une fonction qui demande l'option à l'utilisateur
int demandeLeChoix();// int demandeLeChoix(int option)
int nombreDeProduitDansLePanier = 0;

int main(){
// Exercice 1 donner la categorie selon age
switchAge();
// fonction int2array Exercice 4 Programme de manipulation des entiers
int2array();
// fonction facture() Exercice 3 réalisation d'une facture
facture();
// fonction factureInteractive() Exercice 5 réalisation d'une facture de facon interactive avec l'utilisateur
factureInteractive();

// return 0;
}

/* implementation des fonctions */
// fonction saisieFloat demande un Float à l'utilisateur et retourne sa valeur
double saisieFloat(){
double r=0.0;
printf("Entrer votre nombre decimal\n");
scanf("%lf", &r);
return r;
}
// fonction saisieInt demande un Entier à l'utilisateur et retourne sa valeur
int saisieInt(){
int r=0;
printf("Entrer votre nombre entier\n");
scanf("%d", &r);
return r;
}
// fonction switchAge() Exercice 1 donner la categorie selon age
void switchAge(){
printf("Quel est votre age?\n");
int age=saisieInt();
switch(age){
case 6 ... 7:
    printf("Vous avez %d ans donc etes de la categorie Poussin\n", age);
    break;
case 8 ... 9:
    printf("Vous avez %d ans donc etes de la categorie Pupille\n", age);
    break;
case 10 ... 11:
    printf("Vous avez %d ans donc etes de la categorie Minime\n", age);
    break;
case 12 ... 15:
    printf("Vous avez %d ans donc etes de la categorie Cadet\n", age);
    break;
case 16 ... 18:
    printf("Vous avez %d ans donc etes de la categorie Junior\n", age);
    break;
case 19 ... INT_MAX :
    printf("Vous avez %d ans donc etes de la categorie Senior\n", age);
    break;
default:
    printf("Vous avez %d ans qui n'appartient a aucune categorie comprise de 6 ans et +\n", age);
    break;
break;
}
}
// fonction facture() Exercice 3 réalisation d'une facture
void facture(){
// Définition des variables
printf("Quel est le nombre de produits?");
int nbrProduit=saisieInt();
int quantite[nbrProduit],i;
double prix[nbrProduit],tva[nbrProduit],totalTTC;

// Pour chaque produit, renseignement du prix, la tva et la quantité
for(i=1; i<=nbrProduit; i++){
   printf("pour le Produit %d, indiquez le Prix. ", i);
   prix[i-1]=saisieFloat();
   printf("pour le Produit %d, indiquez le taux de TVA.  ", i);
   tva[i-1]=saisieFloat();
   printf("pour le Produit %d, indiquez la Quantite. ", i);
   quantite[i-1]=saisieInt();
}
// Ecriture soignée de la facture
printf("*********************************** FACTURE **********************************\n");
printf("** Quantite **  Nature  ** Prix HT **  Total HT  **   TVA   **  Prix TTC  **\n");
for(i=0; i<nbrProduit; i++){
    printf("**    %d    ** Produit %d ** %.4f ** %.4f ** %2.2f%% ** %2.2f **\n", quantite[i],i+1,prix[i],quantite[i]*prix[i],tva[i],quantite[i]*prix[i]*(1+tva[i]/100));
    totalTTC+=quantite[i]*prix[i]*(1+tva[i]/100);
}
printf("***************************** TOTAL TTC %f *****************************\n", totalTTC);
}
// fonction int2array Exercice 4 Programme de manipulation des entiers
void int2array(){
printf("Programme de Manipulation des Entiers (PME) : ");
int n=saisieInt();
int m=n;
int i=0;
int j=i;
int k=j;
//printf("n=%d; m=%d; i=%d; j=%d;\n", n,m,i,j);
//* on compte le nombre de chiffres de l'entier saisi par l'utilisateur et on l'enregistre dans la variable i
while(n>0){
    n/=10;
    i++;
}
//printf("n=%d; m=%d; i=%d; j=%d;\n", n,m,i,j);
// Extraction de chaque chiffre de l'entier saisi par l'utilisateur pour remplir le tableau intArray
int intArray[i];
// recuperation de la soisie utilisateur avant sa destruction lors de la construction du tableau intArray
n=m;
while(m>0){
    intArray[j]=m%10;
    m/=10;
    j++;
}
//calcul des caractérisques pair,impair,somme,inverse
int pair=0;
int impair=0;
int somme=0;
double inverse=0.0;
unsigned long intInverse=0;
k=j;
for(i=0; i<j; i++){
    // printf("%d[%d]=%d\n", n,i,intArray[i]);
    somme+=intArray[i];
    inverse+=intArray[i]*pow(10,k);
    k--;
    if((intArray[i]%2)==0)
        pair+=1;
    else
     impair+=1;
}
// transforme l'integer inverse en entier et sauvegarde la valeur dans intInverse
inverse/=10;
intInverse = (long)inverse;
/*
for(i=j-1; i>=0; i--){
    printf("%d[%d]=%d\n", n,i,intArray[i]);
}
*/
printf("Le nombre %d contient %d chiffres dont %d chiffres pairs et %d impairs. La somme de ses chiffres vaut %d et l'inverse est %f(%ld)\n", n,i,pair,impair,somme,inverse,intInverse);
}

// fonction factureInteractive() Exercice 5 réalisation d'une facture de facon interactive avec l'utilisateur
int factureInteractive(){
    Produit panier[TAILLE_TABLEAU] = {0}; // variable de type Tableau d'un panier de Produits

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
            default :
                return 0;
        }

    }
}
// Fonction d'obtention du choix de l'utilisateur
int demandeLeChoix() {
    int option = 0;
    printf("Veuilez choisir une option\n1 : Ajouter un produit\n2 : Afficher La facture\n3 ou autres : Sortir du programme\n");
    scanf("%d", &option);
    return option;
}
void ajouterProduitDansPanier(Produit panier[TAILLE_TABLEAU]){
    if (nombreDeProduitDansLePanier == TAILLE_TABLEAU - 1) {
        printf(" Votre panier est plein");
    } else {
        // creer un element du tableau
        Produit nouveauProduit;

        printf(" Entrer le nom du produit \n");
        scanf("%s", nouveauProduit.nom);

        printf(" Entrer le prix unitaire \n");
        scanf("%d", &nouveauProduit.prix);

        printf(" Entrer la quantité \n");
        scanf("%d", &nouveauProduit.quantite);

        printf(" Entrer la tva \n");
        scanf("%d", &nouveauProduit.tva);

        printf(" Ajout du produit à l'index %d", nombreDeProduitDansLePanier);
        panier[nombreDeProduitDansLePanier] = nouveauProduit; // ajoute du nouveauProduit dans le tableau panier afin de le sauvegarder

        printf("Le produit n° %d est %s\t%d\t%d\t%d\t \n",
               nombreDeProduitDansLePanier + 1,
               panier[nombreDeProduitDansLePanier].nom,
               panier[nombreDeProduitDansLePanier].prix,
               panier[nombreDeProduitDansLePanier].quantite,
               panier[nombreDeProduitDansLePanier].tva);

        nombreDeProduitDansLePanier++; // compte le nombre de produits et permet de rajouter le prochain produit sur l'index suivant
    }

}
void afficherFacture(Produit panier[TAILLE_TABLEAU]){
    //Mettre votre fonction ici
    float sommeTTC;
    int i = 0;

    printf("*             Facture                   *\n");
    printf("Numero \t Designation \t Quantite \t Prix unitaire \t  Prix HT \t TVA \t Prix TTC *\n");

    for (i = 0; i < nombreDeProduitDansLePanier ; i++) {
        Produit produitCourant = panier[i];
        int prixHT = produitCourant.prix * produitCourant.quantite;
        float prixTTC = prixHT * (1 + (float)produitCourant.tva/100);

        printf("%d \t %s \t %d \t %d \t  %d \t %d \t %f *\n",
               i + 1,
               produitCourant.nom,
               produitCourant.quantite,
               produitCourant.prix,
               prixHT,
               produitCourant.tva,
               prixTTC
               );
        sommeTTC += prixTTC;
    }

    printf("                                                  Total  %f \n",sommeTTC);
}

