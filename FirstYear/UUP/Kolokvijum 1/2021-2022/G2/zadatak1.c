#include <stdio.h>
#include <math.h>
/*
Napisati funkciju pom(int arg) koja za prosleđeni broj vraća njemu najbliži kvadrat nekog
prirodnog broja. Ako su dva kvadrata podjednako blizu prosleđenoj vrednosti, vratiti veći.
Primeniti funkciju pom na sve brojeve iz intervala koji unosi korisnik i ispisati rezultate.
Primer: Ulaz: 3 22
Izlaz: 4 4 4 4 9 9 9 9 9 9 16 16 16 16 16 16 16 16 25 25
*/

int kvadrat(int n){
    if ((int)sqrt(n)*(int)sqrt(n)==n){
        return 1;
    }
    return 0;
}

int pom(int arg){
    if (kvadrat(arg)) return arg;
    int pomeraj = 1;
    while (1){
        if (kvadrat((arg+pomeraj))) return arg+pomeraj;
        else if (kvadrat(arg-pomeraj)) return arg-pomeraj;
        pomeraj++;
    }
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for (int i=a;i<=b;i++){
        printf("%d ",pom(i));
    }
    return 0;
}
