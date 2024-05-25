#include <stdio.h>

/*
Napisati program koji za unet prirodni broj 
N crta sledeću figuru (u primeru N=4):

1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
*/

int main()
{
    int n;
    int br=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        br=i;
        for (int j=0;j<n;j++){
            if (br>n){
                br=1;
            }
            printf("%d ",br);
            br++;
        }
        printf("\n");
    }
    return 0;
}