#include <stdio.h>
#include <math.h>


/*
Napisati funkciju pom(int arg) koja proverava da li među sumama simetričnih
cifara broja arg postoji suma koja je prost broj. Funkcija pom vraća n-ti prost broj, gde je
broj n jednak najvećoj sumi simetričnih cifara koja je prost broj, ako takva suma ne postoji
onda je broj n jednak broju cifara prosleđenog argumenta.
Ispisati sve brojeve koje korisnik unese tako da su im cifre zarotirane ciklično za k mesta u
desno, gde je k povratna vrednost funkcije pom. Korisnik unosi brojeve sve dok ne unese 0.
Primer :Ulaz : 2543670 14862 14761 246 0
Izlaz : 4367025 14862 61147 462
*/

int prost(int n){
    for (int i=2;i<=n/2;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}
int nadjiprostbr(int n){
    int x=0;
    int prostbr=2;
    int i=2;
    while(x<n){
        if (prost(i)){
            x++;
            prostbr=i;
        }
        i++;
    }
    return prostbr;

}

int pom(int args){
    int max=0;
    int brojcifri=0;
    int rez=args;
    while (rez!=0){
        brojcifri++;
        rez/=10;
    }
    brojcifri--;
    while (args!=0){
        if (args>10){
        int a= args/pow(10,brojcifri--);


        int b=args%10;

        int zbir= a+b;

        if (prost(zbir)){
            if (zbir>max)max=zbir;
        }

        args/=10;
        args=args%(int)pow(10,brojcifri);
        brojcifri--;
            }
        else {
            if (prost(args)){
                if (args>max)max=args;
            }
            break;
        }
    }

    int k= nadjiprostbr(max);
    return k;
}
int okreni(int br,int n){
    int rez=br;
    int brcifri=0;
    while (rez!=0){
        brcifri++;
        rez/=10;
    }
    for (int i=0;i<n;i++){
        int x=br%10;
        br/=10;
        br=x*(int)pow(10,brcifri-1)+br;
    }
    return br;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        printf("%d\n", okreni(n, pom(n)));
        scanf("%d",&n);
    }

    return 0;
}