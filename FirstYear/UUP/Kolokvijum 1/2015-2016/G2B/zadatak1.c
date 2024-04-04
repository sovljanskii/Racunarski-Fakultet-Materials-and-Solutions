#include <stdio.h>

/*
Napisati funkciju test koja proverava da li su prve dve cifre argumenta veće od
zadnje dve. U slučaju da je broj jednocifren ili dvocifren smatrati da je uslov
ispunjen.
Koristeći tu funkciju, sabrati sve brojeve koji unosi korisnik, a da zadovoljavaju
traženo svojstvo. Kraj je kada se naidje na broj koji nije ispunio svojstvo.
 */

int test(int arg){
    if (arg/100==0){
        return 1;
    }
    int zbr=arg%10;
    int predzbr=arg%100/10;
    while (arg/100!=0){
        arg/=10;
    }
    int pbr=arg/10;
    int dbr=arg%10;
    if (pbr>zbr&&pbr>predzbr&&dbr>zbr&&dbr>predzbr) return 1;
    return 0;
}


int main(){
    int n;
    int suma=0;
    scanf("%d",&n);
    while (test(n)){
        suma+=n;
        scanf("%d",&n);
    }
    printf("%d",suma);
    return 0;
}