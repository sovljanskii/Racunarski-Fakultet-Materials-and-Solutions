#include <stdio.h>

/*
Napisati program koji za dva uneta broja ispisuje njihov zbir, razliku i količnik. Rezultate ispisati zaokružene na 2 decimale.
 */

int main(){
    float a,b;
    scanf("%f%f",&a,&b);
    printf("%.2f %.2f %.2f",a+b,a-b,a/b);
    return 0;
}