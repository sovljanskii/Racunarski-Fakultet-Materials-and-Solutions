#include <stdio.h>

/*
Napisati program u kojem se izbacuju samoglasnici iz unetog teksta.
*/

int main()
{
    char c;

    while ((c=getchar())!='\n'){
        switch (c){
        case 'a': case 'A': case 'e': case 'E': case 'i': case 'I': case 'o': case 'O': case 'u': case 'U':
            break;
            default: putchar(c);
            
        }
    }

    return 0;
}