#include <stdio.h>
#include <string.h>
#define MAX 100

void obrni(char *s){
    for (int i=0;i< strlen(s)/2;i++){
        char temp = s[i];
        s[i] = s[strlen(s)-1-i];
        s[strlen(s)-1-i] = temp;
    }
}

int main() {
    char s[MAX];
    fgets(s,MAX,stdin);
    s[strlen(s)-1]=0;
    obrni(s);
    fputs(s,stdout);

    return 0;
}
