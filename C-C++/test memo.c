#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// declaration des fonctions
double saisieFloat();
int saisieInt();
void doubleValeur();
void tableauGenerateur(int tableau[100]);
void tableauAfficher(int tableau[100]);
void tableauPlusPetitElt(int tableau[100]);
void tableauPlusGrandElt(int tableau[100]);
void tableauIndex(int tableau[100]);
void tableauDivisible(int tableau[100]);
void tableauCroissant(int tableau[100]);
void tableauDecroissant(int tableau[100]);
void tableauCumule(int tableau[100]);
int tp_poiei();

int tp_poiei(){
  // Récupérez un nombre et afficher le double
double a,b,c,d,e,f,r=0.0;
int m,n,p=0;

// demander deux nombres réels et demander le maximum
a=0.0;
b=0.0;
printf("Entrer votre premier nombre\n");
scanf("%lf", &a);
printf("Entrer votre second nombre\n");
scanf("%lf", &b);
if(a>=b)
r=a;
else
r=b;
printf("Le maximum entre %f et %f est %f\n",a,b,r);

// affichage du tabeau
int tableau[100] = {0};
    tableauGenerateur(tableau);
    tableauAfficher(tableau);
// Affichage du plus petit élement
tableauPlusPetitElt(tableau);
// Affichage du plus petit élement
tableauPlusGrandElt(tableau);
//Affichage de l'index de l'element
tableauIndex(tableau);
//Affichage de la liste des nombres divisibles et leur index
tableauDivisible(tableau);
// Tri du tabeau selon l'ordre croissant
tableauCroissant(tableau);
//Tri du tabeau selon l'ordre décroissant
tableauDecroissant(tableau);
//Création d'un tableau cumulé
tableauCumule(tableau);

scanf("%lf", &a);
return 0;
}

/* implementation des fonctions */
/* Variables et fonctions déjà définis dans main
// fonction saisieFloat demande un Float à l'utilisateur et retourne sa valeur
double saisieFloat(){
double r=0.0;
printf("Entrer votre nombre décimal\n");
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
*/
// fonction doubleValeur retourne le double de la valeur
void doubleValeur(){
int a=saisieInt(); // Demande à l'utilisateur la saisie de la valeur
int r=a*2; // On double la valeur
printf("%d*2=%d\n",a,r); // Affichage du resultat
}
// EXO:1) Genrateur de tableau
void tableauGenerateur(int tableau[100]) {
    srand(time( NULL ));
    for (int i = 0; i < 100; i++) {
        tableau[i]=rand()%100+0;
    }
}
// EXO:2) Afficheur de tableau
void tableauAfficher(int tableau[100]) {
    printf("STRUCTURE DU TABLEAU\n");
    for (int i = 0; i < 100; i++) {
        printf("[%d]=%d; ", i,tableau[i]);
    }
    printf("\n");
}
// EXO:3) Afficher le plus petit element du tableau
void tableauPlusPetitElt(int tableau[100]){
    int min=tableau[0];
    int index=-1;
    for (int i = 0; i < 100; i++) {
        if(min>tableau[i]){
          min=tableau[i];
          index=i;
        }
    }
    printf("Le plus petit element du tableau a pour valeur %d avec pour index %d\n", min,index);
}
// EXO:4) Afficher le plus grand element du tableau
void tableauPlusGrandElt(int tableau[100]){
    int max=tableau[0];
    int index=-1;
    for (int i = 0; i < 100; i++) {
        if(max<tableau[i]){
          max=tableau[i];
          index=i;
        }
    }
    printf("Le plus grand element du tableau a pour valeur %d avec pour index %d\n", max,index);
}

// EXO:5) Ecrire une fonction qui renvoit l'index dans le tableau du nombre passé en parametre
void tableauIndex(int tableau[100]){
    int index=-1;
    printf("Choisissez la valeur dont vous voulez rechercher l'index dans le tableau\n");
    int valeur=saisieInt();
    for (int i = 0; i < 100; i++){
        if(valeur==tableau[i]){
          index=i;
        }
    }
    if (index!=-1){
    printf("L'index correspondant a la valeur %d du tableau a pour index %d\n", valeur,index);
    }
    else{
    printf("La valeur %d n'existe pas dans le tableau\n", valeur);
    }
}

// EXO:6) Ecrire une fonction recherchant les valeurs du tableau divisibles par le nombre en parametre
void tableauDivisible(int tableau[100]){
     printf("Choisissez le nombre dont vous voulez rechercher les valeurs divisibles dans le tableau\n");
     int diviseur=saisieInt();
     int valeur=-1;
     int index=-1;
    for (int i = 0; i < 100; i++){
        if((tableau[i]%diviseur)==0){
          valeur=tableau[i];
          index=i;
          printf("Le nombre %d est un diviseur de la valeur %d du tableau qui a pour index %d\n", diviseur,valeur,index);
        }
    }
}

// EXO:7.1) Ecrire une fonction ordonne le tableau de facon croissante
void tableauCroissant(int tableau[100]){
int i,j,k;
for(j=1;j<=100;j++) // pour faire l'operation N fois
    for(i=0;i<99;i++)
        if ( tableau[i] > tableau[i+1] ) {
                k=tableau[i];
                tableau[i]=tableau[i+1];
                tableau[i+1]=k;
        }
printf("TABLEAU CROISSANT\n");
tableauAfficher(tableau);
}
// EXO:8) Ecrire une fonction de cumule de la valeur de celle de l'index suivant
void tableauCumule(int tableau[100]){
    for (int i = 1; i < 99; i++)
    tableau[i]+=tableau[i-1];
    printf("TABLEAU CUMULE\n");
    tableauAfficher(tableau);
}
// EXO:7.2) Ecrire une fonction ordonne le tableau de facon décroissante
void tableauDecroissant(int tableau[100]){
int i,j,k;

for(j=1;j<=100;j++) // pour faire l'operation N fois
    for(i=0;i<99;i++)
        if ( tableau[i] < tableau[i+1] ) {
                k=tableau[i];
                tableau[i]=tableau[i+1];
                tableau[i+1]=k;
        }
printf("TABLEAU DECROISSANT\n");
tableauAfficher(tableau);
}

/* EXERCICE
Imaginez un programme qui demande deux nombres à l'utilisateur :
Stockez ces deux nombres dans des variables.
Faites toutes les opérations de base et afficher les resulats ligne par ligne
*/
  // Declaration de fonction
int incremente();

int Test() {
  // Récupérez les deux nombres saisies par l'utilisateur
double a=0.0;
double b=0.0;

printf("Entrer votre premier nombre\n");
scanf("%lf", &a);
printf("Entrer votre deuxiéme nombre\n");
scanf("%lf", &b);
// on effectue les opérations
double s=a+b;
double st=a-b;
double p=a*b;
double d=a/b;

// on affiche les résultats
printf("%f+%f=%f\n",a,b,s);
printf("%f-%f=%f\n",a,b,st);
printf("%f*%f=%f\n",a,b,p);
printf("%f/%f=%f\n",a,b,d);
/* les dtructures de controles
if (age == 2)
{
    printf("Salut bebe !");
}
else if (age == 6)
{
    printf("Salut gamin !");
}

else
{
    printf("Je n'ai aucune reponse pour ton age");
}
switch (age)
{
case 2:
  printf("Salut bebe !");
  break;
case 6:
  printf("Salut gamin !");
  break;
default:
  printf("Je n'ai aucune reponse pour ton age");
  break;
}
char menu="=== Menu ===\n1. Royal Cheese\n2. Mc Deluxe\n3. Mc Bacon\n4. Big Mac\nVotre choix ?\n";
printf("%s",menu);
*/
// Exercice sur le menu
printf("=== Menu ===\n1. Royal Cheese\n2. Mc Deluxe\n3. Mc Bacon\n4. Big Mac\nVotre choix ?\n");
int n=0;
scanf("%d", &n);
switch (n) {
case 1:
    printf("Vous avez choisi le menu Royal Cheese\n");
    break;
case 2:
    printf("Vous avez choisi le menu Mc Deluxe\n");
    break;
case 3:
    printf("Vous avez choisi le menu Mc Bacon\n");
    break;
case 4:
    printf("Vous avez choisi le menu Big Mac\n");
    break;
default:
    printf("Le menu que vous avez choisi n'existe pas\n");
    break;

}
while (n<=10){
    n++;
    printf("n=%d\n",n);
}
    printf("test sur la portée des variables\n");
    printf("%d\n", incremente());
    printf("%d\n", incremente());
    printf("%d\n", incremente());
    printf("%d\n", incremente());


return 0;


}

int incremente()
{
    // static rend la variable ou la fonction globale dans la limite du fichier de définition
    static int nombre = 0;

    nombre++;
    return nombre;
}


/*
Ci-dessous, ce sont des directives de préprocesseur.
Ces lignes permettent d'ajouter des fichiers au projet,
fichiers que l'on appelle bibliothèques.
Grâce à ces bibliothèques, on disposera de fonctions toutes prêtes pour afficher
par exemple un message à l'écran.
*/

#include <stdio.h>
#include <stdlib.h>

/*
Ci-dessous, vous avez la fonction principale du programme, appelée main.
C'est par cette fonction que tous les programmes commencent.
Ici, ma fonction se contente d'afficher Bonjour à l'écran.
*/

unsigned int test()
{
// Déclaration et assignation de valeurs aux variables
/*
Nom du type Minimum Maximum
signed char -127 127
int -32 767 32 767
long -2 147 483 647 2 147 483 647
float -1 x1037 1 x1037
double -1 x1037 1 x1037
*/
 int noteDeMaths=14;
 double sommeArgentRecue=1846.18;
 unsigned int age=37*365*24*60*60;
 unsigned long ageLong=age*age*age*age;
 const char auteur="Rostand MAGHEN";

 // Affichages des méssages indiquant les valeurs des variables
  printf("noteDeMaths = %d\n", noteDeMaths);
  printf("sommeArgentRecue=%f\n", sommeArgentRecue);
  printf("age= %u secondes\n", age);
  printf("ageLong= %ld secondes\n", ageLong);

  // Affichage de nos variables sur une seule ligne
/*
Format Type attendu
"%d" int
"%u" unsigned int
"%ld" long
"%f" float
"%f" double
%2.2f double deux chiffres apres la virgule
%.4f double quatre chiffres apres la virgule

*/
  printf("\nAFFICHAGE DE NOS VARIABLES SUR UNE SEULE LIGNE DE CODE\n");
  printf("noteDeMaths = %d\nsommeArgentRecue=%f\nage= %u secondes\nageLong= %ld secondes\n", noteDeMaths, sommeArgentRecue, age, ageLong);
/*
avec SCAN le format du double est lf
*/
  // Récupérez une saisie utilisateur
  printf("Entre votre age en nombre entier ou décimal. EX: 12 ou 38.5\n");
  float ageSaisi=0;
  scanf("%f", &ageSaisi);
  printf("Confirmez-vous avoir %f ans?\n", ageSaisi);


return 0;          // Le programme renvoie le nombre 0 puis s'arrête
}
tp_poiei();
