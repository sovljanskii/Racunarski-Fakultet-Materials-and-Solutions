#include <stdio.h>
#define MAX 100

void printMat(int mat[][MAX],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int brcifri(int n){
    int br=0;
    while (n){
        br++;
        n/=10;
    }
    return br;
}

void fun(int mat[][MAX],int n){
    int brc = brcifri(n);
    int rez=n;
    for (int i=brc-1;i>=0;i--){
        mat[i][brc-i-1]=rez%10;
        mat[i][i]=rez%10;
        rez/=10;
    }
    for (int i=0;i<brc;i++){
        int br=(10+mat[i][i]+1)%10;
        for (int j=0;j<brc;j++){
            if (i!=j && i+j!=brc-1){
                mat[i][j]=br;
            }
            else if ((i==j && i<brc/2) || (i+j==brc-1 &&i>brc/2)){
                br = (10+mat[i][i]-1)%10;
            }
            else if ((i+j==brc-1&&i<brc/2)||(i==j && i>=brc/2)){
                br=(10+mat[i][i]+1)%10;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int mat[MAX][MAX];
    fun(mat,n);
    printMat(mat, brcifri(n), brcifri(n));
    return 0;
}