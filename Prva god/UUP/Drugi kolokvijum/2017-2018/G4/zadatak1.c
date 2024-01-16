#include <stdio.h>

double rek(int n,int i,int j,int br){
    if (i==n-1) return j+i;
    return j+i+ 1.0*br/ rek(n,i+1,j+i,br-11);
}

double ite(int n){
    double rez;
    for (int i=n-1;i>=0;i--){
        int br=n;
        int gore = n*10+n-1;
        for (int j=1;j<=i;j++){
            br+=j;
            gore-=11;
        }
        if (i==n-1) rez=br;
        else rez = br +1.0*gore/rez;
    }
    return rez;
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,0,n,n*10+n-1));
    printf("%lf", ite(n));
    return 0;
}