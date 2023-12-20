#include <stdio.h>
/*
Napisati program koji za dati niz A, dužine N, ispisuje svaki element u suprotnom redosledu.
*/
int main(){
    int n;
    scanf("%d",&n);
    int m[n];
    for (int i=0;i<n;i++){
        scanf("%d",&m[i]);
    }
    for (int i=n-1;i>=0;i--){
        printf("%d ",m[i]);
    }
}