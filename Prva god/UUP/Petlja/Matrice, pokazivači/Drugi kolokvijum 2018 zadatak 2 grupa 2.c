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

int brCifri(int n){
    int br=0;
    while (n){
        br++;
        n/=10;
    }
    return br;
}

void matrica(int mat[][MAX],int n){
    int brcif = brCifri(n);
    int br=1;
    for (int i=0;i<brcif;i++){
        for (int j=0;j<brcif;j++){
            if (i==brcif/2||i==brcif/2+i%2){
                int a=1.0*n/ pow(10,brcif-j-1);
                a= a% 10;
                mat[i][j]=a;
                br=-1;
            }
            else{
                int a=1.0*n/ pow(10,brcif-j-1);
                a= a% 10;
                mat[i][j]=(10+a+br)%10;
            }
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int mat[MAX][MAX];
    matrica(mat,n);
    printMat(mat, brCifri(n), brCifri(n));
}