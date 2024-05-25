#include <stdio.h>
#include <math.h>


/////HALF FUNCTIONAL
double rek(int n,int i,int br1,int br2){
    if(br1==1){
        return br1-br2;
    }
    if (i%2) return br1-1.0*br2/ rek(n,i+1,br1,br2);
    return br2+1.0*br1/ rek(n,i+1,br1/2,br2*2);
}

double ite(int n){
    int br1=1,br2=pow(2,n/2-1);
    double res=br1-br2;
    int i=2;
    br1=n/pow(2,(n/2-2)); br2/=2;
    while(i<n-1){
        if (i%2){
            res = br1-br2/res;
            br1=n/ pow(2,(n-i-2)/2);
            br2/=2;
        }
        else {
            res = br2+br1/res;
        }
        i++;
    }
    res = br1-br2/res;

    return res;
}



int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,1,n,1));
    printf("%lf", ite(n));
}