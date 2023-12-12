#include <stdio.h>
#include <math.h>

double rekurzivno(int n, int a, int b) {
    if (a == 0) {
        return 0;
    }
    int max = a > b ? a : b;
    return sqrt(1.0 * max / pow(b, 2) + rekurzivno(n, a - 1, b + 1));
}

double iterativno(int n) {
    double rez = 0;
    for (int i = n, j = 1; i > 0; i--, j++) {
        int max = i > j ? i : j;
        rez = sqrt(1.0 * max / pow(i, 2) + rez);
    }
    return rez;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivno(n, n, 1));
    printf("%lf", iterativno(n));
    return 0;
}