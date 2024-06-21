/*
Une entreprise souhaite piloter les différentes ventes de ces produits effectuées par des clients suivis par ses employées dans les différents bureaux.
Un employé est affecté à un bureau et reporte à un manager de l'entreprise.
L'employé suit également différents clients qui peuvent passer différentes commandes de différents produits ainsi que les paiements qu'il a réalisés. 
Pour chaque produit dans la commande effectuée on a la quantité commandée, le prix de chaque produit et le numéro de ligne dans la commande
Chaque produit a une ligne de produit qui la définit

Une BUREAU est caractérisé par un code, un numéro de télpéhone, une localisation (ville, code postal, etat, pays, territoire, adresse)
Un employé est défini par un numéo d'employé, un nom, un prénom, une adresse email et un poste
un client est identifié par un numéro, un nom, un prénom, une LOCALISATION (ville, code postal, etat, pays, territoire, adresse, un numumero de téléphone et un limite de crédit qu'il peut obtenir),
Pour chaque paiement effectué par un client, nous avons la référence du paiement, la date à laquelle le paiement a été effectué et le montant
Dans les commandes éffectuées par un client, on retrouve le numéro de commande, la date de la commande, la date estimée, la date de livraison, le status de la commande et les commentaires
Les produits quant à eux sont caractérisés par un nom, un taille, un vendeur, une description, la quantité en stock, le prix unitaire. 
Les produits ont des catégories dans lesquelles on a le nom de la catégorie, la description, l'image représentant la catégorie

MCD
MLD
MPD
Creation de la base de données
Creation des tables
Insertion des données

LISTE DES ENTITÉS
Bureau
Localisation
client
employé
paiement
produit
commande
categories

*/
/* MySQL WorkBench
PK NN UQ BIN UN ZF AI G
- PK: primary key (column is part of a pk)
- NN: not null (column is nullable)
- UQ: unique (column is part of a unique key)
- AI: auto increment (the column is auto incremented when rows are inserted)
- DEFAULT
[additional data type flags, depend on used data type]
- BIN: binary (if dt is a blob or similar, this indicates that is binary data, rather than text)
- UN: unsigned (for integer types, see docs: "10.2. Numeric Types")
- ZF: zero fill (rather a display related flag, see docs: "10.2. Numeric Types")
*/

-- date de naissance = email
-- commission = extension

-- /$HOME/Bureau/Merise SQL/SQL/Sample/create_databases_tables_correct.sql

CREATE DATABASE `poei` CHARACTER SET utf8 COLLATE utf8_general_ci;

-- Configuration de mysql aprés installation
CREATE USER 'maghen'@'localhost' IDENTIFIED BY '';
GRANT ALL ON *.* TO 'maghen'@'localhost' WITH GRANT OPTION;
FLUSH PRIVILEGES;
QUIT;


