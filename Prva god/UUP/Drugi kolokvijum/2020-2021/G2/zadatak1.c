#include <stdio.h>

double rek(int n,int br,int i,int j){
    if (br==n){
        if (br%2) return 'A' + br/2;
        return 'A' + n -br/2;
    }
    int max = i>j?i:j;
    if (br%2) return 'A' +br/2 + max/ rek(n,br+1,i-1,j+1);
    return 'A' + n -br/2 + max/ rek(n,br+1,i-1,j+1);
}

double ite(int n){
    double rez;
    int br1 = n/2,br2=2-n/2-n%2;
    rez='A' + n/2;
    for (int i=n-1;i>0;i--){
        int max = br1 > br2 ? br1 : br2;
        if (i%2){
            rez = 'A' + i/2 + 1.0*max/rez;
        }
        else {
            rez = 'A' + n - i/2 + 1.0*max/rez;}
        br1--;br2++;
    }
    return rez;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n", rek(n,1,n/2,1-n/2));
    printf("%lf", ite(n));
    return 0;
}