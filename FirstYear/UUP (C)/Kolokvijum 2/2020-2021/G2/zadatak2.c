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

void srediMat(int mat[][MAX],int mat2[][MAX],int n){
    for (int i=0;i<n;i++){
        mat2[n-i-1][i] = mat[i][i];
        mat2[n-i-1][n-i-1] = mat[i][n-i-1];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i!=j && i+j!=n-1){
                int max=0;
                int top=mat[i-1][j];
                int bottom = mat[i+1][j];
                int left = mat[i][j-1];
                int right = mat[i][j+1];
                max = top>max && top%2==0? top : max;
                max = bottom>max && bottom%2==0 ? bottom : max;
                max = left>max && left%2==0 ? left : max;
                max = right>max && right%2==0? right : max;
                mat2[i][j]=max;
            }
        }
    }
}

int main(){
    int n,mat[MAX][MAX];
    scanf("%d",&n);
    scanMat(mat,n,n);
    int mat2[MAX][MAX];
    srediMat(mat,mat2,n);
    printMat(mat2,n,n);
    return 0;
}