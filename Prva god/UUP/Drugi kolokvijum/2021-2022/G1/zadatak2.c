////// Ne ispisuje jednu podmatricu iz nekog razloga..
#include <stdio.h>
#define MAX 255

void scanMat(int mat[][MAX],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
int podmat(int mat[][MAX],int i,int j,int a,int b){
    int ugao1= mat[i][j],ugao2=mat[i][b],ugao3=mat[a][j],ugao4=mat[a][b];
    for (int x=i;x<=a;x++){
        for (int y=j;y<=b;y++){
            if ((x==i&&y==j)||(x==i&&y==b)||(x==a&&y==j)||(x==a&&y==b)){
                continue;
            }
            if (mat[x][y] == ugao1 || mat[x][y]==ugao2 || mat[x][y]==ugao3||mat[x][y]==ugao4)return 0;
        }
    }
    return 1;
}

void proveriMat(int mat[][MAX],int n,int m){
    for (int i=0;i<=n-3;i++){
        for (int j=0;j<=m-3;j++){
            for (int a = i + 2,b = j + 2; a <= n,b<=m; a++,b++) {
                    if (podmat(mat, i, j, a, b)) {
                        printf("(%d, %d) dimenzija %d x %d\n", i, j, a - i + 1, b - j + 1);
                    }
                }
            }
        }
    }


int main(){
    int mat[MAX][MAX],m,n;
    scanf("%d%d",&n,&m);
    scanMat(mat,n,m);
    proveriMat(mat,n,m);
}
