#include <stdio.h>
#include <math.h>

double rek(int n,int i,int j){
    if (i>n){
        return 0;
    }
    if (j==0) j=3;
    return sqrt(i*j+ rek(n,i+1,j-1));
}

int nadjibr(int br){
    int x=1;
    for (int i=0;i<br;i++){
        switch (x) {
            case 3:
                x=2;
                break;
            case 2:
                x=1;
                break;
            case 1:
                x=3;
                break;
        }
    }
    return x;
}

double ite(int n){
    double rez=0;
    for (int i=n;i>0;i--){
        int br= nadjibr(i);
        rez= sqrt(i*br+rez);

    }
    return rez;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,1,3));
    printf("%lf", ite(n));
    return 0;
}