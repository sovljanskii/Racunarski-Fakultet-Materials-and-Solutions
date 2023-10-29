#include <stdio.h>
/*
Napisati funkciju pom koja izračunava broj koji se dobija uklanjanjem prve i
poslednje cifre argumenta. Napraviti zbir brojeva koji se dobijaju primenom
funkcije na brojeve koje unosi korisnik ( korisnik unosi brojeve dok ne unese
nula).
*/
int pom(int arg){

    int cifre=1;
    int rez=arg;
    while (rez>100){

        cifre*=10;
        rez/=10;
    }
    arg/=10;
    arg%=cifre;
    
    return arg;
}

int main(){
    int n,sum=0;
    scanf("%d",&n);
    while (n!=0){
        sum+=pom(n);
        scanf("%d",&n);
    }
    printf("%d",sum);
    return 0;
}