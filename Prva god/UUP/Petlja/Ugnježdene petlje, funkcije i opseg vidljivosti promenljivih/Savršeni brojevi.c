#include <stdio.h>

/*
Napisati program kojim se određuju i ispisuju svi savršeni brojevi od 2 do N.
Broj je savršen ako je jednak sumi svojih delitelja isključujući njega samog.
28 je savršen broj, jer je: 28 = 1 + 2 + 4 + 7 + 14
*/

int provera(int n){
    int zbir=0;
    for (int i=1;i<=n/2;i++){

        if (n%i==0){
            zbir+=i;
        }
    }
    if (zbir==n){
        return 1;
    }
    return 0;
}


int main()
{
    int n;
    scanf("%d",&n);
    for (int i=2;i<=n;i++){
        if (provera(i)){
            printf("%d ",i);
        }
    }
    return 0;
}