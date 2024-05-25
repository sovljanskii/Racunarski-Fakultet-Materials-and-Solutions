#include <stdio.h>

/*
Napisati funkciju pom(int arg) koja za prosleđeni broj pronalazi cifru koja se nalazi na sredini
broja. Ukoliko se broj sastoji od parnog broja cifra, vratiti veću srednju cifru.
Napisati program koji ispisuje sve brojeve iz intervala koji korisnik unese ukoliko je broj iz
intervala deljiv kubom svoje srednje cifre.
Primer: Ulaz: 819 1030
Izlaz: 819 824 837 864 910 911 912 913 914 915 916 917 918 919
920 928 1010 1011 1012 1013 1014 1015 1016 1017 1018 1019 1024
 */

int brojNula(int n){
    int res=1;
    while (n){
        res*=10;
        n/=10;
    }
    return res;
}

int pom(int arg){
    int nule = brojNula(arg);
    nule/=10;
    while (arg>99){
        arg%=nule;
        nule/=100;
        arg/=10;

    }
    if (arg<10) return arg;
    int des = arg/10;
    int jed = arg%10;
    return des>jed ? des : jed;
}



int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for (int i=a;i<=b;i++){
        if (pom(i)!=0) {
            if (i % (pom(i)*pom(i)*pom(i)) == 0) {
                printf("%d ", i);
            }
        }
    }
    return 0;
}