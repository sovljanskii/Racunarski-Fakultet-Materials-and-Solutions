#include <stdio.h>

/*
Implementirati program koji za dva uneta broja, N i M, ispisuje tablicu množenja.
*/

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i+j>=n-1){
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}