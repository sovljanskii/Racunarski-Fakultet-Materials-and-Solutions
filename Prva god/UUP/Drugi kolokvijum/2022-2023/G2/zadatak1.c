#include <stdio.h>

double rek(int n,int i,int levo,int gore){
    if (i>n) return 1;
    if (i%4==0) return levo+1.0*gore/ rek(n,i+1,n+1-(levo+2),levo+2);
    if (i%2==0) return levo+1.0*gore/ rek(n,i+1,gore+2,n+1-(gore+2));
    return levo+1.0*gore/ rek(n,i+1,levo,gore);
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%lf", rek(n,1,n,1));
    return 0;
}