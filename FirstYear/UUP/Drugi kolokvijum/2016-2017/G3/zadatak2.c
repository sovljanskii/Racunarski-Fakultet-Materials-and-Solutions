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

void srediMat(int mat[][MAX],int mat2[][MAX],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int min=mat[i][j];
            for (int i2=0;i2<n;i2++){
                if (mat[i2][j]<min)min=mat[i2][j];
            }
            for (int j2=0;j2<m;j2++){
                if (mat[i][j2]<min)min=mat[i][j2];
            }
            mat2[i][j]=min;
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int mat[MAX][MAX];
    int mat2[MAX][MAX];
    scanMat(mat,n,m);
    srediMat(mat,mat2,n,m);
    printMat(mat2,n,m);
    return 0;
}