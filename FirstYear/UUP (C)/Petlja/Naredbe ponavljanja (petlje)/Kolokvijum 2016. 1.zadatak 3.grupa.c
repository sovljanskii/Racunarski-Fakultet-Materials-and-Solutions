#include <stdio.h>

/*
Napisati funkciju pom(int arg, int k) koja vraća broj dobijen kada se iz argumenta arg uklone sve cifre manje od k
(vratiti nula ako se izbace sve cifre). Sabrati brojeve koje vraća ova funkcija za 3 broja koja korisnik unese, i za k=5.
*/

int pom(int arg,int k){
    int step=1;
    int br=0;
    while (arg!=0){
        int c=arg%10;
        if (c>=k){
            br+=step*c;
            step*=10;
        }
        arg/=10;
    }
    return br;
}

int main()
{
    int a;
    int k=5;
    int zbir=0;
    for (int i=0;i<3;i++){
        scanf("%d",&a);
        zbir +=pom(a,k);
    }
    printf("%d",zbir);
    return 0;
}