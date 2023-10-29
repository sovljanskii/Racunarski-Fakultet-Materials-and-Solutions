#include <stdio.h>

/*
 Koristeći naredbu while za obradu teksta, ispisati trocifren broj koji se sastoji od 3
poslednje cifre u ulaznom tekstu.
primer: ABC3DF5HFD6GFD7
rezultat: 567
 */

int main(){
    int a=0, b=0, c=0;
    char ch;
    while ((ch=getchar())!='\n'){
        if (ch >='0' && ch<='9'){
            a=b;
            b=c;
            c=ch-'0';
        }
    }
    int rez = a*100+b*10+c;
    printf("%d",rez);
    return 0;
}