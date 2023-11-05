#include <stdio.h>

/*
Napisati program koji ulaz sa tastature ispisuje na ekranu kao tekst šifrovan Cezarovom šifrom. 
(Za uneto slovo A-ispisuje se slovo D, tj. treće po redu iza slova A). 
Beline i interpunkcijski znaci ostaju nepromenjeni.
*/

int main()
{
    char c;
    while ((c=getchar())!='\n'){
        if (c>='A'&&c<'X'||c>='a'&&c<'x'){
            putchar(c+3);
        }
        else if (c>='X'&&c<='Z'||c>='x'&&c<='z'){
            putchar(c-23);
        }
        else putchar(c);
    }

    return 0;
}