#include <stdio.h>

/*
Nacrtati sledeću figuru za unetu visinu n. Primer je za n=5:
12345
1234-
-234-
-23--
–-3--
 */



int main(){
    int n;
    int y=0;
    int x=0;
    scanf("%d",&n);
    for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            if (j<x+1||n-y<j){
                printf("-");
            }

            else printf("%d",j);

        }
        if (i%2) y++;
        else x++;
        printf("\n");
    }

    return 0;
}