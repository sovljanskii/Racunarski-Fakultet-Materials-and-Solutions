#include <stdio.h>
/*
Napisati funkciju int zbir_cif_rek(int a) koja rekurzivno izračunava zbir cifara broja a.
Kasnije u glavnoj funkciji za uneti celi broj ispisati rezultat dobijen pozivom te funkcije.
*/

int zbir_cif_rek(int a){
    if (a==0) return 0;
    return a%10 + zbir_cif_rek(a/10);
}

int main(){
    int a;
    scanf("%d",&a);
    printf("%d",zbir_cif_rek(a));
    return 0;
}