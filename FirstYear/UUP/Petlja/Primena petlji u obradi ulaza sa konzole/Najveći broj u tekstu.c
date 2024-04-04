#include <stdio.h>

/*
Napisati program koji pronalazi najveći broj u unetom tekstu.
*/

int main()
{
    char c;
    int max=0;
    int br=0;
    while ((c=getchar())!='\n'){
        if (c>='0' && c<='9'){
            br=br*10+c-'0';
        }
        else {
            if (br>max) max=br;
            br=0;
        }
    }
    printf("%d",max);

    return 0;
}