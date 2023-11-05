#include <stdio.h>

/*
Korisnik unosi jedno slovo i jedan ceo broj k. Ispisati k-to slovo posle unetog slova.
*/

int main(){
    char ch;
    int k;
    scanf("%c%d",&ch,&k);
    printf("%c",ch+k);
    return 0;
}