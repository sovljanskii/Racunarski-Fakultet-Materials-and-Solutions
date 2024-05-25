#include <stdio.h>

/*
Napisati program koji za učitan mesec i godinu ispisuje koliko taj mesec u toj godini ima dana.
*/

int main(){
    int m,g;
    scanf("%d%d",&m,&g);
    switch (m){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("31");
            break;
        case 4: case 6: case 9: case 11:
                printf("30");
                break;
        case 2:
            if (g%4==0&&g%100!=0||g%400==0){
                printf("29");
            }
            else printf("28");
            break;

    }
    return 0;
}