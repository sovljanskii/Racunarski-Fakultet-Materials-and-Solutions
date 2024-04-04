#include <stdio.h>
/*
Napisati program koji računa i ispisuje zbir brojeva iznad sporedne dijagonale date kvadratne matrice.
*/
void scanmat(int mat[][50],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

int zbiriznad(int mat[][50],int n){
    int zbir=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i+j<n-1){
                zbir+=mat[i][j];;
            }
        }
    }
    return zbir;
}

int main(){
int n;
    scanf("%d",&n);
    int mat[50][50];
    scanmat(mat,n,n);
    printf("%d", zbiriznad(mat,n));
    return 0;
}