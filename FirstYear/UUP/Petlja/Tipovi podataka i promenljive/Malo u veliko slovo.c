#include <stdio.h>

/*
Napisati program koji za uneto malo slovo ispisuje to isto veliko slovo na standardni izlaz.
*/

int main(){
    char ch;
    scanf("%c",&ch);
    printf("%c",ch-('a'-'A'));
    return 0;
}