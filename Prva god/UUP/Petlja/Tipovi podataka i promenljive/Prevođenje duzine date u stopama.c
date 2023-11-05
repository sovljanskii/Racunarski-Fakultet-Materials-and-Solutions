#include <stdio.h>

/*
Napisati program koji prevodi dužinu datu u stopama u centimetre (1 stopa = 30.48 cm). Rezulat ispisati zaokružen na 2 decimale.
*/

int main(){
    float a;
    scanf("%f",&a);
    printf("%.2f",a*30.48);
    return 0;
}