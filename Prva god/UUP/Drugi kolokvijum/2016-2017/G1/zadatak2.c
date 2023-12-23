#include <stdio.h>
#include <math.h>

#define MAX 50

void printMat(int mat[][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int brcifri(int n) {
    int br = 0;
    while (n) {
        br++;
        n /= 10;
    }
    return br;
}

void makeMat(int mat[][MAX], int n) {
    int br = brcifri(n);

    for (int i = br - 1; i >= 0; i--) {
        mat[0][i] = n % 10;
        n /= 10;
    }
    for (int i = 1; i < br; i++) {
        for (int j = 0; j < br; j++) {
            if (i % 2) {
                mat[i][j] = (abs(mat[i - 1][j] + 10 - 1)) % 10;
            } else mat[i][j] = (abs(mat[i - 1][j] + 10 - 2)) % 10;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int mat[MAX][MAX];
    makeMat(mat, n);
    printMat(mat, brcifri(n), brcifri(n));
    return 0;
}