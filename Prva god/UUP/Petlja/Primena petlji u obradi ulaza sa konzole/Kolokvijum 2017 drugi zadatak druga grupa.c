#include <stdio.h>
#include <math.h>
/*
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu slova i cifara, i
izračunati zbir brojeva koji se nalaze između dva slova koji su u ASCII taebli udaljeni najvise do 2 mesta
(uključujući 2).
*/

int main()
{
    char c,cifrapre;
    int br=0;
    int zbir=0;
    while ((c=getchar())!='\n'){
        if (c>='0'&&c<='9'){
            br=br*10+c-'0';
        }
        else {
            if (br!=0){
                if (abs(c-cifrapre)<3){
                    zbir+=br;
                }
                br=0;
            }
            cifrapre=c;
        }
    }
    printf("%d",zbir);
    return 0;
}