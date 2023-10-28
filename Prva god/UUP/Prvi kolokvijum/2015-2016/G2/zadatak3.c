#include <stdio.h>
/*
Nacrtati sledeću figuru za unetu visinu n. Primer je za n=5:
-->--
-<<<-
>>>>>
-<<<-
-->--
*/

void printSign(char sign, int times){
    for (int i=0;i<times;i++){
        putchar(sign);
    }
}

int main(){
    int n;
    char znak;
    scanf("%d",&n);
    for (int i=n/2;i>=0;i--){
        if (i%2) znak='<';
        else znak='>';
        printSign('-',i);
        printSign(znak,n-2*i);
        printSign('-',i);
        printf("\n");
    }
    for (int i=1;i<n/2+1;i++){
        if (i%2) znak='<';
        else znak='>';
        printSign('-',i);
        printSign(znak,n-2*i);
        printSign('-',i);
        printf("\n");
    }
    return 0;
}