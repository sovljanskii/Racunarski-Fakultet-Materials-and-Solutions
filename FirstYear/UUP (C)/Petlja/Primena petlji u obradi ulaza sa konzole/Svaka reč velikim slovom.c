#include <stdio.h>

/*
Napisati program kojim se ispisuje uneti tekst tako da svaka reč počinje velikim slovom.
*/

int main()
{
    char c;
    int prv=1;
    while ((c=getchar())!='\n'){
        if (c==' '){
            prv=1;
            putchar(c);
            continue;
        }
        if (prv){
            if (c>='a' && c<='z') c-=32;
            prv=0;
        }
         putchar(c);

    }
    return 0;
}