#include <stdio.h>
#include <string.h>
#define MAX 256

void moveleft(char *str,int base,int i){
    int j=0;
    for (;str[i+1+j];j++){
        str[base+j] = str[i+1+j];
    }
    str[base+j]=0;
}

void srediStr(char *str,int n){
    int base=0;
    int br=0;
    for (int i=0;str[i];i++){
        if (str[i]==' '){
            if (br<n){
                moveleft(str,base,i);
            }
            else {
                base=i+1;
            }
            br=0;
            i=base;
        }
        else br++;
    }
}

int main(){
    char str[MAX];
    int n=5;
    fgets(str,MAX,stdin);
    str[strlen(str)-1]=0;
    srediStr(str, n);
    fputs(str,stdout);
}