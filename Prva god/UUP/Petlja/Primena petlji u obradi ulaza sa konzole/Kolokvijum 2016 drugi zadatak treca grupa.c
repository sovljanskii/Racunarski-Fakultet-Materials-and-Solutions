#include <stdio.h>

/*
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu slova
tako da se izbroji broj susednih pojavljivanja slova (broje se i mala i velika slova kao jednaka)
i ispiše na odgovarajući nacin.
*/

int main()
{
    char c,crez=-1;
    int br=0;
    while ((c=getchar())!='\n'){
        if (c==crez||c==crez+32){
            br++;
        }
        else {
            if (br>0){
                printf("%c%d",crez,br);
                br=0;
            }
            if (c>='A'&&c<='Z') {
                crez = c;
                br++;
            }
            else if (c>='a' && c<='z') {crez= c-32; br++;}
        }
    }
    if (br>0){
        printf("%c%d",crez,br);

    }
    return 0;
}