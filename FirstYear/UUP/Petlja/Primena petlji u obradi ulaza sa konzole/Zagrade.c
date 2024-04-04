#include <stdio.h>

/*
Napisati program kojim se unosi tekst. Potrebno je izbaciti iz teksta zagrade i sve što je u njima.
*/

int main()
{
    char c;
    int flag=1;
    while ((c=getchar())!='\n'){
        switch (c) {
            case '(':
                flag=0;
                break;
            case ')':
                flag=1;
                break;
            default:
                if (flag){
                    putchar(c);
                }
        }

    }
    return 0;
}