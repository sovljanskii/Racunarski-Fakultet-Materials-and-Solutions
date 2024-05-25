#include <stdio.h>
#include <math.h>


int main(){
    int n;
    int sredina=1;
    scanf("%d",&n);
    for (int i=0;i<n*2;i++){
        putchar(' ');
    }
    putchar('*');
    putchar('\n');
    int br=1;
    for (int i=0;i<n*2-1;i++){
            for (int j=0;j<n*2-1-(br*2-1);j++){
                putchar(' ');
            }
            putchar('*');

            for (int j = 0; j < br; j++) {
                printf("%d", br);
            }
            for (int j = br - 1; j > 0; j--) {
                printf("%d", j);
            }
        if (sredina) {
            br++;
        }
        else br--;
        if (br==n)sredina=0;
        putchar('*');
        putchar('\n');
    }
    for (int i=0;i<n*2;i++){
        putchar(' ');
    }
    putchar('*');
    return 0;
}