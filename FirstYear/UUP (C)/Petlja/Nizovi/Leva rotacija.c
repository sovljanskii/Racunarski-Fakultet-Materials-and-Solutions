#include <stdio.h>
/*
Napisati program koji iz datog niza A, dužine N, izvršava K levih roacija na nizu. 
Leva rotacija je operacija na nizu dužine N koji pomera elemente niza u levo. 
Na primer, ako se na niz {1, 2, 3, 4, 5} izvrse 2 leve rotacije, onda niz postaje {3, 4, 5, 1, 2}
*/

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<k;i++){
        int temp = a[0];
        for (int j=0;j<n-1;j++){
            a[j]=a[j+1];
        }
        a[n-1] = temp;
    }
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}