#include <stdio.h>

/*
Napisati program koji od unetog broja N ispisuje broj koji ima cifre kao broj N, 
samo u obrnutom redosledu. Primetiti da obrnuti broj nema vodećih nula.
*/

int main(){
    int n;
    int izvrnut=0;
    scanf("%d",&n);
    while (n!=0){
        izvrnut=izvrnut*10+n%10;
        n/=10;
    }
    printf("%d",izvrnut);
    return 0;
}