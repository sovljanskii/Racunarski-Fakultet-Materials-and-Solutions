#include <stdio.h>
/*
Napisati program koji za dati niz A, dužine N ispisuje najduži palindromski podniz. Palindromski podniz je niz uzastopnih elemenata nekog niza za koje vazi da se isto čita sa obe strane.

NAPOMENA Ukoliko dva palindromska podniza imaju isti broj elemenata, ispisati palindromski podniz koji se prvo pojavljuje.
*/
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int maxi,maxj;
    int maxcounter=0;
    for (int i=0;i<n;i++){

        for (int j=i+maxcounter;j<n;j++){

            int palindrom=1;
            for (int k=0;k<(j-i)/2;k++){

                if (a[i+k]==a[j-k]) continue;
                palindrom = 0;
                break;
            }
            if (palindrom && j-i>maxcounter){
                maxi=i;maxj=j;
                maxcounter=j-i;
            }
        }
    }
    for (int i=maxi;i<=maxj;i++){
        printf("%d ",a[i]);
    }
    return 0;
}