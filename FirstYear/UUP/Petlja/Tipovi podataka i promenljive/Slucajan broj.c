#include <stdio.h>
#include <stdlib.h>
/*
Napisati program koji ispisuje slučajan broj iz intervala od n do m (interval [n,m]).
*/

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d",rand()%(m-n)+n);
    return 0;
}