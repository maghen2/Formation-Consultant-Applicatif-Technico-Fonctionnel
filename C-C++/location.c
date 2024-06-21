#include <stdio.h>

// 1 faire nos structures d'objet
// 2 declarer nos fonctions
// 3 implementer
// 4 main
#define TAB_SIZE 50

struct structureClient {
    int numeroClient;
    char nom[TAB_SIZE];
    char prenom[TAB_SIZE];
    int age;
    char email[TAB_SIZE];
};

struct structureVoiture {
    int numeroVoiture;
    int prix;
    char type[TAB_SIZE];
};

struct structureContrat {
    int numeroContrat;
    int numeroVoiture;
    int numeroClient;
    char statut[TAB_SIZE];
};

typedef struct structureVoiture Voiture;
typedef struct structureClient Client;
typedef struct structureContrat Contrat;

// Base de donnéee global
Voiture listeVoiture[TAB_SIZE];
int nombreVoiture = 0;

Client listeClient[TAB_SIZE];
Contrat listeContrat[TAB_SIZE];

// fonctions communes
// -1 si différent
// 0 si egaux.
int comparerChaineDeCaractere(char chaine1[TAB_SIZE], char chaine2[TAB_SIZE]);
int verifierExistenceClientParEmail(Client liste[TAB_SIZE], char email[TAB_SIZE]);
int verifierClientExistenceParNumeroIdentifiant(Client liste[TAB_SIZE],int identifiant);
// fonctions

// Avant d'enregistrer le client dans le tableau,
// il faut lui assigner un numero Client
// ca sera l'index ou ce que vous voulez.
Client creerClient(Client client);
Client modifierClient(Client client);
void afficheLesClients();
void afficheUnClient(Client client);

Voiture creerVoiture(Voiture voiture);
void afficheLesVoitures();
void afficheUneVoiture(Voiture voiture);

Contrat louer(Client client, Voiture voiture);
void rendre(Voiture voiture);
void afficheListeContrats();


void saisirInformationVoiture();

// menu
// 1 Process une voiture
      // 11 Creer une voiture
      // 12 Modifier
      // 13 afficher la liste
      // 14 Sortie
// 2 Process un Client
     // 21 Creer
     // 22 afficher la liste
     // 23 Sortie
// 3 Louer une voiture en lui donnant le numero client et le numero de la voiture
// 4 rendre La voiture en lui donnant le numero de la voiture
// 5 afficher la liste
// 0 sortir du programme
int main() {
  // cliquer sur 11
    saisirInformationVoiture();
}

void saisirInformationVoiture() {
    Voiture voitureAEnregister = {0};

    printf("Entrez le prix \n");
    scanf("%d",&voitureAEnregister.prix);

    printf("Entrez le type \n");
    scanf("%s",voitureAEnregister.type);

    Voiture voitureCree = creerVoiture(voitureAEnregister);

    printf(" le numero de la voiture crée est %d",voitureCree.numeroVoiture);
}

Voiture creerVoiture(Voiture voiture) {

    if (!(nombreVoiture < TAB_SIZE - 1)) {
        printf(" Impossibilité de rajouter la voiture");
        voiture.numeroVoiture = -1;
    } else {
        // par que je lui donne un identifiant arbitraire
        voiture.numeroVoiture = nombreVoiture + 1;
        listeVoiture[nombreVoiture] = voiture;
        nombreVoiture++;
    }
    return voiture;
}

// rendre un fichier sous la forme location_prenom_nom.c



