#include <stdio.h>
#include <math.h>
#define MAX 100

int brcifri(int n){
    int br=0;
    while (n){
        br++;
        n/=10;
    }
    return br;
}

void napraviMat(int mat[][MAX],int n){
    int brcif = brcifri(n);

    for (int i=0;i<brcif;i++){
        int cif = n/ pow(10,brcif-1-i);
        n%= (int)pow(10,brcif-1-i);
        int posle=0;
        for (int j=0;j<brcif;j++){

            if (i+j==brcif-1){
                mat[i][j]=cif;
                posle=1;
            }
            else {
                int br=(10+cif-(brcif-j-i)/2)%10;
                mat[i][j]=br;
                if (posle){
                    cif++;
                    posle=0;
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int mat[MAX][MAX];
    napraviMat(mat,n);
    int red= brcifri(n);
    for (int i=0;i<red;i++){
        for (int j=0;j<red;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
