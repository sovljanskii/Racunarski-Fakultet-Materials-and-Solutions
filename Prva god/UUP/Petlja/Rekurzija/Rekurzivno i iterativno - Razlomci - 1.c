#include <stdio.h>

/*
Napisati rekurzivnu funkciju double f1(int n) i iterativnu funkciju double f1_i(int n)
koja za uneto n = 6 izracunava sledeci razlomacki izraz:
 */

double f1(int n){
    if (n==1) return 1;
    return n+1.0/(f1(n-1));
}
double f1_i(int n){
    double rez=0;
    for (int i=1;i<n;i++){
        rez= 1.0/(i+rez); // 1/(3+1/(2+1/1)
    }
    rez+=n;
    return rez;
}


int main(){
    double a;
    scanf("%lf",&a);
    printf("%lf\n", f1(a));
    printf("%lf", f1_i(a));
    return 0;
}