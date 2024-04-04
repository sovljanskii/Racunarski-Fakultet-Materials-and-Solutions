#include <stdio.h>
#include <math.h>

double rek(int n,int i){
    if (n==1){
        return 1;
    }
    return n+ sqrt(i%2+1)/ rek(n-1,i+1);
}
double ite(int n){
    double rez=1;
    for (int i=n-1;i>0;i--){
        rez = (n-i+1)+ sqrt(2-i%2)/rez;

    }
    return rez;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,0));
    printf("%lf", ite(n));
    return 0;
}