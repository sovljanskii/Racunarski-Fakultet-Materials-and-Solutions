#include <stdio.h>
/*
(7p) Nacrtati sledeću figuru za unetu vrednost n.
Primer za n = 5: Primer za n = 6:

....^.... .....^.....
.../*\... ..../*\....
../***\.. .../***\...
./*****\. ../*****\..
---***--- ./*******\.
..|***|.. ----***----
..|***|.. ...|***|...
..|***|.. ...|***|...
..-----.. ...|***|...
...|***|...
...-----...

*/
void printSign(char sign,int times){
    for (int i=0;i<times;i++){
        putchar(sign);
    }
}

int main(){
    int n;
    int sred = (n+2)/2;
    scanf("%d",&n);
    for (int j=0;j<n;j++){
        printSign('.',n-j-1);
                if (j==n/2){
            sred = (n*2-1)-(2*(n-j-1))-2;
        }
        if (j==0) printf("^");

        else {
            printf("/");
            printSign('*',(n*2-1)-(2*(n-j-1))-2);
            printf("\\");
        }
        printSign('.',n-j-1);
        printf("\n");
        }

    printSign('-',((n*2-1)-sred)/2);
    printSign('*',sred);
    printSign('-',((n*2-1)-sred)/2);
    printf("\n");
    for (int i=0;i<n-1;i++){
        printSign('.',((n*2-1)-sred)/2-1);
        printf("|");
        printSign('*',sred);
        printf("|");
        printSign('.',((n*2-1)-sred)/2-1);
        printf("\n");
    }
    return 0;
}
