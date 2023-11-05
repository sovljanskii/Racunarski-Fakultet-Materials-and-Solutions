#include <stdio.h>

/*
Napisati funkciju koja proverava da li je broj prost. Prost broj je broj koji je veci od 1,
a koji je devljiv samo sobom i brojem 1. Zatim, napisati program koji za unet prirodan broj N
ispisuje sve proste brojeve do broja N.
*/

int prost(int br){
    for (int i=2;i<=br/2;i++){
        if (br%i==0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=2;i<=n;i++){
        if (prost(i)){
            printf("%d ",i);
        }
    }

    return 0;
}