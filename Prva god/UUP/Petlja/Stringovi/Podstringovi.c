#include <stdio.h>
#include <string.h>
#define MAX 100



int main() {
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strlen(str)-1]=0;
    for (int i=0;i< strlen(str);i++){
        for (int j=i;j< strlen(str);j++){
            for (int k=i;k<=j;k++){
                putchar(*(str+k));
            }
            putchar('\n');
        }

    }
    return 0;
}
