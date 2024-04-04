#include <stdio.h>
#include <stdlib.h>
/*
Napisati program koji za unete cele brojeve n, m i k izračunava 
nasumičan broj iz intervala [n,m], koji je deljiv sa k.
*/

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int br = rand()%(m-n)+n+k;
    br= br-br%k;
    printf("%d",br);
    return 0;
}