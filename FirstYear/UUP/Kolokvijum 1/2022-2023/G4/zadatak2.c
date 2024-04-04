#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu koja se sastoji od cifara, razmaka i zagrada. Izračunati zbir brojeva koji se nalaze
unutar sekvence, pri čemu se od brojeva u malim zagradama na zbir dodaje samo vrednost
najmanjeg parnog broja, od brojeva u velikim zagradama vrednost razlike najvećeg i
najmanjeg broja, dok se brojevi van zagrada normalno dodaju na zbir. Zagrade ne mogu biti
ugnježdene.
Primer: Ulaz: {32 53 12} (31 6 2) 123 {355} (3 7)
Izlaz: 166
 */


int main(){
    char c;
    int flag=0;
    int min= INT_MAX;
    int max = INT_MIN;
    int zbir=0;
    int br=0;
    while ((c=getchar())!='\n'){
        switch (c){
            case '{':
                flag=1;
                break;
            case '(':
                flag=2;
                break;
            case '}':

                    if (br<min) min=br;
                    if (br>max) max=br;

                zbir+=(max-min);
                max = INT_MIN;
                min= INT_MAX;

                flag=0;
                br=0;
                break;
            case ')':
                if (br%2==0 && br<min){
                        min=br;
                    }
                if (min!=INT_MAX) zbir += min;
                min= INT_MAX;
                flag=0;
                br=0;
                break;
            case ' ':
                if (flag==0){
                    zbir=zbir+br;
                }
                else if (flag==1){
                    if (br<min) min=br;
                    if (br>max) max=br;
                }
                else {
                    if (br%2==0 && br<min){
                        min=br;
                    }
                }
                br=0;
                break;
            default:
                br=br*10+c-'0';
            break;
        }

    }
    if (flag==0){
        zbir=zbir+br;
    }
    printf("%d",zbir);
    return 0;
}