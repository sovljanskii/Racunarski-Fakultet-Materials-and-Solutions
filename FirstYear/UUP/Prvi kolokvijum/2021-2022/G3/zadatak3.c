#include <stdio.h>

int main(){

    int n;
    int br=0;
    int br2=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        if (i<n/2)br= br+br2;
        else if (i>n/2)br=br-br2;

        for (int j=0;j<n;j++){
            if((i>j||i>(n-j-1))&&(n-1-i>j || n-i>n-j)){
                putchar('a'+i);
            }
            else putchar('A'+br);


        }
        if (i<n/2-1)br2++;
        else if(i>n/2)br2--;

        printf("\n");
    }

    return 0;
}