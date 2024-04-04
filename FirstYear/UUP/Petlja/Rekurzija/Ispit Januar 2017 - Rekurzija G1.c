#include <stdio.h>
#include <math.h>

double rekurzivna(int n, int i, int br) {
    if (i == n) {
        return br;
    }
    return br + 1.0 * (n * 2 - i + 1) / rekurzivna(n, i + 1, i + br);
}

double iterativna(int n) {
    double res = 0;
    for (int i = n; i > 1; i--) {
        int br = 1;
        for (int j = 0; j < i; j++) {
            br = br + j;
        }
        res = (n * 2 - i + 2) * 1.0 / (br + res);
    }
    res++;
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lf\n", rekurzivna(n, 1, 1));
    printf("%lf", iterativna(n));

}