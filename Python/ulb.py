"""
#ce script permet de calculer la circonférece et l'aire d'un cercle dont l'utilisateur renseigne le rayon
"""
import math
# from math import pi, circle permet de n'importer que les constatntes dont nous avons besoin dans le module math
rayon = float(input("Veuillez entrer la rayon ex: 5.2 ")) # l'utilisateur renseigne la valeur du rayon

circonference = math.pi*2*rayon
surface = math.pi*rayon**2
print("le rayon est de         : ",rayon)
print("la circonférence est de : ",circonference)
print("la surface est de       : ",surface)

#2.5.5. Exercice UpyLaB 2.1 - Parcours : vert bleu rouge
x = 36
produit = x**2
div_entiere = x//5
expo = 15**15
pi = 3.14159
mon_texte = "Bonjour"
a=float(input())
b=float(input())
c=float(input())
reponse=b*c/a
print(reponse)
help(divmod)

# 2.7.4. Exercice UpyLaB 2.5 - Parcours vert bleu rouge
x=int(input())
y=int(input())
z=float(input())
t=float(input())
a=x-y
print(a)
a=x+z
print(a)
a=z+t
print(a)
a=x*z
print(a)
a=x/2
print(a)
a=x/(y+1)
print(a)
a=(x+y)*z/(4*x)
print(a)
a=x**(-1/2)
print(a)

#2.7.5. Exercice UpyLaB 2.6 - Parcours vert bleu rouge
a='Hello World'
a+="\nAujourd'hui"
a+='\nC\'est "Dommage !"'
a+='\nHum \\o/'
print(a)

#2.7.6. Exercice UpyLaB 2.7 - Parcours bleu rouge
import math
a=float(input())
a=4/3*math.pi*a**3
print(a)

# les boucles en python
i=0
while i!=42 :
    i = int(input("Combien de plis sont-ils nécessaires pour se rendre sur la Lune ? : "))
    if i==42 :
        print("Bravo !")
    else :
        print("Mauvaise réponse.")
# 3.5.4. Exercice UpyLaB 3.10 - Parcours vert bleu rouge
i=a=b=0
while i!=-1 :
    i = int(input())
    if i == -1:
        print(a/b)
    else :
        b+=1
        a+=i

#3.5.8. Exercice UpyLaB 3.13 - Parcours bleu rouge
a=int(input())
b=0
if a >= 0 :
    for i in range(a):
        a = int(input())
        b += a
    print(b)
elif a==-1 :
    while a!="F":
        a = input()
        if a=="F":
            print(b)
        else :
            a=int(a)
            b += a
#3.5.9. Exercice UpyLaB 3.14 - Parcours rouge
import random
a=random.randint(0,100)
b=int(input())
n=1
while n<=6 :
    if b>a and n<6:
        print("Trop grand")
    elif b<a and n<6:
        print("Trop petit")
    elif a==b :
        print("Gagné en", n, "essai(s) !")
        exit()
    if n>=6:
        print("Perdu ! Le secret était", a)
        exit()
    elif n<6:
        n += 1
        b = int(input())

#3.5.12. Exercice UpyLaB 3.16 - Parcours rouge
n=int(input())
for i in range(n+1) :
    l=len
    a = ""
    if i> 0 :
        for j in range(n+1) :
            if j>0 and len(str(j*i))==1:
                a+=" "+str(j*i)+" "
            elif j>0 :
                a+=str(j*i)+" "
        print(a)

#4.3.5. Exercice UpyLaB 4.2 - Parcours vert bleu rouge
def soleil_leve(a, b, c) :
    if a<b:
        if (c >= a and c < b):
            return True
        else:
            return False
    elif a>=b :
        if (c >= a) or (c>=0 and c<b):
            return True
        else:
            return False
    else :
        return False

        # 4.3.6. Exercice UpyLaB 4.3 - Parcours bleu rouge
        def premier(n):
            a = n ** 0.5
            b = 2
            if n <= 1:
                return False
            else:
                while b <= a:
                    if n % b == 0:
                        return False
                        exit()
                    else:
                        b += 1
                return True

        x = int(input())
        a = 2
        while a < x:
            if premier(a):
                print(a)
                a += 1
            else:
                a += 1

#4.4.2. Code ou programme « propre »
"""
Petit jeu de devinette (version 2)
Auteur: Thierry Massart
Date : 10 octobre 2018
Petit jeu de devinette d'un nombre entier tiré aléatoirement
par le programme dans un intervalle donné
Entrée : le nombre proposé par l'utilisateur
Résultat : affiche si le nombre proposé est celui tiré
           aléatoirement
"""

# importation des modules

import random   # module le tirage des nombres aléatoires

# Définition des constantes globales

VALEUR_MIN = 0  # borne inférieure de l'intervalle
VALEUR_MAX = 5  # borne supérieure de l'intervalle

# Définition des fonctions

def entree_utilisateur(borne_min, borne_max):
    """
    Lecture du nombre entier choisi par l'utilisateur
    dans l'intervalle [borne_min, borne_max]
    Entrées : bornes de l'intervalle
    Résultat : choix de l'utilisateur
    """
    message = "Votre choix de valeur entre {0} et {1} : "
    ok = False   # vrai quand le choix donné est valable
    while not ok: # répétition tant que le choix n'est pas bon
        choix = int(input(message.format(borne_min, borne_max)))
        ok = (borne_min <= choix and choix <= borne_max)
        if not ok: # entrée hors de l'intervalle
            print("Hors de l'intervalle ! Donnez une valeur valide")
    return choix

def tirage(borne_min, borne_max):
    """
    Tirage aléatoire d'un entier dans [borne_min, borne_max]
    """
    return random.randint(borne_min, borne_max)

def affichage_resultat(secret, choix_utilisateur):
    """
    Affiche le résultat
    """
    if secret == choix_utilisateur:
        print("gagné !")
    else:
        print("perdu ! La valeur était", secret)

# Code principal

mon_secret = tirage(VALEUR_MIN, VALEUR_MAX)
choix_util = entree_utilisateur(VALEUR_MIN, VALEUR_MAX)
affichage_resultat(mon_secret, choix_util)

# 4.5.5. Exercice UpyLaB 4.4 - Parcours vert bleu rouge
def alea_dice(s) :
    import random
    random.seed(s)
    a = random.randint(1, 6)
    b = random.randint(1, 6)
    c = random.randint(1, 6)
    if (a,b,c) == (1,2,4) or (a,b,c) == (1,4,2) or (a,b,c) == (2,1,4) or (a,b,c) == (2,4,1) or (a,b,c) == (4,1,2) or (a,b,c) == (4,2,1):
        return True
    else :
        return False
# 4.5.6. Exercice UpyLaB 4.5 - Parcours vert bleu rouge
def rendre_monnaie(prix, x20, x10, x5, x2, x1) :
    somme=x20*20+x10*10+x5*5+x2*2+x1
    if somme<prix :
        return (None,None,None,None,None)
    elif somme==prix :
        return (0, 0, 0, 0, 0)
    else :
        somme-=prix
        if somme>=20 :
            x20 = somme//20
            somme-=x20*20
        else :
            x20=0
        if somme>=10 :
            x10 = somme//10
            somme-=x10*10
        else :
            x10=0
        if somme>=5 :
            x5 = somme//5
            somme-=x5*5
        else :
            x5=0
        if somme>=2 :
            x2 = somme//2
            somme-=x2*2
        else :
            x2=0
        if somme>=1 :
            x1 = somme//1
            somme-=x1*1
        else :
            x1=0
        return (x20, x10, x5, x2, x1)

#4.5.8. Exercice UpyLaB 4.7 - Parcours bleu rouge
def rac_eq_2nd_deg(a=0.0, b=0.0, c=0.0):
    d=b**2-4*a*c
    if d<0 :
        return tuple()
    elif d==0 :
        r=-b/(2*a)
        return (r,)
    else :
        r1=(-b-d**0.5)/(2*a)
        r2 = (-b + d ** 0.5) / (2 * a)
        return (min(r1,r2), max(r1,r2))

#4.5.9. Exercice UpyLaB 4.8 - Parcours bleu rouge
import math
def catalan(n) :
    r = math.factorial(2*n) / (math.factorial(n+1)*math.factorial(n))
    r = int(r)
    return r

# 4.5.10. Exercice UpyLaB 4.9 - Parcours bleu rouge
def bat(joueur_1, joueur_2) :
    if joueur_1==joueur_2:
        return False
        elif joueur_1 == 0 and joueur_2 == 2
        return True
    elif joueur_1 == 1 and joueur_2 == 0
        return True
    elif joueur_1 == 2 and joueur_2 == 1
        return True
    else :
        return False

# 4.5.10. Exercice UpyLaB 4.9 - Parcours bleu rouge
def bat(joueur_1, joueur_2) :
    if joueur_1==joueur_2:
        return False
    elif joueur_1 == 0 and joueur_2 == 2 :
        return True
    elif joueur_1 == 1 and joueur_2 == 0 :
        return True
    elif joueur_1 == 2 and joueur_2 == 1 :
        return True
    else :
        return False

#5.1.7. Exercice UpyLaB 5.2 - Parcours vert bleu rouge
def est_adn(a) :
    b="ACGT"
    if a=="" :
        return False
    else :
        for i in range(len(a)) :
            if not(a[i] in b) :
                return False
                exit()
        return True
#5.1.8. Exercice UpyLaB 5.3 - Parcours vert bleu rouge
def duree(a,b):
    h = b[0]-a[0]
    m = b[1]-a[1]
    if h<=0:
        h+=24
    if m<0:
        m+=60
        h-=1
    return (h,m)
# 5.2.7. Exercice UpyLaB 5.8 - Parcours vert bleu rouge
"""
Cette fonction netourne les nb premiers nombres premeiers
situés entre min et max
"""
def prime_numbers(nb):
    if nb == 0:
        np = []
        return np
    elif not(isinstance(nb, int)) or nb<0:
        return None
        exit()

    else :
        na=1
        np=[]
        min = int(2)
        max = int(99**99)
        for n in range(min, max + 1):
            if n > 1:
                for i in range(2, n):
                    if (n % i) == 0:
                        break
                else:
                    np.extend([n])
                    na+=1
                    if na>nb:
                        return np
                        exit()
#5.4.5. Mise en pratique avec ou sans méthodes : exercice UpylaB 5.9 - Parcours vert bleu rouge
def anagrammes(a,b):
    return sorted(a)==sorted(b)
def anagrammes(a,b):
    if len(a) == len(b):
        for i in range(len(a)):
            if not(a[i] in b) or a.count(a[i]) != b.count(a[i]):
                return False
                exit()
        return True
    else :
        return False
print(anagrammes('aabc', 'cacb'))
#5.4.6. Exercice UpyLaB 5.10 - Parcours vert bleu rouge
def  dupliques(a):
        for i in range(len(a)):
            if a.count(a[i]) != 1:
                return True
                exit()
        return False
#5.4.7. Exercice UpyLaB 5.11 - Parcours bleu rouge
def intersection(v, w):
    ix = ''
    min_ = min(len(v), len(w))
    for s in range(len(v)):
        if len(ix) >= min_ - s:
            break
        for e in range(s + len(ix), min_):
            t = v[s:e+1]
            if t not in w:
                break
            if len(t) >= len(ix):
                ix = t
    return ix
#5.4.8. Exercice UpyLaB 5.12 - Parcours bleu rouge
def my_insert(c,b):
    if not (isinstance(b,int)):
        return None
        exit()
    else:
        a=c.copy()
        a.sort()
        for i in range(len(a)):
            if b<=a[i]:
                a.insert(i,b)
                return a
                exit()
        a.insert(i + 1, b)
        return a
#5.4.9. Exercice UpyLaB 5.13 - Parcours rouge
def my_insert(a,b):
    if not (isinstance(a,list) and isinstance(b,int)):
        assert False
    else:
        a.sort()
        for i in range(len(a)):
            if b<=a[i]:
                a.insert(i,b)
                return None
                exit()
        a.insert(i + 1, b)
        return None
#5.4.10. Exercice UpyLaB 5.14 - Parcours vert bleu rouge
def distance_mots (m1,m2):
    d=0
    if len(m1) == len(m2):
        for i in range(0, len(m1), 1):
            if m1[i] != m2[i]:
                d+=1
    return d
#Exercice UpyLaB 5.16 - Parcours vert bleu rouge
def my_pow(a,b):
    if not(isinstance(a,int)) or not(isinstance(b,float)):
        return None
    else :
        c=[b**i for i in range(0,a)]
        return c
#5.6.4. Exercice UpyLaB 5.17 - Parcours bleu rouge
def decompresse(a):
    b=[]
    for i in range(0, len(a)):
        for j in range(0,a[i][0]):
            b.append(a[i][1])
    return b
#5.6.5. Exercice UpyLaB 5.18 - Parcours rouge
# Solution ultra réduite
def my_filter(a,b):
    c=[i for i in a if b(i)]
    return c
#5.6.5. Exercice UpyLaB 5.18 - Parcours rouge
# Solution réduite
def my_filter(a,b):
    c=[]
    for i in a:
       if b(i):
            c.append(i)
    return c
#5.6.5. Exercice UpyLaB 5.18 - Parcours rouge
solution développée
def my_filter(a,b):
    c=[]
    for i in range(0, len(a)):
       if b(a[i]):
            c.append(a[i])
    return c

def gcd(x, y):
    while y != 0:
        (x, y) = (y, x % y)
    return x
print(gcd(-18,24))

def PGCD(num1,num2):
    while num2 != 0:
        (num1, num2) = (num2, num1 % num2)
    return num1

def LetterCapitalize(strParam):
    mot=""
    mots = strParam.split(" ")
    for i in mots :
        mot+=i.capitalize()+" "
    #del mot[-1]
    strParam=mot.rstrip()
    # code goes here
    return strParam
print(LetterCapitalize("hello world"))

def FirstReverse(strParam):
    mot=""
    for i in range(1, len(strParam)+1):
        mot+=strParam[-i]
    strParam=mot
    # code goes here
    return strParam
print(FirstReverse("I Love Code"))

def FirstFactorial(num):
    # code goes here
    if isinstance(num, int) and num>=1 and num<=18 :
        fact = 1
        for i in range(2, num + 1):
            fact *= i
        num=fact
    return num

print (FirstFactorial(4))

def LongestWord(sen):
    # code goes here
    mots=sen.split(" ")
    mots.sort()
    longmax=len(mots[-1])
    mots.append("_")
    for i in range(len(mots)):
        if mots[i]==longmax and mots[i]>=mots[i+1]:
            sen = mots[i]
            return sen
            exit()
#5.8.5. Exercice UpyLaB 5.19 - Parcours vert bleu rouge
def acrostiche(a):
    r = ""
    with open(a, encoding="utf-8") as txt:
        for ligne in txt:
            r+=ligne[0]
    return r

#5.8.6. Exercice UpyLaB 5.20 - Parcours vert bleu rouge
def nouveaux_heros(a,b):
    r=""
    heros1 = ["Paul", "Pierre", "Jacqueline"]
    heros2 = ["Tom", "Paul", "Mathilde"]
    with open(a, encoding="utf-8") as txt:
        for ligne in txt:
            ligne=ligne.replace(heros1[0], heros2[0])
            ligne=ligne.replace(heros1[1], heros2[1])
            ligne=ligne.replace(heros1[2], heros2[2])
            r+=ligne
            """ Meilleure méthode de coder mais je n'y arrives pas
            for i in range(len(heros1)):
                ligne = ligne.replace(heros1[i], heros2[i])
                """
    f=open(b,"w", encoding="utf-8")
    f.write(r)
    f.close

#5.9.4. Exercice UpyLaB 5.24 - Parcours vert bleu roug
def print_mat(m):
    r=""
    for i in m:
        r+= "\n"
        for j in i:
            r+=j+" "
    r=r.replace("\n","",1)
    print(r)
ma_matrice = eval(input())
print_mat(ma_matrice)
#5.9.5. Exercice UpyLaB 5.25 - Parcours bleu rouge
def trace(m):
    r=j=0
    for i in m:
            r+=i[j]
            j+=1
    return r
#Exercice UpyLaB 6.11 - Parcours vert bleu rouge
from math import pi
def bonne_planete(diametre):
    s1=50*1000
    s2=pi*diametre**2
    return s2>=s1
d=int(input())
if bonne_planete(d):
    print("Bonne planète")
else:
    print("Trop petite")
#6.5.3. Exercice UpyLaB 6.12 - Parcours vert bleu rouge
def belongs_to_file(word, filename):
    r=False
    for mot in open(filename, encoding="utf-8"):
        if word==mot.rstrip():
            r=True
    return r
