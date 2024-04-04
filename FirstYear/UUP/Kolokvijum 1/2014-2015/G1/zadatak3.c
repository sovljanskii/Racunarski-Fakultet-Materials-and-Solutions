#include <stdio.h>
/*
Nacrtati sledeću figuru za unetu visinu n. Primer je za n=5:
<<<<<
->>>-
--<--
->>>-
<<<<<
*/

void printSign(char sign, int times){
    for (int i=0;i<times;i++){
        putchar(sign);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char znak;
    for (int i=0;i<n/2+1;i++){
        if (i%2)znak='>';
        else znak='<';
        printSign('-',i);
        printSign(znak,n-i*2);
        printSign('-',i);
        printf("\n");
    }
    for (int i=n/2-1;i>=0;i--){
        if (i%2)znak='>';
        else znak='<';
        printSign('-',i);
        printSign(znak,n-i*2);
        printSign('-',i);
        printf("\n");
    }

    return 0;
}