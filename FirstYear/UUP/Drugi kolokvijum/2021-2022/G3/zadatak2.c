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
        putchar('\n');
    }
}

int nadjiMax(int mat[][MAX],int n,int c){
    int max=mat[0][c];
    for (int i=1;i<n;i++){
        if (max<mat[i][c]) max=mat[i][c];
    }
    return max;
}

void rotirajMat(int mat[][MAX],int n,int c){
    int brpon= nadjiMax(mat,n,c);
    for (int br=0;br<brpon;br++){
        int temp=mat[n-1][c];
        for (int i=n;i>0;i--){
            mat[i][c]=mat[i-1][c];
        }
        mat[0][c]=temp;
    }
}


void proveraMat(int mat[][MAX],int n,int m){
    for (int j=0;j<m;j++){
        int palindrom=1;
        for (int i=0;i<n/2;i++){
            if (mat[i][j]==mat[n-1-i][j]) continue;
            palindrom=0;break;
        }
        if (!palindrom){
            rotirajMat(mat,n,j);
        }
    }
}



int main(){
    int n,m,mat[MAX][MAX];
    scanf("%d%d",&n,&m);
    scanMat(mat,m,n);
    proveraMat(mat,m,n);
    printMat(mat,m,n);
    return 0;
}