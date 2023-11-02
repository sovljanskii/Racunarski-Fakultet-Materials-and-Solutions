#include <stdio.h>
/*
Nacrtati sledeću figuru za unetu vrednost n.
Primer za n = 8 :
H H H H H H H h H H H H H H H
H G G G G G G g G G G G G G H
H G F F F F F f F F F F F G H
H G F E E E E e E E E E F G H
H G F E D D D d D D D E F G H
H G F E D C C c C C D E F G H
H G F E D C B b B C D E F G H
h g f e d c b a b c d e f g h
H G F E D C B b B C D E F G H
H G F E D C C c C C D E F G H
H G F E D D D d D D D E F G H
H G F E E E E e E E E E F G H
H G F F F F F f F F F F F G H
H G G G G G G g G G G G G G H
H H H H H H H h H H H H H H H
*/
int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n * 2 - 1; i++) {
        for (int j = 1; j <= n * 2 - 1; j++) {
            int br = min(min(i, j), min(n * 2- i, n * 2 - j));
            if (i==n||j==n) putchar('a' + n - br);
            else putchar('A' + n - br);
            printf(" ");
        }
        printf("\n");
    }
}