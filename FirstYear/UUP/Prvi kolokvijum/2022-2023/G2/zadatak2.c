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
int brojSDesne(int n){
    int br=0;
     int step=1;
    int rezbr=0;
    while (n){
        int c=n%10;
        if (c+rezbr>=10)br=(c+rezbr-10)*step+br;
        else br=(c+rezbr)*step+br;  //3*1 3 , 2 2+3 * 10
        rezbr=c;
        step*=10;
        n/=10;
    }
    return br;
}
int srednajzaga(int n){
    int max=0;
    int rez=n;
    while (n){
        if (max<n%10)max=n%10;
        n=n/10;
    }
    n=rez;
    n=n*n%max;
    return n;
}
int main(){
    char c;
    int flag=0;
    int br=0;
    while ((c=getchar())!='\n'){
        if (c=='('){
            putchar(c);
            flag=1;
        }
        else if (c=='['){
            putchar(c);
            flag=2;
        }
        else if (c==')' || c==']'){
            if (flag==1){
                printf("%d", brojSDesne(br));
            }
            else if (flag=2){
                printf("%d", srednajzaga(br));
            }
            putchar(c);
            flag=0;
            br=0;
        }
        else {
            if (flag ==0){
                putchar(c);
            }
            else {
                br=br*10+c-'0';
            }

        }
    }
}
