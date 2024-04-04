#include <stdio.h>
#include <math.h>

double rek(int n,int i,int br){
    if (br>n) return 0;
    if (br%2) return sqrt(1.0*i/((n-i+1)*(n-i+1))+ rek(n,i,br+1));
    return sqrt(1.0*(n-i+1)/(i*i)+ rek(n,i+1,br+1));
}

double ite(int n){
    double rez=0;
    int neparno=n/2+n%2;
    for (int i=n;i>0;i--){
        if (i%2){
            rez= sqrt(1.0*neparno/((n-i/2)*(n-i/2))+rez);
            neparno--;
        }
        else {
            rez= sqrt((n+1-1.0*i/2)/((i/2)*(i/2))+rez);
        }
    }

    return rez;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,1,1));
    printf("%lf", ite(n));
    return 0;
}