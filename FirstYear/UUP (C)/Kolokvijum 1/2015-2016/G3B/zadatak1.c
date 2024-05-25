
#include<stdio.h>

/*
 Napisati funkciju test koja izračunava broj koji se dobija od svih neparnih cifara
argumenta. Napraviti zbir brojeva koji se dobijaju primenom funkcije na brojeve
koje unosi korisnik ( korisnik unosi brojeve dok ne unese nula).
 */

int test(int arg){
    int step=1;
    int rez=0;
    while (arg!=0){
        if (arg%10%2==1){
            rez=rez+arg%10*step;
            step*=10;
        }
        arg=arg/10;
    }
    return rez;
}

int main(){
    int n;
    int zbir=0;
    scanf("%d",&n);
    while (n!=0){
        zbir+=test(n);
        scanf("%d",&n);
    }
    printf("%d",zbir);
    return 0;
}