#include <stdio.h>
#include <math.h>
/*
Napisati funkciju pom(int arg) koja vraća najveću razliku između susednih cifara argumenta (pretpostavimo da argument uvek ima bar dve cifre). 
Zatim ispisati sve brojeve iz intervala koji unosi korisnik a kojima je najveća razlika između cifara manja od 3.
*/

int pom(int arg){
    while (arg!=0){
        int c=arg%10;
        arg/=10;
        int c2=arg%10;
        if (abs(c-c2)>=3){
            return 0;
        }

    }
    return 1;
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for (int i=a;i<=b;i++){
        if (pom(i)){
            printf("%d\n",i);
        }
    }
    return 0;
}