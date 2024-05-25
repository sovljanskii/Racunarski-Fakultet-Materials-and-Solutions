#include <stdio.h>
/*
Napisati program koji nalazi i ispisuje minimalni element u datoj matrici.
*/
void scanmat(int mat[][50],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

int nadjimin(int mat[][50],int n,int m){
    int min=mat[0][0];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (min>mat[i][j]) min=mat[i][j];
        }
    }
    return min;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int mat[50][50];
    scanmat(mat,n,m);
    printf("%d",nadjimin(mat,n,m));
    return 0;
}