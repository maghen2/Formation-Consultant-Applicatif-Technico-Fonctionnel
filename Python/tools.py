import mysql.connector

def database(sql):
    myDataBase = mysql.connector.connect(host="localhost", user = "maghen", password = "", database ="sakila")
    #print(myDataBase)
    mycursor= myDataBase.cursor()
    mycursor.execute(sql)
    myresult = mycursor.fetchall()
    myresult.insert(0,mycursor.column_names)
    #print(myresult)
    return myresult
