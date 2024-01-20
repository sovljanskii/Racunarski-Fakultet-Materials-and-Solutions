#include <stdio.h>
#include <math.h>

double rek(int i, int n) {
    if (n == 0) {
        return 0;
    }
    return sqrt((1.0 + i % 2) / n + rek(i + 1, n - 1));

}

double ite(int n) {
    double res = 0;
    for (int i = n; i > 0; i--) {
        res = sqrt(1.0*(2-i%2)/(n-i+1)+res);
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lf\n", rek(0, n));
    printf("%lf", ite(n));
    return 0;
}