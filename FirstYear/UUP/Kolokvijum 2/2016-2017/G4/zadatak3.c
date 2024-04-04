#include <stdio.h>
#include <string.h>
#define MAX 100

void srediStr(char *str){
    int base=0;
    for (int i=0;i<strlen(str);i++){
        if (str[i]=='-'){
            char temp = str[base];
            for (int j=base;j<i-1;j++){
                str[j] = str[j+1];
            }
            str[i-1]=temp;
            base=i+1;
        }
    }
    char temp = str[base];
    for (int j=base;j<strlen(str)-1;j++){
        str[j] = str[j+1];
    }
    str[strlen(str)-1]=temp;
}

int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strlen(str)-1]=0;
    srediStr(str);
    fputs(str,stdout);
    return 0;
}