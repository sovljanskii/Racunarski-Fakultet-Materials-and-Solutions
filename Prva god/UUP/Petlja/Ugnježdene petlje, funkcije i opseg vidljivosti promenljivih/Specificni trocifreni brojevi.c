#include <stdio.h>
/*
Napisati program koji ispisuje trocifrene brojeve sa osobinom da imaju cifru stotica manje od 6, 
parnu cifru desetica i cifru jedinica vecu od cifre desetica.
*/
int specificni(int n){
    if (n/100<6&&n/10%10%2==0&&n%10>n/10%10){
        return 1;
    }
    return 0;
}


int main(){

    for (int i=100;i<1000;i++){
        if (specificni(i)) printf("%d ",i);
    }
    return 0;
}