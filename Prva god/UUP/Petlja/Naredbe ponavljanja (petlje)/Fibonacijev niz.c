#include <stdio.h>
/*
Napisati program koji pronalazi najveći od unetih n celih brojeva.
*/

int main(){
    int n;
    scanf("%d",&n);
    int br=1;
    int br2=1;
    int rez;
    if (n<3) rez=1;
    for (int i=2;i<n;i++){
        rez=br+br2;
        br2=br;
        br=rez;

    }
    printf("%d",rez);
    return 0;
}