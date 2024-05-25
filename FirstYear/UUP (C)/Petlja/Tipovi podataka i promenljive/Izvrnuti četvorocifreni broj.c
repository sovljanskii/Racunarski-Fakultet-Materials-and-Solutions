#include <stdio.h>

/*
Napisati program koji će uneti četvorocifreni broj izvrnuti i ispisati.
*/

int main(){
    int n;
    int izvrnut=0;
    scanf("%d",&n);
    while (n!=0){ /// moze i stepen po stepen, aka printf("%d%d%d%d",n%10,n%100/10,n/100%10,n/1000);
        izvrnut=izvrnut*10+n%10;
        n/=10;
    }
    printf("%d",izvrnut);
    return 0;
}