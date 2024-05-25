#include <stdio.h>
#include <math.h>

double rek(int n, int i, int br){
    if (i>n){
        return 0;
    }
    if (i%2)
        return sqrt(br*1.0/((n-i+1)*2) + rek(n,i+1,br-9));
    return sqrt(1.0/((n-i+1)*2) + rek(n,i+1,br));
}

double ite(int n){

    double rez=0;
    for (int i=n;i>0;i--){
        int delilac = (n-i+1)*2;

        if (i%2==0){
            rez= sqrt(1.0/delilac+rez);
        }
        else {
            int br=n*10+1-i/2*9;
            rez = sqrt(1.0*br/delilac + rez);
        }
    }
    return rez;
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,1,n*10+1));
    printf("%lf", ite(n));
    return 0;
}