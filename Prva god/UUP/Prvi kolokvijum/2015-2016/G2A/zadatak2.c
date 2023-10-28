#include <stdio.h>

/*
Koristeći naredbu while za obradu teksta ,ispisati tekst na način prikazan u
primeru.
primer: 10A3B1C
rezultat: AAAAAAAAAABBBC
 */

int main(){
    int br=0;
    char c;
    while ((c= getchar())){
        if (c>='0'&&c<='9'){
            br=br*10+c-'0';
            continue;
        }
        for (int i=0;i<br;i++){
            putchar(c);
        }
        br=0;
    }
    return 0;
}