#include <stdio.h>

void printSign(char sign,int times){
    for (int i=0;i<times;i++){
        putchar(sign);
    }
}

int main(){
    int n;
    int sred=1;
    scanf("%d",&n);
    int sirina=n*2-1; //
    for (int k=1;k<(n-1)/2;k++){
        sred+=2;
    }
    printSign('.',(sirina-sred-2)/2);
    printSign('-',sred+2);
    printSign('.',(sirina-sred-2)/2);
    printf("\n");
    for (int i=0;i<n-2;i++){
        printSign('.',(sirina-sred-2)/2);
        putchar('|');
        printSign('*',sred);
        putchar('|');
        printSign('.',(sirina-sred-2)/2);
        printf("\n");
    }
    int brzvezdica=sirina-2;
    for (int i=0;i<n-1;i++){
        printSign('.',i);
        putchar('\\');
        printSign('*',brzvezdica);
        putchar('/');
        printSign('.',i);
        brzvezdica-=2;
        printf("\n");
    }
    printSign('.',n-1);
    putchar('v');
    printSign('.',n-1);
    return 0;
}
