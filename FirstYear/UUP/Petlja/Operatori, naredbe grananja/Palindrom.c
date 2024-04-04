#include <stdio.h>
#include <math.h>
/*
Napisati program koji za uneti četvorocifreni broj proverava da li je palindrom.
Broj je palindrom ako se čita isto spreda i odpozadi. Primer: 1221
*/

int main(){
    int n;
    scanf("%d",&n);
    if (n%10==n/1000 && n/100%10==n/10%10){
        printf("DA");
    }
    else printf("NE");
    return 0;
}