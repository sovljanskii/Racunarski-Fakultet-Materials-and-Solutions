#include <stdio.h>

/*
Napisati program koji odredjuje K-ti prost broj.
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
    int k;
    int b=0;
    scanf("%d",&k);
    for (int i=2;i;i++){
        if (prost(i)){
            b++;
        }
        if (b==k){
            printf("%d",i);
            break;
        }
    }

    return 0;
}