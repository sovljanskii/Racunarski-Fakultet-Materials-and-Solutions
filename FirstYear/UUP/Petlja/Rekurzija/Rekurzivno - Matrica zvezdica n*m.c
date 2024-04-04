#include <stdio.h>

/*
Napisati funkciju void matrica_zvezdica(int n, int m) koja
rekurzivno ispisuje matricu veličine n*m koja je popunjena zvezdicama.U
glavnoj funkciji testirati napisanu funkciju,
podrazumevati da korisnik unosi dužinu i širinu matrice.
 */

void matrica_zvezdica(int n,int m){
    if (n==0) return;
    for (int i=0;i<m;i++) printf("*");
    putchar('\n');
    matrica_zvezdica(n-1,m);
}

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    matrica_zvezdica(n,m);
    return 0;
}