#include <stdio.h>

/*
Napisati funkciju pom koja proverava da li je argument veći od obrnutog broja.
Koristeći tu funkciju, sabrati sve brojeve koji unosi korisnik (kraj je kada se unese
nula), a da zadovoljavaju traženo svojstvo.
 */

int pom(int arg){
    int obrnut_br=0;
    int rez=arg;
    while (rez){

        obrnut_br=obrnut_br*10+rez%10;
        rez/=10;
    }

    if (arg>obrnut_br){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    int zbir;
    scanf("%d",&n);
    while (n!=0){
        if (pom(n)){
            zbir+=n;
        }
        scanf("%d",&n);
    }
    printf("%d",zbir);
    return 0;
}