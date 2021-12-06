import numpy as np
#SORAYA KHENE L2 ACAD B 06/12/2021

answer = "o"
while(answer=="o" or answer=="O"):
    bool=True
    print("\nDonner le nombre de lignes=collonnes de votre matrice\n")
    while bool:  
        try:
            n=int(input())
            if n<=0:
               raise ValueError
            else:
                bool=False     

        except ValueError:
            print("svp saissiez un nombre entier positive non nul")
            bool=True    
    #initialiser la matrices a des 1 partout
    matrix_a =np.array([[1 for x in range(n)]for y in range(n)])
    array_a=np.arange(n)
    #demander les valeurs de la matrice
    bool=True
    print(">La matrice")
    for i in range(0,n):
        print("\n>Donner la ligne "+str(i+1))
        for j in range(0,n):
            while(bool):
                try:
                    matrix_a[i,j]=int(input("T["+str(i+1)+"]["+str(j+1)+"] = "))
                    bool=False
                except ValueError:
                        print("Svp saissiez un nombre\n")
                        bool=True
            bool=True      
    print("\n>Le vecteur solution de votre matrice\n")
    for i in range(n):
            while(bool):
                try:
                    array_a[i]=int(input("Donner la ligne "+str(i+1)+" du vecteur solution "))
                    bool=False
                except ValueError:
                    print("Svp saissiez un nombre\n")    
                    bool=True
            bool=True
    #Affichage
    print("\n>Matrice avant l'echelanement de gauss\n")
    for x in range(n):
            for y in range(n):
                print(str(matrix_a[x,y]),end =" ")
            print(" | "+str(array_a[x]))    
    
        
    #verification le pivot <> 0
    for k in range(n-1):
        if matrix_a[k,k]==0:
            print("\n[ ERROR CAR PENDANT LE CALCUL J'AI TOMBER AVEC LE PIVOT ["+str(k+1)+"]["+str(k+1)+"] NULE ]\n")
            p=k
            
        else:
        #calcule de A^k
                p=0
                for i in range(k+1,n):
                    c=matrix_a[i,k] / matrix_a[k,k]
                    array_a[i]=array_a[i]-c*array_a[k]
                    matrix_a[i,k]=0
                    for j in range(k+1,n):
                        matrix_a[i,j]=matrix_a[i,j]-matrix_a[k,j]*c
                    
    #Affichage apr�s taritement
    if matrix_a[p,p]!=0:
        print("\n>La Matrice apres echelonement de gauss\n")
        for x in range(n):
            for y in range(n):
                print(str(matrix_a[x,y]),end =" ")
            print(" | "+str(array_a[x]))
    answer = input("\n>Voulez vous echelonner une autre matrice ? ( o/n )")    

