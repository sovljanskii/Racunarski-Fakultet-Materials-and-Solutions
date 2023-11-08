#include <stdio.h>
#include <math.h>
/*
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu slova, cifara i zagrada. Izračunati zbir brojeva koji se nalaze unutar sekvence, pri
čemu se vrednosti brojeva koji se nalaze unutar malih zagrada posmatraju kao negativni, a
vrednosti brojeva koji se nalaze unutar velikih zagrada se utrostruče pre nego što se dodaju
u zbir. Ukoliko se neki broj nalazi unutar oba tipa zagrada, potrebno je primeniti obe
transformacije.
Primer: Ulaz: md({3}g)a(sd5a)sad{(10sda)12}g11
Izlaz: 3
 */

int main(){
    char c;
    int male=0;
    int velike=0;
    int zbir=0;
    int br=0;
    while ((c=getchar())!='\n'){
        switch (c) {
            case '(':
                if (male==0&&velike==0){
                    zbir+=br;
                    br=0;
                }
                male=1;
                break;
            case '{':
                if (male==0&&velike==0){
                    zbir+=br;
                }
                velike =1;
                break;
            case '}':
                if (male){
                    br=br*-1;

                }
                br*=3;
                zbir+=br;
                br=0;
                velike=0;
                break;
            case ')':
                if (velike) {
                    br*=3;
                }
                br = br * -1;
                zbir+=br;
                br=0;
                male=0;
                break;
            default:
                if (c>='0'&&c<='9')
                    br=br*10+c-'0';

        }
    }
    if (male==0&&velike==0){
        zbir+=br;
    }
    printf("%d",zbir);
    return 0;
}