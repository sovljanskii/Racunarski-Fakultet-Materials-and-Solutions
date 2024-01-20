#include <stdio.h>

int faktorijel(int n){
    if (n==1) return 1;
    return n*faktorijel(n-1);
}

double rekurzivno(int n,int i){
    if (i>n) return 1;
    if (i%2) return (n-i+1)*2+ 1.0*faktorijel(i)/ rekurzivno(n,i+1);
    return faktorijel(i) + (n-i+1)*2/ rekurzivno(n,i+1);
}

int iteFaktorijel(int n){
    int rez=1;
    for (int i=n;i>0;i--){
        rez=rez*i;
    }
    return rez;
}

double iterativno(int n){
    double rez=1;
    for (int i=n;i>0;i--){
        int fakt= iteFaktorijel(i);
        if (i%2==0) rez=fakt+(n-i+1)*2/rez;
        else rez=(n-i+1)*2+fakt/rez;
    }
    return rez;
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rekurzivno(n,1));
    printf("%lf", iterativno(n));
    return 0;
}