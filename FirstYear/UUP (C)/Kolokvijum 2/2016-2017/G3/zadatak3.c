#include <stdio.h>
#include <string.h>
#define MAX 100

void srediStr(char *str){
    int base=0;
    for (int i=0;i<strlen(str);i++){
        if (str[i]=='-'){
            char temp = str[i-1];
            for (int j=i-1;j>base;j--){
                str[j] = str[j-1];
            }
            str[base]=temp;
            base=i+1;
        }
    }
    char temp = str[strlen(str)-1];
    for (int j=strlen(str)-1;j>base;j--){
        str[j] = str[j-1];
    }
    str[base]=temp;
}

int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strlen(str)-1]=0;
    srediStr(str);
    fputs(str,stdout);
    return 0;
}