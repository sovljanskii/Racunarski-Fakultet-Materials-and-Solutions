#include <stdio.h>
/*
Napisati funkciju pom koja proverava da li argument ima sve cifre manje od 5.
Koristeći tu funkciju, pomnožiti sve parne brojeve u intervalu koji unosi korisnik,
a da zadovoljavaju traženo svojstvo.
*/

int pom(int n){
    while (n){
        if (n%10>=5){
            return 0;
        }
        n/=10;
    }
    return 1;
}

int main(){
    int a,b;
    int rez=1;
    scanf("%d%d",&a,&b);
    for (int i=a;i<=b;i++){
        if(pom(i)){
            rez=rez*i;
        }
    }
    printf("Rezultat je %d",rez);
    return 0;
}

