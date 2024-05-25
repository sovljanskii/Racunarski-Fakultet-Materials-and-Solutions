#include <stdio.h>
#include <string.h>
#define MAX 100

void sredi(char *s){
    int length = strlen(s);
    for (int i=1;s[i];i++){
        if (s[i]!=s[i-1]){
            for (int j=length;j>i;j--){
                s[j]=s[j-1];
            }
            s[i]='-';
            i++;
            length++;
            s[length]=0;
        }
    }
    s[length] = '-';
    s[length+1] = 0;

}

int main() {
    char s[MAX];
    fgets(s,MAX,stdin);
    s[strlen(s)-1]=0;
    sredi(s);
    fputs(s,stdout);
    return 0;
}
