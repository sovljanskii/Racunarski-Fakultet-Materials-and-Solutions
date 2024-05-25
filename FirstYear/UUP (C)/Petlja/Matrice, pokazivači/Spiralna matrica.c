#include <stdio.h>


void printmat(int mat[][50],int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}


void spiralMat(int mat[][50],int n,int m){
    int flag=0;
    int br=1;
    int vrsta=0;
    int kolona=0;
    int step=0;
    while (br-1!=n*m){
        if (flag==0 && kolona==m-step){
            flag++;
            kolona--;
            vrsta=step+1;
        }
        else if (flag==1 && vrsta==n-step){
            flag++;
            vrsta --;
            kolona--;
        }
        else if (flag== 2 && kolona==-1+step){
            kolona++;
            vrsta--;
            flag++;
            step++;
        }
        else if (flag==3 && vrsta == -1+step){
            flag=0;
            kolona=step;
            vrsta++;
        }

        switch (flag) {
            case 0:
                mat[vrsta][kolona++] = br++;
                break;
            case 1:
                mat[vrsta++][kolona] = br++;
                break;
            case 2:
                mat[vrsta][kolona--] = br++;
                break;
            case 3:
                mat[vrsta--][kolona] = br++;
            break;
        }

    }

}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int mat[50][50];
    spiralMat(mat,n,m);
    printmat(mat,n,m);

    return 0;
}