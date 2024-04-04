#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    char c='A';
    int br=n-1;
    for (int i=0;i<n;i++){
        if (i%3==0) c++;
        for (int j=0;j<n;j++){
            if (i%2==0){
                if(j==br){
                    putchar(c+1);
                }
                else putchar(c);

            }
            else {
                if (j%2){
                    putchar(c+1);
                }
                else putchar(c);
            }

        }
        if (i%2) br--;
        printf("\n");
    }

}