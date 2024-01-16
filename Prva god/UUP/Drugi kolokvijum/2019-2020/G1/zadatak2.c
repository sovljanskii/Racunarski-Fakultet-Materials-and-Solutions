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

/*
1 1 2
0 0 2
3 3 3
 */
void spiralMat(int mat[MAX][MAX],int n,int m){
    int step=0;
    int br=0;
    int flag=0;
    int vrsta=0,kolona=0;
    while (br++<m*m){
        switch (flag) {
            case 0:
                mat[vrsta][kolona++] = n;
                break;
            case 1:
                mat[vrsta++][kolona] = n;
                break;
            case 2:
                mat[vrsta][kolona--] = n;
                break;
            case 3:
                mat[vrsta--][kolona] = n;
                break;
        }
        if (flag==0 && kolona==m-step){
            flag++;
            kolona--;
            n=(10+n+1)%10;
            br--;

        }
        else if (flag==1 && vrsta==m-step){
            flag++;
            vrsta --;
            n=(10+n+1)%10;
            br--;

        }
        else if (flag== 2 && kolona==-1+step){
            kolona++;
            flag++;
            step++;
            n=(10+n+1)%10;
            br--;

        }
        else if (flag==3 && vrsta == -1+step){
            flag=0;
            vrsta++;
            n=(10+n+1)%10;
            br--;
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int mat[MAX][MAX];
    spiralMat(mat,n,m);
    printMat(mat,m,m);
}