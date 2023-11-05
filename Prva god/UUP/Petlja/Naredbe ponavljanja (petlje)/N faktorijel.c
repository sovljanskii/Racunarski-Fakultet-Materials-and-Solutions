#include <stdio.h>
/*
Napisati program koji pronalazi najveći od unetih n celih brojeva.
*/

int main(){
    int n;
    scanf("%d",&n);
    int br=1;
    for (int i=1;i<=n;i++){
        br=br*i;
    }
    printf("%d",br);
    return 0;
}