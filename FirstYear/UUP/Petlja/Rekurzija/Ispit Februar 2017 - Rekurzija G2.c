#include <stdio.h>
#include <math.h>

double rek(int i, int n,int br, int brp){
    if (i==n){
        if (i%2) return sqrt(br*1.0/ pow(2,n-i+1));
        return sqrt(br);
    }
    if (i%2){
        return sqrt(br*1.0/ pow(2,n-i+1)+ rek(i+1,n,br+brp,br));
    }
    return sqrt(br+ rek(i+1,n,br+brp,br));
}


double ite(int n){
    double res=0;
    for (int i=n;i>0;i--){
        int br=1;
        int a=0;
        for (int j=1;j<i;j++){
            int b=br;
            br+=a;
            a=b;
        }

        if (i%2==0){
            res = sqrt(br+res);
        }
        else {
            res=sqrt(br/pow(2,n-i+1)+res);
        }
    }
    return res;
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(1,n,1,0));
    printf("%lf", ite(n));
    return 0;
}