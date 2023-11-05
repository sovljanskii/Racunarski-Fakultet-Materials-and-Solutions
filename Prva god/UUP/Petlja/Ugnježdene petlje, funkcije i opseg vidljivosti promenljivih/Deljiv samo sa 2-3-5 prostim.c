#include <stdio.h>

/*
Napisati program koji ispisuje u rastućem poretku prvih N prirodnih brojeva koji imaju osobinu 
da ih ne deli niti jedan prosti broj osim 2, 3 i 5.
*/

int prost(int br){
    if (br==1) return 0;
    for (int i=2;i<=br/2;i++){
        if (br%i==0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    int deli=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            if (j!=2 && j!=3 && j!=5 && prost(j)){
                if (i%j==0){
                    deli=1;
                    break;
                }
            }
        }
        if (!deli) printf("%d ",i);
        deli=0;
    }

    return 0;
}