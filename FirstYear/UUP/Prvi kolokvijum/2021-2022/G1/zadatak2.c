#include <stdio.h>
/*
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu slova, cifara i zagrada. Izračunati zbir brojeva koji se nalaze unutar sekvence, pri
čemu se vrednosti brojeva koji se nalaze unutar malih zagrada udvostruče, a vrednosti
brojeva koji se nalaze unutar velikih zagrada kvadriraju pre nego što se dodaju u zbir. Ukoliko
se neki broj nalazi unutar oba tipa zagrada, potrebno je operacije množenja sa dva i
kvadriranja izvršiti redosledom od unutrašnje ka spoljašnjoj.
Primer: Ulaz: md({3}g)a(sd5a)sad{(10sda)12}g11
Izlaz: 583
 */


int main(){
    char c;
    int male=0;
    int velike=0;
    int br=0;
    int zbir=0;
    while ((c=getchar())!='\n'){
        switch (c) {
            case '(':
                if (br!=0)zbir+=br;
                br=0;
                male=1;
                break;
            case '{':
                if (br!=0)zbir+=br;
                br=0;
                velike=1;
                break;
            case ')':
                br*=2;
                if (velike==1){
                    br*=br;
                }
                zbir+=br;
                male=0;
                br=0;


                break;
            case '}':
                br*=br;
                if (male==1){
                    br*=2;
                }
                zbir+=br;
                velike=0;
                br=0;

                break;
            default:
                if(c>='0'&&c<='9'){
                    br=br*10+c-'0';
                }

        }

    }
    zbir+=br;
    printf("%d",zbir);
    return 0;
}