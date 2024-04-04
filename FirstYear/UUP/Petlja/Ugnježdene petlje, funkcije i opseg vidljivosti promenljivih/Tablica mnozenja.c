#include <stdio.h>

/*
Implementirati program koji za dva uneta broja, N i M, ispisuje tablicu množenja.
*/

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            printf("%4d",i*j);
        }
        printf("\n");
    }
    return 0;
}