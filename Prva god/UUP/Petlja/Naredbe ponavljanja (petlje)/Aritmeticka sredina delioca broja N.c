#include <stdio.h>
/*
Napisati program koji pronalazi najveći od unetih n celih brojeva.
*/

int main(){
    int n;
    int zbir=0;
    int br=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        if (n%i==0){
            zbir+=i;
            br++;
        }
    }
    printf("%.2f",1.0*zbir/br);
    return 0;
}