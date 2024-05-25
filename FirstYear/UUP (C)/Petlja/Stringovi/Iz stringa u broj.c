#include <stdio.h>
#include <string.h>
#define MAX 100

void ascii(char *s){
    int length = strlen(s);
    for (int i=0;s[i];i+=3){
        for (int j= length+2;j>i;j--){ ////
            s[j]=s[j-2];
        }
        int br = (int)s[i];
        int br1=br/100;
        int br2=br/10%10;
        int br3=br%10;
        s[i]=br1+'0';
        s[i+1]=br2+'0';
        s[i+2]=br3+'0';
        length+=2;
    }
    s[length]=0;

}

int main() {
    char s[MAX];
    fgets(s,MAX,stdin);
    s[strlen(s)-1]=0;
    ascii(s);
    fputs(s,stdout);

    return 0;
}
