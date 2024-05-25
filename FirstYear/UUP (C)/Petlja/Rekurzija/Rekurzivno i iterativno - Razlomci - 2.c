#include <stdio.h>

double f2(int i, int n) {
    if (i == n) {
        return n;
    }
    return i + 1.0 / f2(i + 1, n);
}

double f2_i(int n) {
    double res = 0;
    for (int i = n; i > 1; i--) {
        res = 1.0 / (i + res);
    }
    res++;
    return res;
}


int main() {
    int n;
    scanf("%d", &n);
    printf("%lf\n", f2(1, n));
    printf("%lf\n", f2_i(n));

    return 0;
}