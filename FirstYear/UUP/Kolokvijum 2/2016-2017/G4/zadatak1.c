#include <stdio.h>
#include <math.h>
double rek(int n,int i){
    if (i==n) return i;
    return i+pow(-1,i+1)*(n*2-i*2+2)/ rek(n,i+1);
}

double ite(int n){
    double res=0;
    for (int i=n;i>1;i--){
        res=(n-i+2)*2/(i+ pow(-1,i+1)*res);
    }
    res+=1;
    return res;
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,1));
    printf("%lf", ite(n));
    return 0;
}