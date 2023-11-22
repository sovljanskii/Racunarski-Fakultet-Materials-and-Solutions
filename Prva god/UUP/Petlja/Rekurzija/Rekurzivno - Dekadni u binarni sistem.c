#include <stdio.h>

/*
Napisati funkciju int dec2bin(int n) koja rekurzivno prebacuje broj iz sistema sa osnovom 10, u
odgovarajući broj sistema sa osnovom 2. U glavnoj funkciji testirati napisanu funkciju, podrazumevati
da korisnik unosi broj za koji se treba odraditi konverzija.
 */
int dec2bin(int n) {
    if (n<2)return n;
    return n%2+ dec2bin(n/2)*10;
}


int main(){
    int a;
    scanf("%d",&a);
    printf("%d", dec2bin(a));
    return 0;
}