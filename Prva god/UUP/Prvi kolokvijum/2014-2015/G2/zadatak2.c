#include <stdio.h>
/*
Koristeći naredbu while za obradu teksta promeniti u veliko slovo svako slovo
koje je susedno prethodno ispisanom slovu (susedna=slova koja se nalaze jedno
pored drugog u ASCII tabeli) iz unetog teksta. Korisnik unosi samo mala
primer: abdfghjk
rezultat: aBdfGHjK
*/

int main(){
    char c;
    char prosli=-1;
    while ((c=getchar())!='\n'){
        if (c==prosli+1||c==prosli-1){
            c-=32;
            prosli=c+32;
        }
        else prosli=c;

        putchar(c);

    }
    return 0;
}