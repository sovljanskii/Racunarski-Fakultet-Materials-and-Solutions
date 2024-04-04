#include <stdio.h>

int min(int a,int b){
    return a<b? a:b;
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n*2+1;i++){
        if (i==0||i==n*2){
            putchar('*');
            putchar('\n');
            continue;
        }
        putchar('*');
        for (int j=1;j<=min(i,2*n-i);j++){
            printf("%d",j);
        }
        for (int j=min(i,2*n-i)-1;j>0;j--){
            printf("%d",j);
        }
        putchar('*');
        putchar('\n');
    }
    return 0;
}