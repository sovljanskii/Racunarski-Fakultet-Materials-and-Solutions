#include <stdio.h>
#include <string.h>
#define MAX 100



int main() {
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strlen(str)-1]=0;
    int length = strlen(str);
    for (int i=0;i<length*2;i+=2){
        for (int j=length*2;j>i;j--){
            str[j]=str[j-1];
        }

    }
    str[length*2]=0;
    fputs(str,stdout);
    return 0;
}
