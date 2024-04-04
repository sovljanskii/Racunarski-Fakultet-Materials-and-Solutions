#include <stdio.h>

/*
Napisati funkciju test koja proverava da li broj ima cifru t (brojevi n i t su
argumenti). Koristeći tu funkciju, pomnožiti sve brojeve u intervalu koji unosi
korisnik, a da zadovoljavaju traženo svojstvo.
*/


int test(int n, int t){
    while(n){

        if (n%10==t){
            return 1;
        }
        n/=10;
    }
    return 0;
}

int main(){
    int a,b;
    int t;
    int rez=1;
    scanf("%d%d%d",&a,&b,&t);

    for (int i=a;i<=b;i++){
        if (test(i,t)) rez*=i;
    }
    printf("%d",rez);
    return 0;
}