#include <stdio.h>
#include <stdlib.h>
//SORAYA KHENE L2 ACAD B 06/12/2021
int main()
{
int n,i,j,k;
float c;
float *a,*b;
char answer;
do{
//cr�ation
printf("Donner le nombre de lignes=collonnes de votre matrice\n");
if(scanf("%d",&n)!=1){printf("\nERROR:Saissiez un nbr positive non nul la prochaine fois\n");exit(0);}

while(n<=0){
    printf("SVP saissier un entier positive non nul");
    scanf("%d",&n);
};
a=malloc(n*n*sizeof(float));
b=malloc(n*n*sizeof(float));
printf(">donner la matrice");
for(i=0;i<n;i++){
    printf("\n>Donner la ligne %d\n",i+1);
for(j=0;j<n;j++){
    printf(">");
if(scanf("%f",&*(a +i*n+ j))!=1){printf("\nERROR:Saissiez un entier la prochaine fois\n");exit(0);};

};
};
printf("Le vecteur solution de votre matrice\n");
for(i=0;i<n;i++){
    printf("\n>Donner la ligne %d du vecteur solution\n",i+1);
    printf(">");
    if(scanf("%f",&*(b + i))!=1){printf("\nERROR:Saissiez un entier la prochaine fois\n");exit(0);};
};

//Affichage
printf("\n>Matrice avant l'echelanement de gauss\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
    printf("\t%.2f",*(a +i*n+ j));

};
printf(" | %.2f",*(b + i));
   printf("\n");
};

//verification le pivot <> 0
for(k=0;k<n-1;k++){
   if(*(a +k*n+ k)==0){printf("\n[ ERROR LE PIVOT [%d,%d] EST NULE ]\n",k,k);exit(0);}
   else{
//calcule de A^k
    for(i=k+1;i<n;i++){
     c=*(a+ i*n + k) / *(a+ k*n + k);
     *(b+ i)=*(b+ i)-*(b + k)*c;
     *(a+ i*n + k)=0;

     for(j=k+1;j<n;j++){
        *(a+ i*n +j)=*(a+ i*n +j)-*(a+ k*n +j)*c;

     };
    };
   };

};
//Affichage apr�s taritement
printf("\n>La Matrice apres echelonement de gauss\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
    printf("\t%.2f",*(a +i*n+ j));

};
   printf(" | %.2f",*(b + i));
   printf("\n");
};
printf("Voulez vs echelonner une autre matrice ? ( o/n )\n");
scanf(" %c",&answer);
}while(answer=='o' || answer=='O');

  return 0;
};
