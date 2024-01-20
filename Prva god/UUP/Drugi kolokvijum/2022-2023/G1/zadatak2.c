#include <stdio.h>
#define MAX 255

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

void func(int mat[][MAX],int n){
    for (int i=0;i<n/2;i++){
            for (int k = 0; k < n * n; k++) {
                for (int j = i; j < n - 1 - i; j++) {

                    if ((mat[i][j] > mat[i][j + 1] && i % 2 == 0) || (mat[i][j] < mat[i][j + 1] && i % 2)) {
                        int temp = mat[i][j];
                        mat[i][j] = mat[i][j + 1];
                        mat[i][j + 1] = temp;
                    }
                }
                for (int j = i; j < n - 1 - i; j++) {
                    if ((mat[j][n - 1 - i] > mat[j + 1][n - 1 - i] && i % 2 == 0) ||
                        (mat[j][n - 1 - i] < mat[j + 1][n - 1 - i] && i % 2)) {
                        int temp = mat[j][n - 1 - i];
                        mat[j][n - 1 - i] = mat[j + 1][n - 1 - i];
                        mat[j + 1][n - 1 - i] = temp;
                    }
                }
                for (int j = n - 1 - i; j > i; j--) {
                    if ((mat[n - 1 - i][j] > mat[n - 1 - i][j - 1] && i % 2 == 0) ||
                        (mat[n - 1 - i][j] < mat[n - 1 - i][j - 1] && i % 2)) {
                        int temp = mat[n - 1 - i][j];
                        mat[n - 1 - i][j] = mat[n - 1 - i][j - 1];
                        mat[n - 1 - i][j - 1] = temp;
                    }
                }
                for (int j = n - 1 - i; j > 1 + i; j--) {
                    if ((mat[j][i] > mat[j - 1][i] && i % 2 == 0) || (mat[j][i] < mat[j - 1][i] && i % 2)) {
                        int temp = mat[j][i];
                        mat[j][i] = mat[j - 1][i];
                        mat[j - 1][i] = temp;
                    }
                }
            }
            }
        }
int main(){
    int n,mat[MAX][MAX];
    scanf("%d",&n);
    scanMat(mat,n,n);
    func(mat,n);
    printMat(mat,n,n);
    return 0;
}