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

void sortMat(int mat[][MAX],int n){
    for (int j=0;j<n;j++){
        for (int i=1;i<n;i++){
            int x = i-1;
            int key = mat[i][j];
            while (x>=0&&key<mat[x][j]){
                mat[x+1][j] = mat[x][j];
                x--;
            }
            mat[x+1][j]=key;
        }
    }
    for (int j=0;j<n;j++){
        for (int j2=0;j2<n-1-j;j2++){
            if (mat[n-1][j2]<mat[n-1][j2+1]){
                for (int a=0;a<n;a++){
                    int temp = mat[a][j2];
                    mat[a][j2] = mat[a][j2+1];
                    mat[a][j2+1] = temp;
                }
            }
        }
    }
}

int main(){
    int n=5;
    int mat[MAX][MAX];
    scanMat(mat,n,n);
    sortMat(mat,n);
    printMat(mat,n,n);
}