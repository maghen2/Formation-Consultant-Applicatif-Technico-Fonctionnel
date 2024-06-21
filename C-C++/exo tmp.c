/* ========================================================================== */
/*                                                                            */
/*   location_rostant_maghen.c                                                */
/*   (c) Mars 2012 Rostant MAGHEN                                             */
/*                                                                            */
/*   Programme de location de voiture réalisé dans le cadre de la formation   */
/*  POIE IB Cergos - INETUM                                                   */
/*  Consulatnt Applicatif et Fonctionel                                       */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// definition des constantes globales
#define TAB_SIZE 50


// definition des differentes structures d'objets
struct structureVoiture {
    int numeroVoiture;
    double prix;
    char type[TAB_SIZE];
};

struct structureClient {
    int numeroClient;
    char nom[TAB_SIZE];
    char prenom[TAB_SIZE];
    int age;
    char email[TAB_SIZE];
};

struct structureContrat {
    int numeroContrat;
    int numeroVoiture;
    int numeroClient;
    char statut[TAB_SIZE];
};

// Definition des nouveaux types personnalisés attachés à nos structures d'objet
typedef struct structureVoiture Voiture;
typedef struct structureClient Client;
typedef struct structureContrat Contrat;

// Definition de tableaux globaux qui vont nous servir de tables de base de donnéee
Voiture listeDeVoiture[TAB_SIZE] = {0}; // variable de type Tableau contenant des objects de type Voiture
Client listeDeClient[TAB_SIZE] = {0}; //  variable de type Tableau contenant des objects de type Client
Contrat listeDeContrat[TAB_SIZE] = {0}; //  variable de type Tableau contenant des objects de type Contrat
// definition des variables globales
int nombreDeVoiture = 0;
int nombreDeClient = 0;
int nombreDeContrat = 0;

// Declaration des fonctions de comparaison et de verifications (retourne 0 si egaux ou correct) sinon -1
int comparerChaineDeCaractere(char chaine1[TAB_SIZE], char chaine2[TAB_SIZE]);
int verifierExistenceParEmail(char liste[TAB_SIZE], char email[TAB_SIZE]);
int verifierClientExistenceParNumeroIdentifiant(Client liste[TAB_SIZE],int identifiant);
// fonctions

// Declaration des differentes fonctions du programme
Voiture creerVoiture();
void ajouterVoiture();
Voiture modifierVoiture(Voiture voiture);
void afficheLesVoitures();
void afficheUnVoiture(Voiture voiture);

Client creerClient(Client client);
void ajouterClient();
Client modifierClient(Client client);
void afficheLesClients();
void afficheUnClient(Client client);

void louerVoiture(Client client, Voiture voiture);
void rendreVoiture(Voiture voiture);
void afficherContrat();

// fonction saisieFloat demande un Float à l'utilisateur et retourne sa valeur
double saisieFloat();
// fonction saisieInt demande un Entier à l'utilisateur et retourne sa valeur
int saisieInt();
// fonction saisieChar demande une chaine de caractere à l'utilisateur et retourne sa valeur
char saisieChar();
// point d'entrée de notre programme de location de voiture
void locationInteractive();
// fonction de recuperation du choix de l'utilisateur
int demandeLeChoix();
// fonction d'affichage intelligent du menu principal
void menuPrincipale(int choix);
// 3)	Créer la fonction void menuVoiture() qui permet d’aller dans le sous menu voiture
void menuVoiture();
 // 4)	Créer la fonction void menuClient qui permet d’aller dans le sous menu client
 void menuClient();


int main() {
locationInteractive();
}


// IMPLEMENTATION DES FONCTIONS
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
// fonction saisieChar demande une chaine de caractere à l'utilisateur et retourne sa valeur
char saisieChar(){
char r=0;
printf("Entrer votre mot\n");
scanf("%s", &r);
return r;
}
// point d'entrée de notre programme de location de voiture
void locationInteractive(){
printf("*******************************************************************************************************\n");
printf("*******************************************************************************************************\n");
printf("**                            BIENVENUE DANS LE PROGRAMME DE LOCATION DE VOITURE                     **\n");
printf("*******************************************************************************************************\n");
printf("*******************************************************************************************************\n\n\n");
menuPrincipale(1); // Affichage de la liste de menu

//Définition des tableaux d'objets à passer en paramètre
Voiture voiture = {0}; // variable de type Voiture
Client client = {0}; //  variable de type Client
Contrat contrat = {0}; //  variable de type Contrat

// affichage du menu dans que l'utilisateur ne sort pas du programme
while(1){
        switch ((int)demandeLeChoix()){
        case 1:
menuVoiture();
// entrée du programme dans le sous-menu
while(1){
        switch ((int)demandeLeChoix()){
        case 11:
ajouterVoiture();
        break;
        case 12:
modifierVoiture(voiture);
        break;
        case 13:
afficheLesVoitures();
        break;
        case 0:
            menuPrincipale(0);
            return 0;
        break;
        default :
           menuPrincipale(-1);
        break;
}

        break;
        case 2:
menuClient();
        break;
        case 3:
louerVoiture(client, voiture);
        break;
        case 4:
rendreVoiture(voiture);
        break;
        case 5:
afficherContrat(); // Affichage de la liste des contrats
        break;
        case 6:
menuPrincipale(1); // Affichage de la liste de menu
        break;
        case 0:
            menuPrincipale(0);
            return 0;
        break;
        default :
           menuPrincipale(-1);
        break;

}
}
}
// fonction d'affichage du menu et receuille du choix de l'utilisateur
int demandeLeChoix(){
int choix=-1;
scanf("%d", &choix);
return (int)choix;
}
// fonction d'affichage du menu
void menuPrincipale(int choix){
switch (choix) {
    case 0:
printf("****************************************************\n");
printf("*        MERCI POUR VOTRE VISITE - AU REVOIR       *\n");
printf("****************************************************\n");
    break;
    case 1 :
printf("*******************************************************************************************************\n");
printf("*           MERCI D'EFFECTUER VOTRE CHOIX EN SELECTIONANT LE CHIFFRE CORRESPONDANT DANS LE MENU       *\n");
printf("*******************************************************************************************************\n");
printf(" 1 Process une Voiture\n");
printf(" 2 Process un Client\n");
printf(" 3 Louer une voiture en lui donnant le numero client et le numero de la voiture\n");
printf(" 4 Rendre La voiture en lui donnant le numero de la voiture\n");
printf(" 5 Afficher la liste des contrats\n");
printf(" 6 Afficher la liste de menu\n");
printf(" 0 Sortir du programme\n");
    break;
    default :
printf("***********************************************************\n");
printf("*       LE CHOIX QUE VOUS AVEZ EFFECTUE N'EXISTE PAS!     *\n");
printf("* 6 afficher la liste de menu                             *\n");
printf("***********************************************************\n");
    break;
}
}
// 3)	Créer la fonction void menuVoiture() qui permet d’aller dans le sous menu voiture
void menuVoiture(){
printf("*******************************************************************************************************\n");
printf("*                                SOUS MENU DU PROCESS VOITURE                                         *\n");
printf("*******************************************************************************************************\n");
printf("       11 Ajouter une voiture\n");
printf("       12 Modifier une voiture\n (hors exercice)");
printf("       13 Afficher la liste des voitures\n");
printf("       10 Retourner au menu principal\n");
}
 // 4)	Créer la fonction void menuClient qui permet d’aller dans le sous menu client
 void menuClient(){
printf("*******************************************************************************************************\n");
printf("*                                SOUS MENU DU PROCESS CLIENT                                          *\n");
printf("*******************************************************************************************************\n");
printf("       21 Ajouter un client\n");
printf("       22 Modifier un client\n (hors exercice)");
printf("       23 Afficher la liste des clients\n");
printf("       20 Retourner au menu principal\n");
 }

// Creation et renvoie d'un nouveau element Voiture
Voiture creerVoiture(){
        // création d'un nouveau élement de type Voiture
        Voiture nouveauElementVoiture = {0};
        //printf(" Entrer le numero d'immatriculation de la Voiture \n");
        nouveauElementVoiture.numeroVoiture = saisieInt();
        //printf("%d\n", nouveauElementVoiture.numeroVoiture);

        printf(" Entrer le prix unitaire de location de la voiture\n");
        nouveauElementVoiture.prix = saisieFloat();
        //printf("%f\n", nouveauElementVoiture.prix);

        printf(" Entrer le type de voiture (Marque / Modele) \n");
        //strcpy(nouveauElementVoiture.type, saisieChar());
        scanf("%s", &nouveauElementVoiture.type);
        //printf("%s\n", nouveauElementVoiture.type);

return nouveauElementVoiture;
}
// Ajoute nouveauElementVoiture créer par creerVoiture(); dans le tableau listeDeVoiture afin de le sauvegarder et affichage des messages de confirmation
void ajouterVoiture(){
    if (nombreDeVoiture>=TAB_SIZE - 1) { // Verification des limites de capacité
        printf(" Limite de %d/%d voitures atteinte! Impossible de rajouter une nouvelle voiture\n", nombreDeVoiture, TAB_SIZE);
    } else {
        Voiture nouveauElementVoiture = {0};
        nouveauElementVoiture = creerVoiture();
        listeDeVoiture[nombreDeVoiture] = nouveauElementVoiture; // Recuperation d'un Nouveau Element Voiture créer par creerVoiture() et enregistrement dans la liste des voitures
        //printf(" Une erreur s'est produite! Le Nouveau Element Voiture n'a pas pu etre ajoute a l'index %d de la Liste des Voiture", nombreDeVoiture);
        printf(" Le Nouveau Element Voiture a ete ajoute a l'index %d de la Liste des Voiture avec les caracteristiques ci-dessous :\n", nombreDeVoiture);
        printf("Voiture numero : %d\tPlaque d'immatriculation : %d\tPrix : %2.2f\tType : %s\t\n",
               nombreDeVoiture + 1,
               listeDeVoiture[nombreDeVoiture].numeroVoiture,
               listeDeVoiture[nombreDeVoiture].prix,
               listeDeVoiture[nombreDeVoiture].type);
        nombreDeVoiture++; // compte le nombre de Voitures et permet de rajouter le prochain element Voiture sur l'index suivant
    }
}
Voiture modifierVoiture(Voiture Voiture){}
void afficheLesVoitures(){}
void afficheUnVoiture(Voiture Voiture){}

Client creerClient(Client client){}
void ajouterClient(){}
Client modifierClient(Client client){}
void afficheLesClients(){}
void afficheUnClient(Client client){}

void louerVoiture(Client client, Voiture voiture){

}
void rendreVoiture(Voiture voiture){}
void afficherContrat(){}


