#include <stdio.h>

/*
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu
koja se sastoji od slova, cifara i zagrada. Program ispisuje sumu brojeva. Ako je broj unutar
zagrade formirati novi broj koji se sastoji od parnih pozicija i njega dodati u sumu. Ako je broj
van zagrada ili u ugnježdenim zagradama dodati na sumu obrnuti broj. Napomena, pozicije
cifara u broju računaju se sa leve strane, počevši od 1 (na primer u broju 13579 na poziciji 2
nalazi se cifra 3, na poziciji 4 nalazi se cifra 7).
Primer: Ulaz: md(q2345q(a31b)g141d)a41(sd45a)sad((145sda)1222)g
Izlaz: 634
 */

int brCifara(int arg){
    int br=0;
    while (arg){
        br++;
        arg/=10;
    }
    return br;
}
int samoParne(int arg){
    int brcif= brCifara(arg);
    int nule=1;
    int novibroj=0;
    while (arg){

        if (brcif%2==0){
            int c = arg%10;
            novibroj= novibroj + c*nule;
            nule*=10;
        }
        brcif--;
        arg/=10;
    }
    return novibroj;
}
int obrnut(int arg){
    int br=0;
    while(arg){
        int c=arg%10;
        br=br*10+c;
        arg/=10;

    }
    return br;
}


int main(){
    char c;
    int br=0;
    int zbir=0;
    int zagrade=0;
    while ((c=getchar())!='\n'){
        if (c=='('){
            if (br!=0){
                if (zagrade==1){
                    zbir+= samoParne(br);

                }
                else {
                    zbir+= obrnut(br);
                }
                br=0;
            }
            zagrade++;
            continue;
        }
        else if (c==')'){
            if (br!=0){
                if (zagrade==1){
                    zbir+= samoParne(br);

                }
                else {
                    zbir+= obrnut(br);
                }
                br=0;
            }
            zagrade--;
            continue;
        }
        else {
            if (c>='0'&&c<='9'){
                br=br*10+c-'0';
            }
            else if (br!=0){
                if (zagrade==1){
                    zbir+= samoParne(br);

                }
                else {
                    zbir+= obrnut(br);
                }
                br=0;
            }
        }
    }
    if (br!=0){
        if (zagrade==1){
            zbir+= samoParne(br);

        }
        else {
            zbir+= obrnut(br);
        }
        br=0;
    }
    printf("%d",zbir);
    return 0;
}