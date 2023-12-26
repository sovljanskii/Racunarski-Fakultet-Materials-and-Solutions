#include <stdio.h>
#define MAX 100

void scanMat(int mat[][MAX],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
void printMat(int mat[][MAX],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void srediMat(int mat[][MAX],int mat2[][MAX],int n, int m){

    for (int j=0;j<m;j++){
        for (int i=0;i<n;i++){
            if (j==0){
                mat2[i][j] = mat[i][j+1];
            }
            else if (j==m-1){
                mat2[i][j] = mat[i][j-1];
            }
            else mat2[i][j] = mat[i][j-1] + mat[i][j+1];
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int mat[MAX][MAX],mat2[MAX][MAX];
    scanMat(mat,n,m);
    srediMat(mat,mat2,n,m);
    printMat(mat2,n,m);
    return 0;
}