#include <stdio.h>

/*
Napisati funkciju pom(int p, int k) koja za prosleđene brojeve vraća prost broj najbliži po
vrednosti sredini intervala [p,k]. Ukoliko su dva prosta broja podjednako udaljena od sredine
intervala, funkcija pom vraća manji od ta dva prosta broja. Primeniti funkciju pom na
početak i kraj intervala koji unosi korisnik i na osnovu dobijene vrednosti ispisati koliko
prostih brojeva iz intervala [p,k] je manje, a koliko je veće od dobijene vrednosti.
Primer: Ulaz: 100 1000
Izlaz: Manjih 75, Vecih 67
 */

int prost(int arg){
    if (arg%2==0 && arg!=2) return 0;
    for (int i=3;i<arg/2;i+=2){
        if (arg%i==0){
            return 0;
        }
    }
    return 1;
}

int pom(int p, int k){
    int manji,veci;
    int sredina=(p+k)/2;
    for (int i=sredina;i;i++){
        if (prost(i)){
            veci=i;
            break;
        }
    }
    for (int i=sredina;i;i--){
        if (prost(i)){
            manji=i;
            break;
        }
    }
    if (veci-sredina<sredina-manji){
        return veci;
    }
    return manji;
}

int main(){
    int brojmanjih=0,brojvecih=0;
    int p,k;
    scanf("%d%d",&p,&k);
    int srednjiprosti=pom(p,k);
    for (int i=p;i<=k;i++){
        if (prost(i)){
            if (i>srednjiprosti)brojvecih++;
            else if (i<srednjiprosti) brojmanjih++;
        }
    }
    printf("Manjih %d, Vecih %d",brojmanjih,brojvecih);

    return 0;
}