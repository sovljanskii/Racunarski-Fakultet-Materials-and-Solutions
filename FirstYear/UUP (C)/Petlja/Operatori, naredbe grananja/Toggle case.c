#include <stdio.h>

/*
Napisati program koji za jedno učitano slovo ispisuje mali ili veliki pandan tog slova, 
u zavisnosti da li je uneto slovo veliko ili malo.
*/

int main(){
    char c;
    c=getchar();
    if (c>'Z') putchar(c-'a'+'A');
    else putchar (c+'a'-'A');
    return 0;
}