#include <stdio.h>

/*
Potrebno je da za uneto N ispisati kvadratnu figuru koja po svojim rubovima ima zvezdice,
a ostalo je popunjeno prazninama. Primer za uneto n = 5:

*****
*   *
*   *
*   *
*****
*/

int main()
{
    int n;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i==0||j==0 || i==n-1|| j==n-1){
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}