#include <stdio.h>
/*
Napisati funkciju pom(int arg) koja za prosleđeni broj vraća njemu najbliži prost broj.
Ako su dva prosta broja podjednako blizu prosleđenoj vrednosti, vratiti manji. Primeniti
funkciju pom na sve brojeve iz intervala koji unosi korisnik i ispisati rezultate.
Primer: Ulaz: 8 22
Izlaz: 7 7 11 11 11 13 13 13 17 17 17 19 19 19 23
 */
int prost(int n){
    if (n==1) return 0;
    for (int i=2;i<n/2;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}
int pom(int arg){
    if (prost(arg)) return arg;
    int blizina=1;
    while (1){
        if (prost(arg-blizina)){
            return arg-blizina;
        }
        if (prost(arg+blizina)){
            return arg+blizina;
        }
        blizina++;
    }
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for (int i=a;i<=b;i++){
        printf("%d ", pom(i));
    }
    return 0;

}