#include <stdio.h>

/*
Koristeći naredbu while za obradu teksta, pronaći najveću razliku između 2
susedna broja.
primer: adg7gjk12fdsj15fghfh11dfgdg9
rezultat: 5
 */

int main(){
    char c;
    int max=0;
    int count=0;
    int prvi=0;
    while ((c = getchar())!='\n'){
        if (c>='0'&&c<='9'){
            if (prvi){
            if (count > max) max=count;
            }
            else prvi = 1;
            count=0;
        }
        else count++;
    }
    printf("%d",max);
    return 0;
}