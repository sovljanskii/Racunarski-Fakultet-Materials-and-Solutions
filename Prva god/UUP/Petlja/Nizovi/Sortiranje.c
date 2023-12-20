#include <stdio.h>
/*
Napisati program koji za dati niz A, dužine N, 
ispisuje sortirani niz A u neopadajucem poretku.
*/
void sort(int *m,int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            if (m[j]>m[j+1]){
                int temp = m[j];
                m[j] = m[j+1];
                m[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int m[n];
    for (int i=0;i<n;i++){
        scanf("%d",&m[i]);
    }
    sort(&m[0],n);
    for (int i=0;i<n;i++){
        printf("%d ",m[i]);
    }
}