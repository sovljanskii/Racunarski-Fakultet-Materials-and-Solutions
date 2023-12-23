#include <stdio.h>

void scanmat(int mat[][50],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
void printmat(int mat[][50],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int mat[50][50];
    scanmat(mat,n,m);
    int mat2[50][50];
    for (int j=0;j<m;j++){
        for (int i=0;i<n;i++){
            mat2[j][i] = mat[i][j];
        }
    }
    printmat(mat2,m,n);
    return 0;
}