#include <stdio.h>
#include <math.h>

double f4(int i, int n) {
    if (i == n) {
        return sqrt(n);
    }
    return sqrt(i + f4(i + 1, n));
}

double f4_i(int n) {
    double res = 0;
    for (int i = n; i > 0; i--) {
        res = sqrt(i + res);
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lf\n", f4(1, n));
    printf("%lf\n", f4_i(n));
    return 0;
}