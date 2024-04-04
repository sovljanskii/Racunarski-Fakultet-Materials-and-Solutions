#include <stdio.h>
#include <math.h>
/*
Napisati program koji za unetu godinu proverava da li je prestupna.
Godina je prestupna kada je deljiva sa 400 ili kada je deliva sa 4 a nije deljiva sa 100.
*/

int main(){
    int god;
    scanf("%d",&god);
    if ((god%4==0&&god%100!=0)||god%400==0){
        printf("DA");
    }
    else printf("NE");
    return 0;
}