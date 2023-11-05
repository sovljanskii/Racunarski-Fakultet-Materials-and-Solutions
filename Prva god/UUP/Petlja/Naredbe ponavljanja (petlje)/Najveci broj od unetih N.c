#include <stdio.h>
#include <limits.h>
/*
Napisati program koji pronalazi najveći od unetih n celih brojeva.
*/

int main(){
    int n;
    scanf("%d",&n);
    int max= INT_MIN;
    for (int i=0;i<n;i++){
        int br;
        scanf("%d",&br);
        if (br>max)max=br;
    }
    printf("%d",max);
    return 0;
}