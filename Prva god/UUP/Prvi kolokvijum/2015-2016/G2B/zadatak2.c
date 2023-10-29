#include <stdio.h>

/*
Koristeći naredbu while za obradu teksta, ispisati tekst na način prikazan u
primeru.
primer: c3-e5-d10
rezultat: ccc-eeeee-dddddddddd
 */



int main(){
    char c,c2=' ';
    int br=0;
    while ((c=getchar())!='\n'){
        if (c>='0' && c<='9'){
            br=br*10+c-'0';
        }
        else if (c=='-'){
            for (int i=0;i<br;i++){
                printf("%c",c2);
            }
            printf("-");
            br=0;
        }
        else c2=c;
    }
    for (int i=0;i<br;i++){
        printf("%c",c2);
    }
    return 0;
}