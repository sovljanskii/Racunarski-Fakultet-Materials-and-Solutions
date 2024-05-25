#include <stdio.h>
#include <math.h>

double f3(int n) {
    if (n == 1) {
        return 1;
    }
    return sqrt(n + f3(n - 1));
}

double f3_i(int n) {
    double res = 0;
    for (int i = 1; i <= n; i++) {
        res = sqrt(i + res);
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lf\n", f3(n));
    printf("%lf", f3_i(n));
    return 0;
}