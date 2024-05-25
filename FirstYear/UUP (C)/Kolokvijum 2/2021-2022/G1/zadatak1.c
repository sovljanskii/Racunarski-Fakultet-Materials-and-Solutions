#include <stdio.h>
#include <math.h>

double rek(int n,int i){
    if (i>n) return 0;
    if (i%2) return sqrt(1.0*i/(i+1)+rek(n,i+1));
    return i*sqrt(1.0*i/((i+1)*(i+1))+ rek(n,i+1));
}

double ite(int n){
    double rez=0;
    for (int i=n;i>0;i--){
        if (i%2) rez= sqrt(1.0*i/(i+1)+rez);
        else rez= i*sqrt(1.0*i/((i+1)*(i+1))+rez);
    }
    return rez;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,1));
    printf("%lf", ite(n));
    return 0;
}