#include <stdio.h>
/*
Napisati program koji za dati niz A, dužine N i K veličina "prozora" 
pravi novi niz B na sledeci nacin: 
B[i] = A[i], ako je i + 1 < K B[i] = (A[i] + A[i-1] + ... + A[i - K + 1]) / K
*/
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    int b[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }

    for (int i=n-1;i>k-2;i--){
        int sum=0;
        for (int j=i-k+1;j<=i;j++){
            sum+=b[j];
        }
        b[i]=sum/k;
    }
    for (int i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    return 0;
}