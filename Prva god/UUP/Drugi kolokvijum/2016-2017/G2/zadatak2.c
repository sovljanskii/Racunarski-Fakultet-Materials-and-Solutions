#include <stdio.h>
#include <math.h>
#define MAX 100

void printMat(int mat[][MAX],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
int brcifara(int n){
    int br=0;
    while(n){
        br++;
        n/=10;
    }
    return br;
}

void srediMat(int mat[][MAX],int n){
    int brcif = brcifara(n);
    for (int j=0;j<brcif;j++){
        int cif = n/ pow(10,brcif-1-j);
        cif%=10;
        mat[brcif-1][j] = cif;
    }
    int br=2;
    for (int i=brcif-2;i>=0;i--){
        for (int j=0;j<brcif;j++){
            mat[i][j]=(10+mat[i+1][j]+br)%10;
        }
        br = br==2 ? 1 : 2;
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int mat[MAX][MAX];
    srediMat(mat,n);
    printMat(mat, brcifara(n), brcifara(n));
}