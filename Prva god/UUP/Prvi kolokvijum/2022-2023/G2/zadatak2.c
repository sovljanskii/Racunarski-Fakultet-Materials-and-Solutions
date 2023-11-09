#include <stdio.h>
#include <math.h>
/*
Upotrebom naredbe while i funkcijom getchar() za čitanje karaktera obraditi ulaznu
sekvencu koja se sastoji od slova, cifara i simbola tako da se brojevi koji su okruženi malim
zagradama ispišu tako da se svaka cifra u broju osim poslednje uveća za njenu susednu cifru
sa desne strane. Umesto brojeva koji su okruženi srednjim (uglastim) zagradama treba da se
ispiše ostatak pri deljenju kvadrata datog broja sa najvećom cifrom u tom broju. Ostale
karaktere ispisati bez izmene. Zagrade su pravilno otvorene i zatvorene, nema ugnježdenih
zagrada i nema praznih zagrada.
Napomena : Pri uvećavanju cifara, posmatrati rezultate ciklično (posle 9 ide opet 0 itd.).
Ograničenje : Posmatraju se samo pozitivni celi brojevi.
Primer: Ulaz : Az(12895)2*&c22[1414](241)[78]
Izlaz : Az(30745)2*&c22[0](651)[4]
 */
int main(){
    char c;
    int flag=0;
    int br=0;
    int rezbr=0;
    int max=0;
    while ((c=getchar())!='\n'){
        switch (c){
            case '(':
                putchar('(');
                flag=1;
                break;
            case '[':
                putchar('[');
                flag=2;
                break;
            case ')':
                br+=rezbr;
                printf("%d",br);
                putchar(')');
                rezbr=0;
                br=0;
                flag=0;
                break;
            case ']':
                printf("%d",(int)pow(br,2) % max);
                putchar(']');
                max=0;
                br=0;
                flag=0;
                break;
            default:
                if (c>='0'&&c<='9') {
                    if (flag==1) {
                        if (rezbr == 0) {
                            rezbr = c - '0';
                        } else {
                            if (c-'0'+rezbr>9){
                                br=br*10 + (c-'0'+rezbr-10)*10;
                            }
                            else br=br*10 + (c-'0'+rezbr)*10;
                        }
                        rezbr=c-'0';
                    }
                    else if (flag==2){
                        br=br*10 +c-'0';
                        if (c-'0'>max){
                            max=c-'0';
                        }
                    }
                    else putchar(c);


                }
                else putchar(c);
        }
    }

    return 0;
}
