#include <stdio.h>

/*
Nacrtati sledeću figuru za unetu visinu n. Primer je za n=5:
–-C--
--CD-
-BCD-
-BCDE
ABCDE
 */

void printSign(char sign,int times){
    for (int i=0;i<times;i++){
        putchar(sign);
    }
}

int main(){
    int n;

    scanf("%d",&n);
    char c;
    int x=0;int y=0;
    for (int i=0;i<n;i++){
        c='A'+n/2;
        printSign('-',n/2-x);
        for (int i=x;i>0;i--){
            putchar(c-i);
        }
        putchar(c);
        for (int i=1;i<=y;i++){
            putchar(c+i);
        }
        printSign('-',n/2-y);
        if (i%2)x++;
        else y++;
        printf("\n");
    }
    return 0;
}