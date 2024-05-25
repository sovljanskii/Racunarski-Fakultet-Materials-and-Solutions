#include <stdio.h>

/*
Napisati funkciju pom(int arg, int delilac) koja vraća broj dobijen kada se iz argumenta arg uklone
sve cifre koje su deljive argumentom delilac (delilac je u opsegu [2,9]).
Zatim koriscenjem funkcije pom ispisati sve brojeve iz intervala koji unosi korisnik
koji nemaju parnu cifru (sve cifre su neparne)
*/

int pom(int arg, int delilac){
    int br=0,step=1;
    while (arg!=0){
        int c=arg%10;
        if (c%delilac!=0){
            br+=c*step;
            step*=10;
        }
        arg/=10;
    }
    return br;
}


int main()
{
    int a,b;
    int delilac=2;
    scanf("%d%d",&a,&b);
    for (int i=a;i<=b;i++){
        if (i==pom(i,delilac)){
            printf("%d\n",i);
        }
    }
    return 0;
}