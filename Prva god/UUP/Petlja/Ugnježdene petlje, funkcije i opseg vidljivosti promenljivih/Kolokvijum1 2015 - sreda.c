#include <stdio.h>
/*
Napisati program koji za uneto n=5 ispisuje sledeću figuru:

11111
12222
12333
12222
11111

*/
int min(int a,int b){
    if (a<b) return a;
    return b;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int br = min(min(i,j),n+1-i);

            printf("%d",br);
        }
        printf("\n");
    }
    return 0;
}