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
int i,j,k;

// Declaration des fonctions de comparaison et de verifications (retourne 0 si egaux ou correct) sinon -1
int comparerChaineDeCaractere(char chaine1[TAB_SIZE], char chaine2[TAB_SIZE]);
int verifierExistenceClientParEmail(char liste[TAB_SIZE], char email[TAB_SIZE]);
int verifierClientExistenceParNumeroIdentifiant(Client liste[TAB_SIZE],int identifiant);


// Declaration des differentes fonctions du programme
Voiture creerVoiture();
void ajouterVoiture();
Voiture modifierVoiture(Voiture voiture);
void afficheLesVoitures();
void afficheUnVoiture(Voiture voiture);

Client creerClient();
void ajouterClient();
Client modifierClient(Client client);
void afficheLesClients();
void afficheUnClient(Client client);

void ajouterContrat();
void louerVoiture(Client client, Voiture voiture);
void terminerContrat();
void rendreVoiture(Voiture voiture);
void afficheLesContrat();

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
/*
while(1){
char str1[TAB_SIZE]="\0";
char str2[TAB_SIZE]="\0";
printf("str1 \t");
scanf("%s", &str1);
printf("str2 \t");
scanf("%s", &str2);
printf("comparerChaineDeCaractere %d\n", (str1,str2));
}
*/
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
// Definition des fonctions de comparaison et de verifications (retourne 0 si egaux ou correct) sinon -1
int comparerChaineDeCaractere(char chaine1[TAB_SIZE], char chaine2[TAB_SIZE]){ //printf("comparerChaineDeCaractere %d\n", comparerChaineDeCaractere("",""));
    int i=0;
    int j=0;
 do{
  if(chaine1[i] != chaine2[i]){
  j=-1;
  break;
  }
  i++;
  } while(i<TAB_SIZE);

//  printf("j=%d\n", j);
  return j;
}

// renvoie 0 si cette email est dejà dans la liste sinon -1, vous devez utiliser la fonction
int verifierExistenceClientParEmail(char liste[TAB_SIZE], char email[TAB_SIZE]){
    int i=0;
    int j=-1;
    int k=-1;
if(nombreDeClient>0){
//    printf("nombreDeClient = %d\n", nombreDeClient);
 do{
//     printf("listeDeClient[i].email, email \t %s,%s\n", listeDeClient[i].email,email);
     k=comparerChaineDeCaractere(listeDeClient[i].email, email);

//    printf("i=%d \t j=%d t\ k=%d \n", i,j,k);
 if(k==0){
    j=0;
    break;
 }
 i++;
 } while(i<nombreDeClient);
}
// printf("nombreDeClient=%d \t i=%d \t j=%d t\ k=%d \n", nombreDeClient,i,j,k);
 return j;
}
int verifierClientExistenceParNumeroIdentifiant(Client liste[TAB_SIZE],int identifiant){}

// point d'entrée de notre programme de location de voiture
void locationInteractive(){
printf("*******************************************************************************************************\n");
printf("*******************************************************************************************************\n");
printf("**                            BIENVENUE DANS LE PROGRAMME DE LOCATION DE VOITURE                     **\n");
printf("*******************************************************************************************************\n");
printf("*******************************************************************************************************\n\n\n");

menuPrincipale(2); // Affichage de la liste de menu

//Définition des tableaux d'objets à passer en paramètre
Voiture voiture = {0}; // variable de type Voiture
Client client = {0}; //  variable de type Client
Contrat contrat = {0}; //  variable de type Contrat
int i =0;
// affichage du menu dans que l'utilisateur ne sort pas du programme
while(1){
        switch ((int)demandeLeChoix()){
        case 1:
menuVoiture();
i=0;
// entrée du programme dans le sous-menu
while(i!=1){
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
        case 10:
           menuPrincipale(1);
           menuPrincipale(2);
            i=1;
        break;
        default :
           menuVoiture();
        break;
}
}

        break;
        case 2:
menuClient();
i=0;
// entrée du programme dans le sous-menu
while(i!=1){
        switch ((int)demandeLeChoix()){
        case 21:
ajouterClient();
        break;
        case 22:
modifierClient(client);
        break;
        case 23:
afficheLesClients();
        break;
        case 20:
           menuPrincipale(1);
           menuPrincipale(2);
            i=1;
        break;
        default :
           menuClient();
        break;
  }
}
        break;
        case 3:
ajouterContrat();
        break;
        case 4:
terminerContrat();
        break;
        case 5:
afficheLesContrat(); // Affichage de la liste des contrats
        break;
        case 6:
menuPrincipale(2); // Affichage de la liste de menu
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
    case 1:
printf("****************************************************\n");
printf("*MERCI POUR VOTRE VISITE - RETOUR AU MENU PRINCIPAL*\n");
printf("****************************************************\n");
    break;
    case 2 :
    case 10 :
    case 20 :
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
printf("       12 Modifier une voiture (hors exercice)\n");
printf("       13 Afficher la liste des voitures\n");
printf("       10 Retourner au menu principal\n");
printf("       Veuillez choisir une option\n");
}
 // 4)	Créer la fonction void menuClient qui permet d’aller dans le sous menu client
 void menuClient(){
printf("*******************************************************************************************************\n");
printf("*                                SOUS MENU DU PROCESS CLIENT                                          *\n");
printf("*******************************************************************************************************\n");
printf("       21 Ajouter un client\n");
printf("       22 Modifier un client (hors exercice)\n");
printf("       23 Afficher la liste des clients\n");
printf("       20 Retourner au menu principal\n");
printf("       Veuillez choisir une option\n");
 }

/* II-  Process Voiture */
// Creation et renvoie d'un nouveau element Voiture
Voiture creerVoiture(){
        // création d'un nouveau élement de type Voiture
        Voiture nouveauElementVoiture = {0};
        printf(" Entrer le numero d'immatriculation de la Voiture \n");
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
void ajouterVoiture(){ // saisirInformationVoiture()
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
        menuVoiture();
    }
}
Voiture modifierVoiture(Voiture Voiture){}
// Affichage de la liste des voitures
void afficheLesVoitures(){
printf("*********************************** LISTE DES VOITURES ************************************************\n");
printf("*        NUMERO     *    IMMATRICULATION    *       PRIX    *       TYPE(Marque / Modele)             *\n");
for (i = 0; i < nombreDeVoiture; i++) {
printf("*        %d         *           %d             *         %2.2f    *           %s             *\n",
               i+1,
               listeDeVoiture[i].numeroVoiture,
               listeDeVoiture[i].prix,
               listeDeVoiture[i].type
       );
}
printf("********************************* TOTAL : %d Voitures **********************************\n", nombreDeVoiture);

    menuVoiture(); // Affichage du sous menu voiture
}

void afficheUnVoiture(Voiture Voiture){}

/* III) Process client */
// Creation et renvoie d'un nouveau element Client
Client creerClient(){ // saisirInformationClient()
int i=0;
// création d'un nouveau élement de type Client
Client nouveauElementClient = {0};
printf("Entrer le numero de matricule du Client \n");
nouveauElementClient.numeroClient = saisieInt();
//printf("%d\n", nouveauElementClient.numeroClient);

printf("Entrer le NOM du client \n");
scanf("%s", &nouveauElementClient.nom);
//printf("%s\n", nouveauElementClient.type);

printf("Entrer le Prenom du client \n");
scanf("%s", &nouveauElementClient.prenom);
//printf("%s\n", nouveauElementClient.type);

printf("Entrer l'age du client \n");
nouveauElementClient.age = saisieInt();
//printf("%d\n", nouveauElementClient.numeroClient);


// Vérification si l'adresse email existe déjà dans la base de donnée et obtention d'une adresse e-mail unique
  do{
  printf("Entrer une adresse e-mail client qui n'existe pas deja dans la base de donnee \n");
  scanf("%s", &nouveauElementClient.email);

  char liste[TAB_SIZE]={0};
  i=verifierExistenceClientParEmail(liste[TAB_SIZE],nouveauElementClient.email);
//  printf("while(i==0) \t i=%d\n", i);

  if(i==0)
  printf("L'adresse e-mail \"%s\" existe deja dans la base de donnee\n", nouveauElementClient.email);
  else
  printf("Adresse e-mail accepte. Merci\n");

  } while(i==0);

return nouveauElementClient; // retourn un nouveau
}
// Ajoute nouveauElementClient créer par creerClient(); dans le tableau listeDeClient afin de le sauvegarder et affichage des messages de confirmation
void ajouterClient(){ // saisirInformationClient()
    if (nombreDeClient>=TAB_SIZE - 1) { // Verification des limites de capacité
        printf(" Limite de %d/%d clients atteinte! Impossible de rajouter une nouvelle client\n", nombreDeClient, TAB_SIZE);
    }
    else {
        Client nouveauElementClient = {0};
        nouveauElementClient = creerClient();
        listeDeClient[nombreDeClient] = nouveauElementClient; // Recuperation d'un Nouveau Element Client créer par creerClient() et enregistrement dans la liste des clients
        //printf(" Une erreur s'est produite! Le Nouveau Element Client n'a pas pu etre ajoute a l'index %d de la Liste des Client", nombreDeClient);
        printf(" Le Nouveau Element Client a ete ajoute a l'index %d de la Liste des Clients avec les caracteristiques ci-dessous :\n", nombreDeClient);
        printf("Client numero : %d\t Matricule Client : %d\t Nom du Client : %s\t Prenom du Client : %s\t Age du Client : %d\t E-mail Client : %s\t \n",
               nombreDeClient + 1,
               listeDeClient[nombreDeClient].numeroClient,
               listeDeClient[nombreDeClient].nom,
               listeDeClient[nombreDeClient].prenom,
               listeDeClient[nombreDeClient].age,
               listeDeClient[nombreDeClient].email);
        nombreDeClient++; // compte le nombre de Clients et permet de rajouter le prochain element Client sur l'index suivant
        menuClient();
    }
}
Client modifierClient(Client Client){}
// Affichage de la liste des clients
void afficheLesClients(){
printf("*********************************** LISTE DES CLIENTS ************************************************\n");
printf("*   NUMERO   *   MATRICULE   *       NOM       *       PRENOM       *    AGE    *       E-MAIL       *\n");
for (i = 0; i < nombreDeClient; i++) {
printf("*     %d     *      %d        *      %s    *   %s    *    %d  *       %s *\n",
               i+1,
               listeDeClient[i].numeroClient,
               listeDeClient[i].nom,
               listeDeClient[i].prenom,
               listeDeClient[i].age,
               listeDeClient[i].email);
}
printf("********************************* TOTAL : %d Clients **********************************\n", nombreDeClient);

    menuClient(); // Affichage du sous menu client
}

void afficheUnClient(Client client){}

/* IV) Contrat et location */

// 1)	Créer et implémenter la fonction void afficheListeContrats(); affiche la liste des contrats
void afficheLesContrat(){
printf("************************ LISTE DES CONTRATS *************************\n");
printf("* NUMERO * NUMERO CONTRAT * NUMERO VOITURE * NUMERO CLIENT * STATUT *\n");
for (i = 0; i < nombreDeContrat; i++) {
printf("*     %d     *      %d        *      %d    *   %d    *       %s *\n",
               i+1,
               listeDeContrat[i].numeroContrat,
               listeDeContrat[i].numeroVoiture,
               listeDeContrat[i].numeroClient,
               listeDeContrat[i].statut);
}
printf("************************ TOTAL : %d Contrats *************************\n", nombreDeContrat);

    menuPrincipale(2); // Affichage du sous menu client
}

// 2)	Créer et implémenter la fonction Contrat louer(Client client, Voiture voiture) sachant qu’il faut vérifier s’il n’y pas un contrat de location sur la voiture
// Ajout de nouveau contrat
ajouterContrat(){
printf("Pour louer une voiture, vous aurez besoin d'un numero de client et d'un numero de voiture valide \n");

Voiture voiture = {0};
Client client = {0};

int numeroVoiture = 0;
int numeroClient = 0;
int i = 0;
int j = 0;
int k = 0;
int l = 0;

printf("Entrer le numero de plaque d'immatriculation de la voiture a louer \n");
numeroVoiture = saisieInt();
for(i=0; i<nombreDeVoiture; i++){
if (numeroVoiture == listeDeVoiture[i].numeroVoiture){
 voiture.numeroVoiture = listeDeVoiture[i].numeroVoiture;
 voiture.prix = listeDeVoiture[i].prix;
 strcpy(voiture.type, listeDeVoiture[i].type);
 break;
}
}

printf("Entrer le numero du client locataire \n");
numeroClient = saisieInt();
for(j=0; j<nombreDeClient; j++){
if (numeroClient == listeDeClient[j].numeroClient){
 client.numeroClient = listeDeClient[j].numeroClient;
 memcpy(client.nom, listeDeClient[j].nom, sizeof listeDeClient[j].nom);
 memmove(client.prenom, listeDeClient[j].prenom, sizeof listeDeClient[j].prenom);
 client.age = listeDeClient[j].age;
 strcpy(client.email, listeDeClient[j].email);
 break;
}
}
/*
// test du programme
printf("numeroVoiture=%d \t numeroClient=%d \t i=%d \t j=%d\n", numeroVoiture,numeroClient,i,j);
printf("voiture.numeroVoiture=%d \t voiture.prix=%2.2f \t voiture.type=%s\n", voiture.numeroVoiture, voiture.prix, voiture.type);
printf("client.numeroClient=%d, client.nom=%s, client.prenom=%s, client.age=%d, client.email=%s\n", client.numeroClient, client.nom, client.prenom, client.age, client.email);
*/
if((voiture.numeroVoiture == NULL) || (client.numeroClient == NULL)){
    printf("Vous devez indiquer un numero de plaque d'immatriculation de la voiture et un numero de client valides \n");
    }
else{
    for(k=0; k<nombreDeContrat; k++){
        if(listeDeContrat[k].numeroVoiture == voiture.numeroVoiture){
            printf("Desole! La voiture numero %d a deja ete loue \n", listeDeContrat[k].numeroVoiture);
            l=-1;
            break;
        }
    }
    if(l==0){
    louerVoiture(client, voiture);
    printf("La voiture numero %d de type %s a ete loue au prix de %2.2f au client numero %d ( %s %s ) \n", voiture.numeroVoiture, voiture.type, voiture.prix,client.numeroClient, client.nom, client.prenom);
    }
    }
menuPrincipale(2);
}
// Ajoute nouveauElementContrat créer par creerContrat(); dans le tableau listeDeContrat afin de le sauvegarder et affichage des messages de confirmation
void louerVoiture(Client client, Voiture voiture){ // saisirInformationContrat()
    if (nombreDeContrat>=TAB_SIZE - 1) { // Verification des limites de capacité
        printf(" Limite de %d/%d contrats atteinte! Impossible de rajouter une nouveaux contrat\n", nombreDeContrat, TAB_SIZE);
    } else {
// Creation d'un nouveau element Contrat
        Contrat nouveauElementContrat = {0};
        nouveauElementContrat.numeroContrat = nombreDeContrat+1;
        //printf("%d\n", nouveauElementContrat.numeroContrat);

        nouveauElementContrat.numeroVoiture = voiture.numeroVoiture;
        //printf("%d\n", nouveauElementContrat.numeroVoiture);

        nouveauElementContrat.numeroClient = client.numeroClient;
        //printf("%d\n", nouveauElementContrat.numeroClient);

        char statut[TAB_SIZE] = "Louer";
        strcpy(nouveauElementContrat.statut, statut);
        //printf("%s\n", nouveauElementContrat.statut);

        listeDeContrat[nombreDeContrat] = nouveauElementContrat; // Recuperation d'un Nouveau Element Contrat créer par creerContrat() et enregistrement dans la liste des voitures

        //printf(" Une erreur s'est produite! Le Nouveau Element Contrat n'a pas pu etre ajoute a l'index %d de la Liste des Contrat", nombreDeContrat);
        printf(" Le Nouveau Element Contrat a ete ajoute a l'index %d de la Liste des Contrat avec les caracteristiques ci-dessous :\n", nombreDeContrat);
        printf("Numero : %d\tNumero Contrat : %d\tNumero Voiture : %d\tNumero Client : %d\tStatut : %s\t\n",
               nombreDeContrat,
               listeDeContrat[nombreDeContrat].numeroContrat,
               listeDeContrat[nombreDeContrat].numeroVoiture,
               listeDeContrat[nombreDeContrat].numeroClient,
               listeDeContrat[nombreDeContrat].statut);
        nombreDeContrat++; // compte le nombre de Contrats et permet de rajouter le prochain element Contrat sur l'index suivant
    }
}
// 3)	Créer et implémenter la fonction void rendre(Voiture voiture) sachant que qu’on change le statut du contrat en cours
void terminerContrat(){
printf("Pour rendre une voiture, vous aurez besoin de fournir son numero de voiture \n");

Voiture voiture = {0};
int numeroVoiture = 0;
int i = 0;
int j = 0;

printf("Entrer le numero de plaque d'immatriculation de la voiture a rendre \n");
numeroVoiture = saisieInt();
for(i=0; i<nombreDeVoiture; i++){
if (numeroVoiture == listeDeVoiture[i].numeroVoiture){
 voiture.numeroVoiture = listeDeVoiture[i].numeroVoiture;
 voiture.prix = listeDeVoiture[i].prix;
 strcpy(voiture.type, listeDeVoiture[i].type);
 break;
}
}

/*
// test du programme
printf("numeroVoiture=%d \t numeroClient=%d \t i=%d \t j=%d\n", numeroVoiture,numeroClient,i,j);
printf("voiture.numeroVoiture=%d \t voiture.prix=%2.2f \t voiture.type=%s\n", voiture.numeroVoiture, voiture.prix, voiture.type);
*/
if(voiture.numeroVoiture == NULL){
    printf("Vous devez indiquer un numero de plaque d'immatriculation valide d'une voiture en cours de location \n");
}
else{
    rendreVoiture(voiture);
    printf("La voiture numero %d de type %s a ete rendue \n", voiture.numeroVoiture, voiture.type);
}
menuPrincipale(2);
}

void rendreVoiture(Voiture voiture){
    int i=0;
    int j=0;
    char statut[TAB_SIZE] = "Rendue";

    for(i=0; i<nombreDeContrat; i++){
        if(listeDeContrat[i].numeroVoiture == voiture.numeroVoiture){
          strcpy(listeDeContrat[i].statut, statut);
          j=-1;
          break;
        }
    }
if(j=-1){
        //printf(" Une erreur s'est produite! Le Nouveau Element Contrat n'a pas pu etre ajoute a l'index %d de la Liste des Contrat", nombreDeContrat);
        printf("Numero : %d\tNumero Contrat : %d\tNumero Voiture : %d\tNumero Client : %d\tStatut : %s\t\n",
               i+1,
               listeDeContrat[i].numeroContrat,
               listeDeContrat[i].numeroVoiture,
               listeDeContrat[i].numeroClient,
               listeDeContrat[i].statut);
}
else
    printf("Une erreur inattendue s'est produite! La voiture n'a pas pu etre rendue");
}
