#include <stdio.h>
#include <math.h>
double rek(int n, int br,int brp){
    if (n==0){
        return 0;
    }
    return sqrt(1.0*br/(n*2* pow(10,n-1))+ rek(n-1,br+brp,br));
}

double ite(int n){
    double rez=0;
    for (int i=n, x=1;i>0;i--,x++){
        int a=0;
        int br=1;
        for (int j=1;j<i;j++){
            int b=br;
            br+=a;
            a=b;
        }
        rez= sqrt(1.0*br/(x*2*pow(10,x-1))+rez);
    }
    return rez;
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,1,0));
    printf("%lf", ite(n));
    return 0;
}