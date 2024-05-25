#include <stdio.h>
/*
Napisati program koji pronalazi najveći od unetih n celih brojeva.
*/

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int b2=0;
    int br=0;
    while (a-b>b2){  //21 4 8 12 16 20 24
        b2+=b;
        br++;
    }
    printf("%d",a-b2);
    return 0;
}