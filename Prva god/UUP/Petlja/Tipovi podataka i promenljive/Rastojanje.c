#include <stdio.h>
#include <math.h>
/*
Napisati program koji računa Euklidsko rastojanje između dve tačke u ravni i ispisuje ga na standardni izlaz.
*/

int main(){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    printf("%.2f", sqrt(pow(x2-x1,2)+pow(y2-y1,2)));
    return 0;
}