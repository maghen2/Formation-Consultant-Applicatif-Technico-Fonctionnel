# TP_Algo_Python_en_C
# TP : Gestion de document et analyse logique (Jour 3)
# Rostand MAGHEN
#python TP_Algo_Python_en_C_maghen3.py --option2 val2 --limit 15 --output file=file.csv screen=true --option3 val3 --option1 val1 --option4 val4 --showTable category --actor davis

import mysql.connector, sys, csv;

def database(sql):
    myDataBase = mysql.connector.connect(host="localhost", user = "maghen", password = "", database ="sakila")
    #print(myDataBase)
    mycursor= myDataBase.cursor()
    mycursor.execute(sql)
    myresult = mycursor.fetchall()
    myresult.insert(0,mycursor.column_names)
    #print(myresult)
    return myresult

# Étape 1 : Écrire une fonction vous permetant de lire les arguments d'un programme python et affiche ceux ci
def arguments():
    # creation d'un dictionnaire des differents arguments
    arguments={}
    i=1
    while(i<len(sys.argv)-1):
        if sys.argv[i] == "--output" :
            while((i<len(sys.argv)-1) and ("=" in str(sys.argv[i+1]))):
                i+=1
                output = sys.argv[i].split("=")
                arguments[output[0]] = output[1]
            i+=1
        else:
            arguments[str(sys.argv[i]).replace("--","")]=sys.argv[i+1]
            i+=2
    # Trie du dictionnaire
    arguments = dict(sorted(arguments.items()))
    return arguments
#print(arguments())
argument = arguments()

# Étape 2 : Une option sera "--output". Si elle est presente, elle sera sous la forme --output file=file.csv screen=true (edited)
# Affichage des paramètres passés au script à l'aide de la fonction arguments()
# python TP_Algo_Python_en_C_maghen3.py --option2 val2 --output file=file.csv screen=true --option3 val3 --option1 val1
def afficheArguments():
    txt=""
# on rempli la variable du texte
    for cle, valeur in argument.items() :
        txt+=str(cle)+" = "+str(valeur)+"\n"

# on écrit le fichier des arguments
    f=open("arguments.txt", "w")
    f.write(txt)
    f.close
# si screen est true on affiche le texte
    if  ("screen" in argument) and (argument["screen"] == "true"):
        print(txt)
afficheArguments()

#écrit le resultat d'une requete sql dans un fichier csv
def sql2csv(myresults):
    # Parcours des resultats et enregistrement dans le fichier csv
    with open(argument["file"] , 'w',  newline='') as csvfile:
        writer = csv.writer(csvfile)
        for row in myresults :
            writer.writerow(row)
    csvfile.close()
# Affiche le resultat d'une requete sql ou d'un tableau
def sql2print(myresults):
    for row in myresults:
        for element in row:
            print(str(element)+"    ", end=" ")
        print("")
    print("")

#Étape 3 : Implémenter une option "--showTable". Elle va prendre en compte le nom de la table à traiter.
#Étape. 4 : Ajouter une nouvelle option "--limit" qui défini la limite des elements à extraire de la base de données.
def showTable():
    sql = "select * from "
    if ("showTable" in argument):
        tableName = argument["showTable"]
        sql += "`"+str(tableName)+"`"
        if ("limit" in argument):
            tableLimit = argument["limit"]
            sql += " limit "+str(tableLimit)
        #print("sql="+sql)
        # Recuperation du resultat de la requete puis aficchage et/ou enregistrement selon les parametres passés
        myresults = database(sql)
        if ("screen" in argument) and (argument["screen"] == "true"):
            sql2print(myresults)
        if ("file" in argument) and (argument["file"] != ""):
            sql2csv(myresults)
showTable();

#Étape 5 : Ajouter l'option "--actor" qui prendra le nom de l'acteur (colonne : LAST_NAME) et retournera la liste des clients qui ont loué ses films. Attention l'option "--limit" s'appliquera également si besoin.
def actor():
    sql = " SELECT customer.customer_id, customer.first_name, customer.last_name, count(*) as count_rental, actor.actor_id, actor.first_name, actor.last_name FROM customer"
    sql += " inner join rental on customer.customer_id=rental.customer_id"
    sql += " inner join inventory on inventory.inventory_id=rental.inventory_id"
    sql += " inner join film on film.film_id=inventory.film_id"
    sql += " inner join film_actor on film_actor.film_id=film.film_id"
    sql += " inner join actor on actor.actor_id=film_actor.actor_id"
    sql += " group by customer.customer_id, rental.customer_id"

    if ("actor" in argument):
        tableActorlast_name = argument["actor"]
        sql += ' having actor.last_name LIKE "%'+str(tableActorlast_name)+'%"'
        sql += " order by customer.customer_id"
        if ("limit" in argument):
            tableLimit = argument["limit"]
            sql += " limit "+str(tableLimit)
        #print("sql="+sql)
        # Recuperation du resultat de la requete puis aficchage et/ou enregistrement selon les parametres passés
        myresults = database(sql)
        if ("screen" in argument) and (argument["screen"] == "true"):
            sql2print(myresults)
        if ("file" in argument) and (argument["file"] != ""):
            sql2csv(myresults)
actor();

#Étape 6 : Ajouter l'option "--customer" qui prendra le nom du client (colonne : LAST_NAME) retournera la liste des acteurs qui on jouer dans les films qu'il a loué. Attention l'option "--limit" s'appliquera également si besoin. Conseil : Poser vous avant de commencer à coder
def customer():
    sql = " SELECT  actor.actor_id, actor.first_name, actor.last_name, count(*) as count_rental, customer.customer_id, customer.first_name, customer.last_name FROM actor"
    sql += " inner join film_actor on film_actor.actor_id=actor.actor_id"
    sql += " inner join film on film.film_id=film_actor.film_id"
    sql += " inner join inventory on inventory.film_id=film.film_id"
    sql += " inner join rental on rental.inventory_id=inventory.inventory_id"
    sql += " inner join customer on customer.customer_id=rental.customer_id"
    sql += " group by actor.actor_id, rental.customer_id"

    if ("customer" in argument):
        tableCustomerlast_name = argument["customer"]
        sql += ' having customer.last_name LIKE "%'+str(tableCustomerlast_name)+'%"'
        sql += " order by actor.actor_id,customer.customer_id"
        if ("limit" in argument):
            tableLimit = argument["limit"]
            sql += " limit "+str(tableLimit)
        #print("sql="+sql)
        # Recuperation du resultat de la requete puis afichage et/ou enregistrement selon les parametres passés
        myresults = database(sql)
        if ("screen" in argument) and (argument["screen"] == "true"):
            sql2print(myresults)
        if ("file" in argument) and (argument["file"] != ""):
            sql2csv(myresults)
customer();

