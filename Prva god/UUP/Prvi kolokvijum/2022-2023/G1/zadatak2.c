#include <stdio.h>
#include <math.h>

/*
Upotrebom naredbe while i funkcijom getchar() za čitanje karaktera obraditi ulaznu
sekvencu koja se sastoji od slova i cifara tako da brojevi koji su okruženi identičnim
karakterom slova se ispišu tako da se svaka cifra u broju uveća za poziciju te cifre unutar
broja (cifra najveće težine ima poziciju 1 u broju). Umesto brojeva koji su okruženi
karakterom slova treba da se ispiše ostatak pri deljenju datog broja kvadratom broja cifara
 */

int brojCifri(int n){
    int br=0;
    while(n){
        br++;
        n/=10;
    }
    return br;
}

int main(){
    char c;
    char c_rez;
    int br=0;
    while ((c = getchar())!='\n'){
        if (c>='0'&&c<='9'){
            br=br*10+c-'0';
        }
        else {
            if (br!=0){
                if (c==c_rez){
                    int cif = brojCifri(br);
                    for (int i=0;i< brojCifri(br);i++){
                        br=br + cif*pow(10,i);
                        cif--;

                    }
                    printf("%d",br);
                }
                else {
                    printf("%d",br%(brojCifri(br)* brojCifri(br)));
                }
            }
            c_rez=c;
            br=0;
            putchar(c);
        }
    }
    return 0;
}