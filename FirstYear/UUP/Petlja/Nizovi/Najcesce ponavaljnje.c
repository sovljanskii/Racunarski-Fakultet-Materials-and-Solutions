#include <stdio.h>
/*
Napisati program koji iz datog niza A, duzine N, pronalazi element koji se najviš puta pojavljuje. 
Ispisati element i broj ponavljanja tog elementa.

NAPOMENA Ukoliko dva elementa ili vise elemenata ima istu učestalost, ispisati najmanji element. 
Ukoliko se element 1 pojavljuje 2 puta i element 2 pojavaljuje 2 puta program ispisuje 1
*/
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int max=0,maxbr=0;
    for (int i=0;i<n;i++){
        int ucestalost=0;
        for (int j=0;j<n;j++){
            if (a[i]==a[j]){
                ucestalost++;
            }
        }

        if (ucestalost>maxbr){
            maxbr=ucestalost;
            max=a[i];
        }
        else if (ucestalost==maxbr){
            if (a[i]<max) max=a[i];
        }
    }
    printf("%d %d",max,maxbr);
    return 0;
}