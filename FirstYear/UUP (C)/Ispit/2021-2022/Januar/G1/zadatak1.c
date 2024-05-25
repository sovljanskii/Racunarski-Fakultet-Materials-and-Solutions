#include <stdio.h>

#define MAX 255

void scanMat(int mat[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMat(int mat[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void makeNewMat(int A[][MAX], int B[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int max = 0;
            for (int j2 = j - 1, i2 = i + 1; j2 >= 0 && i2 < n; j2--, i2++) {
                if (A[i2][j2] > max) max = A[i2][j2];
            }
            for (int j2 = j + 1, i2 = i + 1; j2 < n && i2 < n; j2++, i2++) {
                if (A[i2][j2] > max) max = A[i2][j2];
            }
            for (int j2 = j + 1, i2 = i - 1; j2 < n && i2 >= 0; j2++, i2--) {
                if (A[i2][j2] > max) max = A[i2][j2];
            }
            for (int j2 = j - 1, i2 = i - 1; j2 >= 0 && i2 >= 0; j2--, i2--) {
                if (A[i2][j2] > max) max = A[i2][j2];
            }
            B[i][j] = max;
        }
    }
}

int main() {
    int n, A[MAX][MAX];
    scanf("%d", &n);
    scanMat(A, n);
    int B[MAX][MAX];
    makeNewMat(A, B, n);
    printMat(B, n);
    return 0;
}