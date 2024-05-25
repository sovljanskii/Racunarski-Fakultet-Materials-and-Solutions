#include <stdio.h>

double rek(int n, int i, int br){
    if (i==n){
        if (i%2) return br;
        return 1;
    }
    if (i%2)
        return br+ ((n-i+1)*2)/rek(n,i+1,br-9);
    return 1+((n-i+1)*2)/rek(n,i+1,br);
}

double ite(int n){

    double rez=0;
    for (int i=n;i>1;i--){
        int gore = (n-i+2)*2;
        if (i%2==0){
            rez= 1.0*gore/(1+rez);
        }
        else {
            int br=n*10+1-i/2*9;
            rez = 1.0*gore/(br + rez);
        }
    }
    rez+=n*10+1;
    return rez;
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,1,n*10+1));
    printf("%lf", ite(n));
    return 0;
}