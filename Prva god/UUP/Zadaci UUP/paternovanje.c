0.
Napisati program koji menja unetu rečenicu koja se čuva kao string tako što izbacuje
sve reči koje počinju i završavaju se malim slovom. Pretpostavlja se da se unose samo slova i znak
razmaka (space).

Primer: Recenice se Ne pisu ovakO
Rezultat: Recenice Ne ovakO

#define SIZE 100

int proveri(char *str, int start, int end) {
    if (str[start] >= 'a' && str[start] <= 'z' && str[end] >= 'a' && str[end] <= 'z') return 0;
    return 1;
}

int main(){

    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = ' ';
    int start = 0, end;
    int k = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            end = i-1;
            if (proveri(str, start, end)) {
                for (int j = start; j <= end; j++) {
                    str[k++] = str[j];
                }
                str[k++] = ' ';
            }
            start = i+1;
        }

    }
    str[k] = '\0';
    puts(str);
    return 0;
}

1.
Napisati program koji menja unetu rečenice koja se čuva kao string tako što izbacuje sve
reči koje imaju manje od n karaktera, broj n unosi korisnik. Pretpostavlja se da se unose samo slova i
znak razmaka (space). Primer za n=5.

Primer: Recenica koja ima nekoliko reci
Rezultat: Recenica nekoliko

#define SIZE 100

int main(){

    char str[SIZE];
    int n;
    printf("Unesi n: ");
    scanf("%d ", &n);
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = ' ';
    int start = 0, end;
    int k = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            end = i-1;
            if (abs(start-end) > n) {
                for (int j = start; j <= end; j++) {
                    str[k++] = str[j];
                }
                str[k++] = ' ';
            }
            start = i+1;
        }

    }
    str[k] = '\0';
    puts(str);
    return 0;
}

2.
Napisati program koji menja uneti string koji sadrži cifre i znak '-', tako što cifre između
znaka - šiftuje za jedno mesto u desno.

Primer: 345-135-3217
Rezultat: 534-513-7321

#define SIZE 100

int main(){

    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = '-';
    int start = 0, end;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            end = i-1;
            for (int j = start; j <= end; j++) {
                char temp = str[j];
                str[j] = str[end];
                str[end] = temp;
            }
            start = i+1;
        }
    }
    str[strlen(str)-1] = '\0';
    puts(str);
    return 0;
}
  

3.
Napisati program koji menja uneti stringa koji sadrži cifre i znak '-', tako što cifre
između znaka - šiftuje za jedno mesto u levo.

Primer: 345-1354-321
Rezultat: 453-3541-213

#define SIZE 100

int main(){

    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = '-';
    int start = 0, end;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            end = i-1;
            for (int j = end; j >= start; j--) {
                char temp = str[j];
                str[j] = str[start];
                str[start] = temp;
            }
            start = i+1;
        }
    }
    str[strlen(str)-1] = '\0';
    puts(str);
    return 0;
}

4.
Napisati program koji učitava string koji sadrži reči razdvojene spejsom i od njega pravi
novi string koji sadrži sve različite reči iz unetog stringa (izbačena su sva naredna pojavljivanja iste
reči).

Primer: prvi drugi prvi treci drugi
Rezultat: prvi drugi treci

#define SIZE 100

int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = '\0';

    char pomocnik[SIZE] = "";
    char* token = strtok(str, " ");
    while(token) {
        if (strstr(pomocnik, token) == NULL)
            strcat(strcat(pomocnik, token), " ");
        token = strtok(NULL, " ");
    }
    pomocnik[strlen(pomocnik)-1] = '\0';
    puts(pomocnik);
    return 0;
}

5.
Napisati program koji učitava string koji sadrži reči razdvojene spejsom i od njega pravi
novi string koji sadrži samo reči koje se ponavljaju u unetom stringu (pojavljuju se u unetom stringu
više od jednom).

Primer: prvi drugi prvi treci drugi
Rezultat: prvi drugi

#define SIZE 100

int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = '\0';

    char pomocnik[SIZE] = "", novi[SIZE] = "";
    char* token = strtok(str, " ");
    while(token) {
        if (strstr(pomocnik, token) == NULL) strcat(strcat(pomocnik, token), " ");
        else strcat(strcat(novi, token), " ");
        token = strtok(NULL, " ");
    }
    pomocnik[strlen(novi)-1] = '\0';
    puts(novi);
    return 0;
}

6.
Napisati program koji učitava string koji sadrži mala slova i crtice i od unetog stringa
pravi novi string u kom su u podstringu između crtica izbačena sva ponovna pojavljivanja istog slova
(rezultujudi podstring sadrži jedno pojavljivanje svakog slova iz podstringa u unetom stringu).

Primer: abba-affg-ccc-fgh
Rezultat: ab-afg-c-fgh

#define SIZE 100

int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = ' ';

    char novi[SIZE] = "", partition[SIZE] = "";
    char* token = strtok(str, "-");
    
    while (token) {
        int k = 0;
        for (int i = 0; i < strlen(token); i++) {
            if (strchr(partition, token[i]) == NULL) partition[k++] = token[i];
        }
        partition[k] = '\0';
        strcat(strcat(novi, partition), "-");
        strcpy(partition, "");
        token = strtok(NULL, "-");
    }
    
    novi[strlen(novi)-1] = '\0';
    puts(novi);
    return 0;
}

7.
Napisati program koji učitava string koji sadrži mala slova i crtice i od unetog stringa
pravi novi string u kom je svaki podstring između crtica zamenjen slovima koji se u podstringu
unetog stringa pojavljuju više od jednom (u bilo kom redosledu).

Primer: abba-afgf-ccc-fgh
Rezultat: ab-f-c

#define SIZE 100

int main()
{
    char str[SIZE], novi[SIZE];
    int index = 0;
    int* map = calloc(26, sizeof(int));
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = ' ';

    int start = 0, end = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            end = i-1;
            for (int k = start; k <= end; k++)
                map[str[k]-'a']++;
            for (int m = 0; m < 26; m++)
                if (map[m] > 1) novi[index++] = m+'a';
            map = calloc(26, sizeof(int));
            novi[index++] = '-';
            start = i+1;
        }
    }

    novi[strlen(novi)-1] = '\0';
    puts(novi);
    return 0;
}

8.
Korisnik unosi rečenicu. Ispisati najučestaliju reč (reč koja se pojavila najvedi broj puta) i njenu
učestalost. Ukoliko postoji više reči koje imaju najvedu učestalost ispisati prvu koja se pojavila u rečenici.
primer:

prvi drugi prvi drugi treci prvi
izlaz: prvi 3

#define SIZE 100

int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = ' ';

    int max = 0;
    char kopija[SIZE], save[SIZE];
    strcpy(kopija, str);

    char* token = strtok(str, " ");
    while (token) {
        int brojac = 0;
        char *pok = kopija;
        while ((pok = strstr(pok, token)) != NULL) {
            brojac++;
            pok++;
        }
        if (brojac > max) {
            max = brojac;
            strcpy(save, token);
        }
        token = strtok(NULL, " ");
        strcpy(kopija, str);
    }
    printf("%s %d", save, max);
    return 0;
}

9.
Napisati program koji menja unetu rečenicu koja se čuva kao string tako što iz reči koje se nalaze
u pravilno zatvorenim navodnicima (navodnici se nalaze i pre i posle reči) izbacuje sve suglasnike i same
navodnike oko te reči. Pretpostavlja se da se unose velika i mala slova, znak razmaka i navodnici pre i/ili
posle reči (navodnici se ne nalaze u samoj reči).

Primer: "Danas je "pravi" dan "za" sneg"
Ispis: "Danas je ai dan a sneg"

#define SIZE 100

int main(){

    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = ' ';
    int start = 0, end;
    int k = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            end = i-1;
            if (str[start] == '"' && str[end] == '"') {
                for (int j = start+1; j <= end-1; j++) {
                    if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u')
                        str[k++] = str[j];
                }
            }
            else {
                for (int j = start; j <= end; j++)
                        str[k++] = str[j];
            }
            start = i+1;
            str[k++] = ' ';
        }
    }
    str[k] = '\0';
    puts(str);
    return 0;
}

10.
Napisati funkciju koja menja prosleđeni string tako što okrede reči neparne dužine. U glavnom
programu ispisati uneti string posle primene funkcije na njemu. Pretpostavlja se da se unose velika i
mala slova i znak razmaka.
PRIMER:

ikavS nad mi je kinzarp
Svaki dan mi je praznik

#define SIZE 100

void reverse(char* str, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = ' ';

    int start = 0, end = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            end = i-1;
            if ((end-start+1) & 1) reverse(str, start, end);
            start = i+1;
        }
    }

    puts(str);
    return 0;
}

11.
Korisnik unosi string koji sadrži cifre razdvojene crticom. Ispisati koji zbir cifara između crtica se
najčešde pojavljuje u unetom stringu, ispisati zbir, i sve podstringove cifara koje imaju taj zbir. Ukoliko
postoji više zbirova koji se najčešde pojavljuju ispisati bilo koji od njih.
PRIMER:

234-567-908-171-456-432
Izlaz: Zbir 9, 234 171 432

#define SIZE 100

int saberi(char* str, int start, int end) {
    int zbir = 0;
    for (int i = start; i <= end; i++)
        zbir += str[i]-'0';
    return zbir;
}

void sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printWord(char* arr, int start, int end)  {
     for (int i = start; i <= end; i++)
        putchar(arr[i]);
    putchar(32);
}

int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = '-';

    int start = 0, end = 0;
    int zbirovi[SIZE], index = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            end = i-1;
            zbirovi[index++] = saberi(str, start, end);
            start = i+1;
        }
    }
    sort(zbirovi, index);
    int max = 0, brojac = 1;
    for (int i = 0; i < index-1; i++) {
        if (zbirovi[i] == zbirovi[i+1]) brojac++;
        else {
            if (brojac > max) max = zbirovi[i-1];
            brojac = 1;
        }
    }
    printf("Zbir %d, ",max);
    start = 0, end = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            end = i-1;
            int zbir = saberi(str, start, end);
            if (zbir == max) printWord(str, start, end);
            start = i+1;
        }
    }
    return 0;
}

12.
Napisati program koji menja sve unete reči u unetom stringu tako da im mala slova
postanu velika ako su palindromi, ili ih obrće ako nisu palindromi. Palindrom je reč koja
se isto čita sa leva na desno i sa desna na levo. Pretpostavlja se da se unose samo
mala slova i znak razmaka.

Primer: ovo je palindrom za reper
Rezultat: OVO ej mordnilap az REPER

#define SIZE 100

int isPalindrome(char* str, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        if (str[i] != str[j]) return 0;
    }
    return 1;
}

void reverse(char* str, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        str[i]^=str[j];
        str[j]^=str[i];
        str[i]^=str[j];
    }
}

int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = ' ';

    int start = 0, end = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' '){
            end = i-1;
            if (isPalindrome(str, start, end)) {
                for (int k = start; k <= end; k++)
                    str[k] = str[k]-32;
            }
            else reverse(str, start, end);
            start = i+1;
        }
    }
    str[strlen(str)-1] = '\0';
    puts(str);
    return 0;
}

13.
Napisati program koji proverava da li je uneta linija teksta palindrom. Palindrom je
tekst koji se isto čita sa leva na desno i sa desna na levo. Pri proveri se ignorišu
razmaci, i parovi slova “nj” i “lj” se tretiraju kao jedno slovo. Pretpostavlja se da se unose
samo mala slova i znak razmaka.

Primer: i jogurt ujutru goji
Rezultat: jeste palindrom
Primer: neki tekst
Rezultat: nije palindrom
Primer: idu ljudi
Rezultat: jeste palindrom

#define SIZE 100

int isPalindrome(char* str) {
    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        if (str[i] == 32) i++;
        if (str[j] == 32) j--;
        if (str[i] == 'l' && str[i+1] == 'j' && str[j] == 'j' && str[j-1] == 'l') {
            i+=2;
            j-=2;
        }
        else if (str[i] == 'n' && str[i+1] == 'j' && str[j] == 'j' && str[j-1] == 'n') {
            i+=2;
            j-=2;
        }
        if (i > j) break;
        if (str[i] != str[j]) return 0;
    }
    return 1;
}


int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = '\0';
    printf("%s", (isPalindrome(str)?("Jeste palindrom"):("Nije palindrom")));
    return 0;
}

14.
Napisati program koji učitava string sastavljen od reči razdvojenih spejsom. Reči su
napisane malim slovima abecede. Program treba da proveri i ispiše za svaku reč koja
sadrži ista slova najmanju razdaljinu između istih slova (broje se slova koja se nalaze
između istih slova). Ispisuje se reč i razdaljina.

Primer: mamaa kjloijk abc hjkjk
Ispis: mamaa - 0
kjloijk - 3
hjkjk - 1

void proveri(char *str) {
    str[strlen(str) - 1] = '\0';
    char *token = strtok(str, " ");
    int brojac = 0, min = INT_MAX, flag = 0;
    while (token != NULL) {
        for (int i = 0; i < strlen(token); i++) {
                brojac = 0;
                for (int j = i + 1; j < strlen(token); j++) {
                    if (token[j] == token[i]) {
                        flag = 1;
                        if (brojac < min) min = brojac;
                        brojac = 0;
                    }
                    else brojac++;
                }

        }
        if (flag) printf("%s - %d\n", token, min);
        min = INT_MAX;
        flag = 0;
        token = strtok(NULL, " ");
    }
}

int main()
{
    char str[SIZE];
    fgets(str, sizeof(str), stdin);
    proveri(str);
    return 0;
}

15.
Napisati program koji učitava string sastavljen od malih i velikih slova abacede.
Program treba da pronađe i ispiše najduži podstring koji počinje i završava se istim
slovom nezavisno od veličine slova. Ispisati podstring i dužinu, ako ima više podstringova
sa istom najvećom dužinom ispisati sve.

Primer: amjZdghAshZfgh
Rezultat: duzina 8
podstringovi: amjZdghA ZdghAshZ ghAshZfg hAshZfgh

#define SIZE 100

void printSubstring(char* str, int start, int end) {
    for (int i = start; i <= end; i++) putchar(str[i]);
    putchar(32);
}

void transform(char* str) {
    for (int i = 0; i < strlen(str); i++)
        if (str[i] >= 'A' && str[i] <= 'Z') str[i]+=32;
}

int main()
{
    char str[SIZE], copy[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = ' ';
    strcpy(copy, str);
    transform(str);

    int max = 0;
    for (int i = 0; i < strlen(str)-1; i++) {
        int brojac = 1;
        for (int j = i+1; j < strlen(str); j++) {
            brojac++;
            if (str[i] == str[j]) {
                if (brojac > max) {
                    max = brojac;
                }
            }
        }
    }
    printf("Duzina: %d\n", max);
    int start = 0, end = 0;
    for (int i = 0; i < strlen(str)-1; i++) {
        int brojac = 1;
        for (int j = i+1; j < strlen(str); j++) {
            brojac++;
            if (str[i] == str[j]) {
                if (brojac == max) {
                    printSubstring(copy, i, j);
                    brojac = 1;
                }
            }
        }
    }
    return 0;
}

16.
Napisati program koji učitava string sastavljen od reči odvojenih razmacima i
nalazi najređu reč (reč koja ima najmanji broj ponavljanja). Potom izbacuje iz
stringa sva njena pojavljivanja. Ukoliko više reči ima minimalni broj ponavljanja,
izbaciti ih sve.

Ulaz: hill forest woods lake forest hill
Izlaz: hill forest forest hill

Ulaz: castle flower rose flower castle rose flower
Izlaz: flower flower flower

#define SIZE 100

int main()
{
    char str[SIZE];
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    char pomocnik[SIZE] = "", kopija[SIZE];
    strcpy(kopija, str);
    char *token = strtok(str, " ");
    int brojac = 0, min = INT_MAX;
    while (token != NULL) {
        char *pok = kopija;
        while ((pok = strstr(pok, token)) != NULL) {
            brojac++;
            pok++;
        }
        if (brojac < min) min = brojac;
        brojac = 0;
        token = strtok(NULL, " ");
    }
    strcpy(str, kopija);
    token = strtok(str, " ");
    while (token != NULL) {
        char *pok = kopija;
        while ((pok = strstr(pok, token)) != NULL) {
            brojac++;
            pok++;
        }
        if (brojac != min) strcat(strcat(pomocnik, token), " ");
        brojac = 0;
        token = strtok(NULL, " ");
    }
    pomocnik[strlen(pomocnik) - 1] = '\0';
    strcpy(str, pomocnik);
    puts(str);
    return 0;
}

17.
Za 2 zadata stringa, S i P, pronaći ukupan broj pojavljivanja svih različitih
podstringova stringa P unutar stringa S koji se dobiju kada se iz P izbaci jedno slovo
(izbaciju se sva pojavljivanja istog slova).
Ulaz:             Ulaz:           Ulaz:

cbaebabacd              BBDDADADA               AAABABAA
abc                     ABBDA                   AABA
Izlaz: 2                Izlaz: 3                Izlaz: 3
(ab-1, ac-1, bc-0) (BBD-1, ADA-2,ABBA-0)        (AAA-1, B-2)


#define SIZE 100

int ponavljanja(char* subString, char* strS) {
    int brojac = 0;
    char* pok = strS;
    while((pok = strstr(pok, subString))) {
        brojac++;
        pok++;
    }
    return brojac;
}

int main()
{
    char strS[SIZE], strP[SIZE];
    fgets(strS, SIZE, stdin); fgets(strP, SIZE, stdin);
    strS[strlen(strS) - 1] = '\0'; strP[strlen(strP) - 1] = '\0';
    char map[SIZE];
    int m = 0;

    for(int i = 0; i < strlen(strP); i++) {
        if (strchr(map, strP[i])) continue;
        map[m++] = strP[i]; map[m] = '\0';
        char subString[SIZE];
        int index = 0;
        for (int j = 0; j < strlen(strP); j++) {
            if (strP[i] != strP[j]) subString[index++] = strP[j];
        }
        subString[index] = '\0';
        printf("%s - %d ", subString, ponavljanja(subString, strS));
        strcpy(subString, " ");
        index = 0;
    }

    return 0;
}

18. Napisati program koji učitava string koji sadrži mala slova i crtice i od unetog stringa pravi
novi string u kom su izbačeni svi podstringovi između crtica u kojima ima slova koja se ponavljaju (u
bilo kom redosledu).

Primer: abba-afgh-ccc-fgh
Rezultat: afgh-fgh

#define SIZE 100

int provera(char* subString) {
    int* map = calloc(26, sizeof(int));
    for (int i = 0; i < strlen(subString); i++) map[subString[i]-'a']++;
    for (int i = 0; i < 26; i++)
        if (map[i] > 1) return 0;
    return 1;
}

int main()
{
    char str[SIZE], novi[SIZE] = "";
    fgets(str, SIZE, stdin);
    str[strlen(str) - 1] = '\0';

    char* token = strtok(str, "-");
    while(token) {
        if (provera(token)) {
            strcat(strcat(novi, token), "-");
        }
        token = strtok(NULL, "-");
    }
    novi[strlen(novi)-1] = '\0';
    puts(novi);
    return 0;
}

19. Napisati program koji učitava string koji sadrži reči razdvojene spejsom i od njega pravi novi
string u kome su izbačena sva susedna pojavljivanja jednakih reči (ostavlja se prvo pojavljivanje, a
ostala se izbacuju).

Primer: prvi prvi prvi drugi prvi treci treci drugi
Rezultat: prvi drugi prvi treci drugi

#define SIZE 100

int main()
{
    char str[SIZE], novi[SIZE] = "";
    fgets(str, SIZE, stdin);
    str[strlen(str) - 1] = '\0';

    char container[SIZE][SIZE];
    int index = 0;

    char* token = strtok(str, " ");
    while(token) {
        strcpy(container[index++], token);
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < index-1; i++) {
        if (strcmp(container[i], container[i+1]) == 0) continue;
        strcat(strcat(novi, container[i]), " ");
    }
    strcat(strcat(novi, container[index-1]), " ");
    novi[strlen(novi)-1] = '\0';
    puts(novi);
    return 0;
}

20. 
Napisati program koji ucitava string koji sadrzi brojeve odvojene razmacima. U svakom broju treba promeniti simetricne
cifre na sledeci nacin. Prva cifra i poslednja cifra se uvecavaju za jedan, druga cifra i pretposlednja cifra se uvecavaju
za dva itd. Ako pri uvecavanju broj bude veci od 9, ispisati poslednju cifru.
Nije dozvoljeno koristiti dodatne stringove.

Input: 4385 53913 335
Output: 5506 65234 456

#define SIZE 100

void izmeni(char *str, int start, int end) {
    int brojac = 1;
    for (int i = start, j = end; i <= j; i++, j--) {
        int c1, c2;
        c1 = str[i] - '0', c2 = str[j] - '0';
        c1 += brojac, c2 += brojac;
        if (c1 > 9) c1 -= 10;
        if (c2 > 9) c2 -= 10;
        c1 += '0', c2 += '0';
        str[i] = c1, str[j] = c2;
        brojac++;
    }
}

int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str)-1] = ' ';
    int start = 0, end;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            end = i-1;
            izmeni(str, start, end);
            start = i+1;
        }
    }
    str[strlen(str)-1] = '\0';
    puts(str);
    return 0;
}

21.
Napisati program koji ucitava jedan red teksta i ispisuje sve parove reci koji sadrze (bar jedan) zajednicki
podstring duzi od dva slova. Razlikovati velika od malih slova. Primer:
Ulaz:
pravac jug jugozapad moj zdrav zivot moja pravila

Izlaz:
pravac zdrav
pravac pravila
jug jugozapad
moj moja
zdrav pravila

#define SIZE 100

int ispitaj(char* str1, char* str2) {
    for (int i = 0; i < strlen(str1); i++) {
        char sub[SIZE];
        int index = 0;
        for (int j = i; j < strlen(str1); j++) {
            sub[index++] = str1[j];
            sub[index] = '\0';
            if (strlen(sub) > 2 && strstr(str2, sub)) return 1;
        }
        sub[index] = '\0';
        index = 0;
    }
    return 0;
}

void ispisi(char words[SIZE][SIZE], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (ispitaj(words[i], words[j]))
                printf("%s %s\n", words[i], words[j]);
        }
    }
}

int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str) - 1] = '\0';

    char words[SIZE][SIZE];
    int index = 0;

    char* token = strtok(str, " ");
    while(token) {
        strcpy(words[index++], token);
        token = strtok(NULL, " ");
    }
    ispisi(words, index);
    return 0;
}

22.
Napisati program koji učitava string koji sadrži reči razdvojene spejsom i od njega pravi novi
string koji sadrži samo reči koje se pojavljuju i u obrnutom zapisu u unetom stringu.

Primeri: Ulaz: abc eef cba eed ghi dee aaa 
Izlaz: abc cba eed dee

Ulaz: goog evo bbf ove fbc gg 
Izlaz: evo ove

#define SIZE 100

int proveri(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) return 0;
    for (int i = 0, j = strlen(str1)-1; i < strlen(str1); i++, j--) {
        if (str1[i] != str2[j]) return 0;
    }
    return 1;
}

int main()
{
    char str[SIZE], novi[SIZE] = "";
    fgets(str, SIZE, stdin);
    str[strlen(str) - 1] = '\0';

    char words[SIZE][SIZE];
    int index = 0;

    char* token = strtok(str, " ");
    while(token) {
        strcpy(words[index++], token);
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < index-1; i++) {
        for (int j = 0; j < index; j++) {
            if (proveri(words[i], words[j]))
                strcat(strcat(novi, words[i]), " ");
        }
    }
    novi[strlen(novi) - 1] = '\0';
    puts(novi);
    return 0;
}