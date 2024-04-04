#include <stdio.h>

void ucitaj(int n, int m, int mat[][100]) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
}

// Funkcija vraca 1 ako se matrica mat2 dimenzija (n2, m2) sadrzi u mat1 dimenzija (n1, m1). U suprotnom vraca 0.
int mat_sadrzi(int n1, int m1, int mat1[][100], int n2, int m2, int mat2[][100]) {
    int i, j, k, l, found;
    if (n2 > n1 || m2 > m1) return 0;
    for (i = 0; i + n2 - 1 < n1; i++){
        for (j = 0; j + m2 - 1 < m1; j++) {
            found = 1;
            for (k = 0; k < n2; k++){
                for (l = 0; l < m2; l++){
                    if (mat2[k][l] != mat1[i + k][j + l]) {
                        found = 0;
                    }
                }
            }
            if (found) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int mat1[100][100], n1, m1, mat2[100][100], n2, m2;
    scanf("%d %d", &n1, &m1);
    ucitaj(n1, m1, mat1);
    scanf("%d %d", &n2, &m2);
    ucitaj(n2, m2, mat2);
    if (mat_sadrzi(n1, m1, mat1, n2, m2, mat2)){
    	printf("DA");
    } else {
    	printf("NE");
    }
    return 0;
}
