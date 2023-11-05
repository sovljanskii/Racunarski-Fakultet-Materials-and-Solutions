#include <stdio.h>
#include <math.h>
/*
Napisati program koji za uneti trocifreni broj proverava da li je Armstrongov.
Broj je Armstrongov ako je jednak zbiru kubova svojih cifara. Primer: 371 = 3^3 + 7^3 + 1^3
*/

int main(){
    int n;
    scanf("%d",&n);
    int arm=pow(n/100,3) + pow(n/10%10,3) + pow(n%10,3);
    if (n==arm) printf("DA");
    else printf("NE");
    return 0;
}