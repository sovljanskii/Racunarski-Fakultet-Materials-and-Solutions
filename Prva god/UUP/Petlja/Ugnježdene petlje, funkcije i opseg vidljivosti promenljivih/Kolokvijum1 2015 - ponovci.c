#include <stdio.h>
/*
Napisati program koji za uneto n=5 ispisuje sledeću figuru:

///\\
\///\
\\///
\\\//
/\\\/

*/
int main(){
    int n;
    char znak='/';
    int br=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%c",znak);
            br++;
            if (br%3==0){
                if (znak=='/') znak='\\';
                else znak='/';
            }
        }
        printf("\n");
    }

    return 0;
}