#include <stdio.h>
#define MAX 100

int brcifara(int n){
    int br=0;
    while (n){
        br++;
        n/=10;
    }
    return br;
}

void printMat(int mat[][MAX],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int napraviMat(int mat[][MAX],int n){
    int brc = brcifara(n);
    for (int i=brc-1;i>=0;i--){
        mat[i][brc-1-i] = n%10;
        n/=10;
    }
    for (int i=0;i<brc-1;i++){
        int br=(10+mat[i][brc-1-i]-1)%10;
        for (int j=brc-2-i,a=0;j>=0;j--,a++){
            mat[i][j]= br;
            if(a%2) br--;
        }
    }
    for (int i=1;i<brc;i++){
        int br=(10+mat[i][brc-i-1])%10;
        for (int j=brc-i,a=0;j<brc;j++,a++){
            mat[i][j] = br;
            if(a%2==0) br=(10+br+1)%10;
        }
    }

}


int main(){
    int n;
    scanf("%d",&n);
    int mat[MAX][MAX];
    napraviMat(mat,n);
    printMat(mat, brcifara(n), brcifara(n));
    return 0;
}