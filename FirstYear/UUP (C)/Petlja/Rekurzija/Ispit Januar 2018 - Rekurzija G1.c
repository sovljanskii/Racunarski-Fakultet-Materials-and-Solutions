#include <stdio.h>
#include <math.h>
double rek(int n,int i, int br,int brp){
    if (i==n-1){
        return br;
    }
    return br+(n-i)*2* pow(10,i)/ (rek(n,i+1,br+brp,br));

}

double ite(int n){
    double rez=0;
    for (int i=n;i>1;i--){
        int br=1;
        int a=0;
        for (int j=1;j<i;j++){
            int b=br;
            br+=a;
            a=b;
        }
        rez = 1.0*(n-i+2)*2* pow(10,i-2)/(br+rez);
    }
    rez++;
    return rez;
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,0,1,0));
    printf("%lf", ite(n));
    return 0;
}