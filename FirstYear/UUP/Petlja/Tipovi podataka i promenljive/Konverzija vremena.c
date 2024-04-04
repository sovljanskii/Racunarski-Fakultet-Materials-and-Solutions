#include <stdio.h>

/*
Napisati program koji vremenski interval dat u sekundama prikazuje u satima, minutima i sekundama.
*/

int main(){
    int s;
    scanf("%d",&s);
    printf("%d %d %d",s/3600,s/60%60,s%60);
    return 0;
}