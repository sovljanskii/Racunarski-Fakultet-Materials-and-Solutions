#include <stdio.h>
#include <math.h>
/*
Napisati funkciju pom(int arg) koja vraća k-ti stepen kvadrata zbira svih cifara na
neparnim pozicijama broja arg, gde je k ukupan broj cifara prosleđenog broja. Pozicije
cifara brojati od 1 sleva nadesno (najznačajnija cifra ima poziciju 1).
Ispisati sve brojeve koje korisnik unese tako da su iz njih izbačene sve cifre koje se pojavljuju
u broju koji za njih vrati funkcija pom. Korisnik unosi brojeve sve dok ne unese 0.
*/

int pom(int args){
    int brcifara=0;
    int rez=args;
    int zbir=0;
    while (rez){
        brcifara++;
        rez/=10;
    }

    for (int i=0;i<brcifara;i++){
        if (i%2==0){ // 123/10
            zbir+=args/(int)pow(10,brcifara-1-i);

        }

        args=args%(int)pow(10,brcifara-i-1);
    }

    return (int)pow(zbir,brcifara);
}

int oduzmiBroj(int b) {

    int a=pom(b);
    int result = 0;
    int multiplier = 1;

    while (b > 0) { 
        int digit = b % 10; 
        int tempA = a;  
        int found = 0;  

        while (tempA > 0) {
            int aDigit = tempA % 10;
            if (aDigit == digit) {
                found = 1;
                break;
            }
            tempA /= 10;
        }

        if (!found) {
            result += digit * multiplier;
            multiplier *= 10;
        }

        b /= 10;
    }

    return result;
}



int main(){
    int n;
    scanf("%d",&n);
    while (n!=0){
        printf("%d\n",oduzmiBroj(n));
        scanf("%d",&n);
    }
    return 0;
}