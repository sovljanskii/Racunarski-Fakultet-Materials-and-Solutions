#include <stdio.h>

void scanmat(int mat[][50],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void sortirajKolone(int mat[][50],int n,int m){

    for (int j=0;j<m;j++){
        for (int i=1;i<n;i++){
            int key = mat[i][j];
            int ij=i-1;
            while(ij>=0 && mat[ij][j] >key){
                mat[ij+1][j] = mat[ij][j];
                ij--;
            }
            mat[ij+1][j]=key;
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
    sortirajKolone(mat,n,m);
    printmat(mat,n,m);
    return 0;
}