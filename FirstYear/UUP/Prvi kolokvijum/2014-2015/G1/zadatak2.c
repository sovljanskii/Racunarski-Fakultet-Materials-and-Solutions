#include <stdio.h>
/*
Koristeći naredbu while za obradu teksta izbaciti svako slovo koje je susedno
prethodno ispisanom slovu (susedna=slova koja se nalaze jedno pored drugog u
ASCII tabeli) iz unetog teksta.
primer: AbDfghjk
rezultat: ADfj
*/

int main(){
    char c;
    char prosli=-1;
    while((c= getchar())!='\n'){
        if (c!=prosli-1&&c!=prosli+1&&c!=prosli+33&&c!=prosli-33){
            putchar(c);
        }
        prosli=c;
    }

    return 0;
}