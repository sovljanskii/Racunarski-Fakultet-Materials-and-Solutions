#include <stdio.h>

/*
Nacrtati sledeću figuru za unetu visinu n. Primer je za n=5:
11111
12222
12333
12222
11111
 */

int main(){
    int n;
    int x=0;
    int br=1;
    scanf("%d",&n);
    for (int i=0;i<n/2+1;i++){
        for (int j=0;j<n;j++){
            printf("%d",br);
            if (j<x){
                br++;
            }
        }
        x++;
        br=1;
        printf("\n");
    }

    for (int i=n/2+1;i<n;i++){
        br=1;
        x-=2;
        for (int j=0;j<n;j++){
            printf("%d",br);
            if (j<x){
                br++;
            }
        }

        printf("\n");
    }
}