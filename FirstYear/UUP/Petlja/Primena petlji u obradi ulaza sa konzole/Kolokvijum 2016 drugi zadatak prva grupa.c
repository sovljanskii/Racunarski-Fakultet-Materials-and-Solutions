#include <stdio.h>

/*
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu karaktera
koja se sastoji od brojeva i znakova + i -, tako da se izračuna i ispiše rezultat aritmetičkih operacija
sabiranja i oduzimanja koje se izvršavaju redom.
*/

int main()
{
    char c;
    int znak=1;
    int br=0;
    int zbir=0;
    while ((c=getchar())!='\n'){
        switch (c) {
            case '+':
                zbir+=br*znak;
                br=0;
                znak=1;
                break;
            case '-':
                zbir+=br*znak;
                br=0;
                znak=-1;
                break;
            default:
                br=br*10+c-'0';
                break;

        }
    }
    zbir+=br*znak;
    printf("%d",zbir);

    return 0;
}