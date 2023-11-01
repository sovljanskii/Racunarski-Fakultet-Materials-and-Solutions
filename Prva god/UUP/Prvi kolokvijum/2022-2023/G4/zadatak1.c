#include <stdio.h>
/*
Napisati funkciju pom(int arg, int n) koja za prosleđeni broj i vrednost n vraća zbir prvih
n delilaca tog broja. Ako broj ima manje od n delilaca vratiti zbir svih. Primeniti funkciju pom
za n=3, na sve brojeve iz intervala koji unosi korisnik i ispisati rezultate.
Primer: Ulaz: 12 23
Izlaz: 6 14 10 9 7 18 6 20 7 11 14 24
*/
int pom(int args,int n){
    int zbir=0;
    int br=0;
    for (int i=1;i<args/2;i++){
        if (args%i==0){
            zbir+=i;
            br++;
            if (br==n){
                return zbir;
            }
        }
    }
    zbir+=args;
    return zbir;
}

int main(){
    int a,b;
    int n=3;
    scanf("%d%d",&a,&b);
    for (int i=a;i<=b;i++){
        printf("%d ",pom(i,n));
    }
}