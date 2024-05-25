#include <stdio.h>
/*
Napisati program koji za uneti niz A, duzine N, formira nizove B i C tako da su elementi 
niza B parni članovi niza A, a elementi niza C su neparni članovi niza A.
*/
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int b[n],c[n],nb=0,nc=0;
    for (int i=0;i<n;i++){
        if (a[i]%2==0){
            b[nb++]=a[i];
        }
        else c[nc++]=a[i];
    }
    for (int i=0;i<nb;i++){
        printf("%d ",b[i]);
    }
    putchar('\n');
    for (int i=0;i<nc;i++){
        printf("%d ",c[i]);
    }
    return 0;
}