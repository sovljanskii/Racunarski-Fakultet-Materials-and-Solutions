#include <stdio.h>

void ispisi(int n, int mat[][100]) {
    int i, j;
    for (i = 0; i < n; i++, putchar('\n'))
        for (j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
}

void formiraj_mat(int n, int mat[][100]){
	int i, j;
	for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i > j) {
            	mat[i][j] = 3;
            } else if (i == j) {
            	mat[i][j] = 2;
            } else {
            	mat[i][j] = 1;
            }
        }
	}
}

int main() {
    int mat[100][100], n;
    scanf("%d", &n);
    formiraj_mat(n, mat);
    ispisi(n, mat);
    return 0;
}
