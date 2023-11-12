#include <stdio.h>

/*
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu slova tako da se proveri da li su zagrade [] i () pravilno zatvorene. Zagrade
mogu biti ugneždene jedna u drugu, s time da je dozvoljen samo jedan nivo
ugneždenosti. Ako su sve zagrade pravilno zatvorene, ispisati “ok”, inače “greska”.
 */


int main(){
    char c;
    int zagradaA=0;
    int zagradaB=0;
    int greska=0;
    while ((c=getchar())!='\n'){
        switch (c) {
            case '(':
                zagradaA=zagradaB+1;
                break;
            case ')':
                if (zagradaB>zagradaA){
                     greska=1;
                }
                zagradaA=0;
                break;
            case '[':
                zagradaB=zagradaA+1;
                break;
            case ']':
                if (zagradaA>zagradaB){
                    greska=1;

                }
                zagradaB=0;
                break;
        }
        if (greska){
            break;
        }
    }
    if (greska==0) {
        if ((zagradaA != 0 || zagradaB != 0)) printf("greska");
        else printf("ok");
    }
    else printf("greska");

    return 0;
}