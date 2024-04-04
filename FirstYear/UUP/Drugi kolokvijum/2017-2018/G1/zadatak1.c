#include <stdio.h>
#include <math.h>

double rek(int n,int i,int j){
    if (n==0) return 0;
    if (i%2) return sqrt(1.0*j/(n*2)+ rek(n-1,i+1,j-1));
    return sqrt(1.0*(i/2)/(n*2)+ rek(n-1,i+1,j));
}

double ite(int n){
    double res=0;
    int br1=n-(n-1)/2;
    int br2=n/2;
    int dole=2;
    for (int i=n;i>0;i--){
        if (i%2==0){
            res=sqrt(1.0*br2/dole+res);
            br2--;
        }
        else{
            res=sqrt(1.0*br1/dole+res);
            br1++;
        }
        dole+=2;
    }
    return res;
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,1,n));
    printf("%lf", ite(n));
    return 0;
}