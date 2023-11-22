#include <stdio.h>
/*
Napisati funkciju int pow_rek(int a, int b) koja rekurzivno izračunava b-ti stepen broja a. 
Kasnije u glavnoj funkciji za dva uneta prirodna broja ispisati rezultat dobijen pozivom te funkcije.
*/
int pow_rek(int a, int b){
    if (b==0) return 1;
    return a * pow_rek(a,b-1);
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d", pow_rek(a,b));
    return 0;
}