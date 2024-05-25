#include <stdio.h>

/*
Napisati program za obradu teksta koji sabira brojeve u ogledalu unutar teksta.
*/

int main()
{
    char c;
    int br=0;
    int zbir=0;
    int step=1;
    while ((c=getchar())!='\n'){
        if (c>='0'&&c<='9'){
            br=br+(c-'0')*step;
            step*=10;
        }
        else {
            zbir+=br;
            br=0;
            step=1;
        }

    }
    zbir+=br;
    printf("%d",zbir);
    return 0;
}