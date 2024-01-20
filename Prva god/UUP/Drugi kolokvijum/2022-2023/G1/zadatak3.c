#include <stdio.h>
#include <string.h>
#define MAX 255

void obrisiRec(char *str,int a,int b){
    int i2=0;
    for (int i=0;str[i];i++){
        if (i>=a&&i<=b) continue;
        str[i2++]=str[i];
    }
    if (str[i2-1]== ' ') str[i2-1]=0;
    str[i2]=0;
}

int nadjiReci(char *str,int a,int b){
    char pocetno,zadnje;
    pocetno=str[0];
    for (int i=1;str[i-1];i++){
            if (str[i] == ' '||str[i]==0) {
                zadnje = str[i - 1];
                if (i!=b+1) {

                    if (pocetno == str[a] && zadnje == str[b]) {
                        return 1;
                    }
                }
                pocetno = str[i + 1];
            }
        }
    return 0;
}

void proveristr(char *str){
    int base=0;
    for (int i=1;str[i-1];i++){
        if (str[i]==' '||str[i]==0){
            if (!nadjiReci(str,base,i-1)){
                obrisiRec(str,base,i);
                i=1;
                base=0;
            }
            else base = i+1;
        }
    }
}

int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strlen(str)-1]=0;
    proveristr(str);
    fputs(str,stdout);
    return 0;
}