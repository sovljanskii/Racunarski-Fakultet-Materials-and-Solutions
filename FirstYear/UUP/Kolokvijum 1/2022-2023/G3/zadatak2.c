#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu cifara, razmaka i zagrada. Izračunati zbir brojeva koji se nalaze unutar sekvence na
sledeći način. Ukoliko se brojevi nalaze unutar malih zagrada, na zbir se dodaje vrednost
najmanjeg broja iz trenutno razmatrane zagrade stepenovanog na broj brojeva unutar tih
istih zagrada. Ukoliko se brojevi nalaze unutar srednjih zagrada, na zbir se dodaje srednja
vrednost brojeva unutar trenutno razmatranih zagrada, zaokružena na prvi veći ili jednak ceo
broj. Ukoliko se broj ne nalazi unutar zagrada, njegova vrednost se direktno dodaje na zbir.
Podrazumevati da je unos zagrada pravilan, tj. da nema ugneždenih ili unakrsno otvaranih ili
zatvaranih zagrada.
Primer: Ulaz: (15 4 42) 21 4 [54 103 36]
Izlaz: 154
 */

int main(){
    int c;
    int flag=0;
    int zbir=0;
    int br=0,brbroj=0;
    int zbir2=0;
    int min= INT_MAX;
    while ((c= getchar())!='\n'){
        switch (c) {
            case '(':
                flag=1;
                break;
            case ')':
                brbroj++;
                if (br<min) min=br;
                zbir+= (int)pow(min,brbroj);
                br=0;
                flag=0;
                brbroj=0;
                break;
            case '[':
                flag=2;
                break;
            case ']':
                zbir2+=br;
                brbroj++;
                if (zbir2%brbroj!=0) zbir++;
                zbir+= zbir2/brbroj;
                flag=0;
                brbroj=0;
                br=0;
                zbir2=0;
                break;
            case ' ':
                if (flag==0){
                    zbir+=br;
                }
                else if (flag==1){
                    if (br<min) min=br;
                    brbroj++;
                }
                else{
                    zbir2+=br;
                    brbroj++;
                }

                br=0;
                break;
            default:
                br=br*10+c-'0';

        }

    }
    if (flag==0){
        zbir+=br;
    }
    printf("%d",zbir);
}