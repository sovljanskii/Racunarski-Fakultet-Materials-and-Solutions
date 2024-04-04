#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n*2;i++){
        if (i==0||i==n*2-1){
            printf("+");
            if (i==0) {
                for (int j = 0; j < n - 1; j++) {
                    printf("-");
                }
            }
            else {
                for (int j = 0; j < n*2 - 2; j++) {
                    printf("-");
                }
            }
            printf("+");
        }
        else {
            printf("|");
            if (i<n) {
                for (int j = 1; j < n+ i+1; j++) {
                    if (i == j) printf("\\");
                    else if (j==n+i){
                        if (i==n-1){printf("+");}
                        else printf("\\");
                    }
                    else if(j==n*2-i-1){
                        printf("/");
                    }
                        else printf(".");
                }
            }
            else {
                for (int j=1;j<n*2;j++){
                    if (i==j) printf("\\");

                    else if (j==n*2-1){
                        printf("|");
                    }
                    else if (j==n*2-i-1){
                        printf("/");
                    }
                    else printf(".");
                }
            }
        }


        printf("\n");
    }
    return 0;
}