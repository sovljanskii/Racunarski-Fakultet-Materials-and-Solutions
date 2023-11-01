0.
Koristeći naredbu while za obradu teksta izbaciti svako slovo koje je susedno
prethodno ispisanom slovu (susedna=slova koja se nalaze jedno pored drugog u
ASCII tabeli) iz unetog teksta.
primer: AbDfghjk
rezultat: ADfj

int main()
{
    int ch;
    int prev = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= 'A' && ch <= 'Z') {
            if (!(ch == prev+1 || ch == prev-1 || ch == prev-32-1 || ch == prev-32+1))
                putchar(ch);
        }
        else if (ch >= 'a' && ch <= 'z') {
            if (!(ch == prev+1 || ch == prev-1 || ch == prev+32-1 || ch == prev+32+1))
                putchar(ch);
        }
        prev = ch;
    }
}

1.
Koristeći naredbu while za obradu teksta promeniti u veliko slovo svako slovo
koje je susedno prethodno ispisanom slovu (susedna=slova koja se nalaze jedno
pored drugog u ASCII tabeli) iz unetog teksta. Korisnik unosi samo mala
primer: abdfghjk
rezultat: aBdfGHjK

int main()
{
    int ch;
    int prev = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == prev+1 || ch == prev-1) putchar(ch-32);
        else putchar(ch);
        prev = ch;
    }
}

2.
Koristeći naredbu while za obradu teksta ,ispisati tekst na način prikazan u primeru.
primer: 10A3B1C
rezultat: AAAAAAAAAABBBC

int main()
{
    int ch;
    int n = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9')
            n = n*10+ch-'0';
        else {
            for (int i = 0; i < n; ++i, putchar(ch)) {}
            n = 0;
        }
    }
}

3.
Koristeći naredbu while za obradu teksta, ispisati tekst na način prikazan u primeru.
primer: c3-e5-d10
rezultat: ccc-eeeee-dddddddddd

int main()
{
    int ch, save = 0;
    int n = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= 'a' && ch <= 'z') save = ch;
        else if (ch >= '0' && ch <= '9')
            n = n*10+ch-'0';
        else if (ch == '-') {
            for (int i = 0; i < n; ++i, putchar(save)){}
            putchar('-');
            n = 0;
        }
    }
    for (int i = 0; i < n; ++i, putchar(save)){}
}

4.
Koristeći naredbu while za obradu teksta, ispisati trocifren broj koji se sastoji od 3
poslednje cifre u ulaznom tekstu.
primer: ABC3DF5HFD6GFD7
rezultat: 567

int main()
{
    int ch;
    int n = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9')
            n = n*10+ch-'0';
    }
    printf("%d", n%1000);

}

5.
Koristeći naredbu while za obradu teksta, pronaći najveću razliku između 2
susedna broja.
primer: adg7gjk12fdsj15fghfh11dfgdg9
rezultat: 5

#define MAX(A,B) (A>B)?(A):(B)
int main()
{
	int ch, n = 0, maks = 0, x = -1, y = -1;
	while ((ch = getchar()) != EOF && ch != '\n') {
		if (ch >= '0' && ch <= '9')
			n = n * 10 + ch - '0';
		else if (n != 0) {
			if (x == -1 && y == -1) x = n;
			else if (y == -1) {
				y = n;
				maks = MAX(maks, abs(x-y));
				y = -1;
				x = n;
			}
			n = 0;
		}
	}
	printf("%d", maks);
	return 0;
}

6.
Koristeći naredbu while za obradu teksta, ispisati tekst kao u primeru.
primer: abcdefghijklmnopq
rezultat: abCDefGHijKLmnOPq

int main()
{
    int ch;
    int flag = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (flag == 0 || flag == 1) putchar(ch);
        else putchar(ch-32);
        flag = (flag+1)%4;
    }
    return 0;
}

7.
Koristeći naredbu while za obradu teksta, ispisati tekst kao u primeru.
primer: aaaaxxxxcccddeeeeefff
rezultat: aaaaXXXXcccDDeeeeeFFF

int main()
{
    int ch;
    int curr = -1;
    int flag = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch != curr) {
            curr = ch;
            flag = (flag+1)%2;
        }
        if (flag) putchar(ch);
        else putchar(ch-32);

    }
}

8.
Koristedi naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu karaktera
koja počinje brojem a sastoji se od brojeva i znakova + i -, tako da se izračuna i ispiše rezultat
aritmetičkih operacija sabiranja i oduzimanja koje se izvršavaju redom.
primer: 10+13-12+25-5+100
rezultat: 131

int main()
{
    int ch, n = 0;
    int op = '+';
    int sum = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9')
            n = n*10+ch-'0';
        else if (ch == '+' || ch == '-') {
            if (op == '+') sum+=n;
            else sum-=n;
            op = ch;
            n = 0;
        }
    }
    if (n != 0) {
        if (op == '+') sum+=n;
        else sum-=n;
    }
    printf("%d", sum);
}

9.
Koristedi naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu karaktera
koja počinje brojem, a sastoji se od brojeva i znakova * i /, tako da se izračuna i ispiše rezultat
aritmetičkih operacija množenja i celobrojnog deljenja koje se izvršavaju redom.
primer: 25/5*10*2/25
rezultat: 4

int main()
{
	int ch, n = 0, r = 1;
	char op = '*';
	while ((ch = getchar()) != EOF && ch != '\n') {	
		if (ch >= '0' && ch <= '9') 
			n = n * 10 + ch - '0';
		else if (ch == '*' || ch == '/') {
			if (op == '*') r *= n;
			else r /= n;
			op = ch;
			n = 0;
		}
		else {
			printf("GRESKA");
			exit(1);
		}
	}
	if (op == '*') r *= n;
	else r /= n;
	printf("%d", r);
	return 0;
}

10.
Koristedi naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu slova
tako da se izbroji broj susednih pojavljivanja slova (broje se i mala i velika slova kao jednaka) i ispiše
na slededi način:
primer: AAababbBBCc
rezultat: 3a1b1a4b2c

int main()
{
    int ch, prev = -1;
    int count = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= 'A' && ch <= 'Z') ch+=32;
        if (prev == -1) prev = ch;
        if (prev == ch) count++;
        else {
            printf("%d%c", count, prev);
            count = 1;
        }
        prev = ch;
    }
    printf("%d%c", count, prev);
}

11.
Koristedi naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu slova
tako da se izbroji broj susednih pojavljivanja slova (broje se mala i velika slova kao jednaka) i ispiše
na slededi način:
primer: aaababbBBC
rezultat: a3b1a1b4c1

int main()
{
    int ch, prev = -1;
    int count = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= 'A' && ch <= 'Z') ch+=32;
        if (prev == -1) prev = ch;
        if (prev == ch) count++;
        else {
            printf("%c%d", prev, count);
            count = 1;
        }
        prev = ch;
    }
    printf("%c%d", prev, count);
}

12.
Koristedi naredbu while i funkciju getchar() za čitanje karaktera iz ulazne sekvence karaktera
koja se sastoji od slova i cifara izračunati zbir svih brojeva koji se nalaze između istih slova, pri čemu
se odgovarajude malo i veliko slovo smatraju istim (a je jednako sa A).
primer: ab23Bnh46zu37uj1jht21m
rezultat: 61
(objašnjenje: brojevi koji se nalaze između istih slova su 23, 37 i 1, u zbiru 61)

int main()
{
    int ch;
    int n = 0, sum = 0;
    int saveLetter = -1;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= 'A' && ch <= 'Z') ch+=32;
        if (ch >= '0' && ch <= '9')
            n = n*10+ch-'0';
        else {
            if (ch == saveLetter) sum+=n;
            saveLetter = ch;
            n = 0;
        }
    }
    if (ch == saveLetter) sum+=n;
    printf("%d", sum);
}

13.
Koristedi naredbu while i funkciju getchar() za čitanje karaktera iz ulazne sekvence karaktera
koja se sastoji od slova i cifara izračunati zbir svih brojeva koji se nalaze između slova koji su najviše
do dva mesta udaljeni u ASCII tabeli.
primer: ab11cnh23zk37j1jht21m
rezultat: 49
(objašnjenje: brojevi koji se nalaze između slova sa razmakom do dva mesta 11, 37 i 1, u zbiru 49)

int main()
{
    int ch;
    int n = 0, sum = 0;
    int saveLetter = -1;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= 'A' && ch <= 'Z') ch+=32;
        if (ch >= '0' && ch <= '9')
            n = n*10+ch-'0';
        else {
            if (ch >= saveLetter-2 && ch <= saveLetter+2) sum+=n;
            saveLetter = ch;
            n = 0;
        }
    }
    if (ch >= saveLetter-2 && ch <= saveLetter+2) sum+=n;
    printf("%d", sum);
}

14.
Koristedi naredbu while i funkcije getchar() i putchar() obraditi ulaznu sekvencu karaktera koja
se sastoji od cifara i zagrada tako što se izraz u ugnježdenoj zagradi zamenjuje zbirom cifara koje se
nalaze u toj ugnježdenoj zagradi, a svi ostali karakteri se prepisuju. Pretpostavlja se da su zagrade
pravilno otvorene i zatvorene i da može biti samo jedan nivo ugnježdenosti.
primer: 34(78)67(56(34)56)(34(456))
rezultat: 34(78)67(56756)(3415)

int main()
{
    int ch, n = 0;
    int count = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (count == 2 && ch >= '0' && ch <= '9')
            n += ch-'0'; 
        if (ch == '(') count++;
        else if (ch == ')') {
            if (count == 2) {
                printf("%d", n);
                count--;
                n = 0;
                continue;
            }
            count--;
        }
        if (count != 2) putchar(ch);
    }
}

15.
Koristedi naredbu while i funkcije getchar() i putchar() obraditi ulaznu sekvencu karaktera koja
se sastoji od cifara i vitičastih zagrada tako što se izraz u ugnježdenoj zagradi zamenjuje
maksimalnom cifrom koja se nalaze u toj zagradi, a svi ostali karakteri se prepisuju. Pretpostavlja se
da su zagrade pravilno otvorene i zatvorene i da može biti samo jedan nivo ugnježdenosti.
primer: 34{78}67{56{34}56}{34{456}}
rezultat: 34{78}67{56456}{346}

int main()
{
    int ch, max = -1;
    int count = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (count == 2 && ch >= '0' && ch <= '9')
            max = ((ch-'0') > max)?(ch-'0'):(max);
        if (ch == '{') count++;
        else if (ch == '}') {
            if (count == 2) {
                printf("%d", max);
                count--;
                max = -1;
                continue;
            }
            count--;
        }
        if (count != 2) putchar(ch);
    }
}

16.
Koristedi naredbu while i funkciju getchar() za čitanje karaktera iz ulazne sekvence karaktera
koja se sastoji od slova i cifara, izračunati zbir svih trocifrenih brojeva.
primer: ab123de5000f4g567hh rezultat: 690
(objašnjenje: brojevi koji su trocifreni su 123 i 567, u zbiru su 690)

int main()
{
    int ch;
    int n = 0, sum = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9')
            n = n*10+ch-'0';
        else if (n != 0) {
            if (n >= 100 && n <= 999) sum+=n;
            n = 0;
        }

    }
    if (n >= 100 && n <= 999) sum+=n;
    printf("%d", sum);

}

17.
Koristedi naredbu while i funkciju getchar() za čitanje karaktera iz ulazne sekvence karaktera
koja se sastoji od slova i cifara, izračunati zbir svih brojeva koji sadrže cifru 2 ili 5.
primer: ab123de3000f4g567hh rezultat: 690
(objašnjenje: brojevi koji sadrže cifru 2 ili 5 su 123 i 567, u zbiru su 690)

int main()
{
    int ch;
    int n = 0, sum = 0;
    int flag = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            n = n*10+ch-'0';
            if (ch == '2' || ch == '5') flag = 1;
        }
        else if (n != 0) {
            if (flag) sum+=n;
            flag = 0;
            n = 0;
        }
    }
    if (flag) sum+=n;
    printf("%d", sum);
}

18.
Koristedi naredbu while i funkciju getchar() za čitanje karaktera iz ulazne sekvence karaktera
koja se sastoji od slova i cifara, izračunati zbir svih brojeva koji ne sadrže cifre 1 i 6.
primer: ab123de3000f4g567hh
rezultat: 3004
(objašnjenje: brojevi koji ne sadrže cifre 1 i 6 su 3000 i 4, u zbiru su 3004)

int main()
{
    int ch;
    int n = 0, sum = 0;
    int flag = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            n = n*10+ch-'0';
            if (ch == '1' || ch == '6') flag = 1;
        }
        else if (n != 0) {
            if (!flag) sum+=n;
            flag = 0;
            n = 0;
        }
    }
    if (!flag) sum+=n;
    printf("%d", sum);
}

19.
//GRESKA U TEKSTU ZADATKA//
Koristedi naredbu while i funkciju getchar() za čitanje karaktera iz ulazne sekvence karaktera
koja se sastoji od slova i cifara, izračunati zbir svih brojeva koji sadrže samo neparne cifre.
primer: ab123de3000f4g567hh rezultat: 690
(objašnjenje: brojevi koji sadrže samo neparne cifre su 123 i 567, u zbiru su 690)

int main()
{
    int ch;
    int n = 0, sum = 0;
    int flag = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            n = n*10+ch-'0';
            if (!((ch-'0') & 1)) flag = 1;
        }
        else if (n != 0) {
            if (!flag) sum+=n;
            flag = 0;
            n = 0;
        }
    }
    if (!flag) sum+=n;
    printf("%d", sum);
}

20.
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu slova tako da se proveri da li su zagrade [] i () pravilno zatvorene. Zagrade
mogu biti ugneždene jedna u drugu, s time da je dozvoljen samo jedan nivo
ugneždenosti. Ako su sve zagrade pravilno zatvorene, ispisati “ok”, inače “greska”.
Ulaz: (jedan[dva][tri][četiri]) Izlaz: ok
Ulaz: (jedan][dva) Izlaz: greska

int main()
{
    int ch;
    int mala = 0, velika = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == '(') mala++;
        else if (ch == '[') velika++;
        else if (ch == ')') {
            mala--;
            if (mala == -1) {printf("GRESKA"); return 0;} // [)
        }
        else if (ch == ']') {
            velika--;
            if (velika == -1) {printf("GRESKA"); return 0;} // (]
        }
    }
    if (mala != 0 || velika != 0) printf("GRESKA");
    else printf("OK");
}

21.
Koristeći naredbu while i funkciju getchar() za čitanje karaktera proveriti da li su u
ulaznoj sekvenci karaktera tagovi <a> i <b> pravilno zatvoreni. Oznaka otvarajućeg taga
je <a>, a zatvarajućeg </a>. Tagovi su pravilno zatvoreni ako svaki otvarajući tag ima
svoj odgovarajući zatvarajući tag i ako je dobra ugnježdenost. Unutar taga a (otvorenog i
zatvorenog) može se nalaziti otvoren i zatvoren tag b i obrnuto. Postoji samo jedan nivo
ugnježdenosti. Ako su svi tagovi pravilno zatvoreni, ispisati “ok”, inače “greska”.
Ulaz: as<a>prvi<b>drugi</b>treci</a>kraj Izlaz: ok
Ulaz: as<a>prvi</a>drugi<b>treci</b>kraj Izlaz: ok
Ulaz: as<a>prvi<b>drugi</a>treci</b> Izlaz: greska
Ulaz: as<a>prvi<b>drugi</b>kraj Izlaz: greska
Ulaz: as</a>prvi<a>drugi<b>treci</b> Izlaz: greska

int main()
{
    int ch, prev = -1;
    int openA = 0, openB = 0;
    int trenutni = -1;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == 'a' && prev == '<') {
            openA++;
            trenutni = 'A';
        }
        else if (ch == 'b' && prev == '<') {
            openB++;
            trenutni = 'B';
        }
        else if (ch == 'a' && prev == '/') {
            openA--;
            if (openA == -1 || trenutni == 'B') {printf("GRESKA"); return 0;}
            trenutni = -1;
        }
        else if (ch == 'b' && prev == '/') {
            openB--;
            if (openB == -1 || trenutni == 'A') {printf("GRESKA"); return 0;}
            trenutni = -1;
        }
        prev = ch;
    }
    if (openA != 0 || openB != 0) printf("GRESKA");
    else printf("OK");
}

22.
Koristeći naredbu while i funkciju getchar() za čitanje karaktera, obraditi ulaznu
sekvencu koja se sastoji od malih slova, cifara i pravilno zatvorenih zagrada ( ), ispisati
zbir brojeva koji se dobiju sastavljanjem prve i poslednje cifre unutar zagrada.
Napomena: Izmedju zagrada će uvek biti bar jedna cifra.
Primer: ab13(12s3)(5)x(y6gg79zs)pk8
Ispis: 137
Objašnjenje: (12s3) – prva cifra je 1, poslednja 3, kreiramo broj 13
(5) – prva cifra je 5, poslednja cifra je 5, kreiramo broj 55
(y6gg79zs) – prva cifra je 6, poslednja cifra je 9, kreiramo broj 69

137 = 13 + 55 + 69

int main()
{
    int ch;
    int open = 0, first = -1, last = 0;
    int sum = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (open && ch >= '0' && ch <= '9') {
            if (first == -1) {
                first = ch-'0';
            }
            last = ch-'0';
        }
        if (ch == '(') open = 1;
        else if (ch == ')') {
            sum += first*10+last;
            first = -1;
            open = 0;
        }
    }
    if (open) sum += first*10+last;
    printf("%d", sum);

}

23.
Koristeći naredbu while i funkciju getchar() za čitanje karaktera, obraditi ulaznu
sekvencu koja se sastoji od malih slova, cifara i pravilno zatvorenih zagrada [ i ],
izračunati i ispisati najveću razliku između prve i poslednje cifre unutar zagrada.
Napomena: Izmedju zagrada će uvek biti bar jedna cifra.
Primer: ab13[12s3][5]x[y6gg79zs]pk8
Ispis: 3
Objašnjenje: [12s3] – prva cifra je 1, poslednja 3, razlika 2
[5] – prva cifra je 5, poslednja cifra je 5, razlika 0
[y6gg79zs] – prva cifra je 6, poslednja cifra je 9, razlika 3

Najveća razlika je 3.

int main()
{
    int ch;
    int open = 0, first = -1, last = 0;
    int max = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (open && ch >= '0' && ch <= '9') {
            if (first == -1) {
                first = ch-'0';
            }
            last = ch-'0';
        }
        if (ch == '[') open = 1;
        else if (ch == ']') {
            max =(abs(first-last) > max)?(abs(first-last)):(max);
            first = -1;
            open = 0;
        }
    }
    if (open) max =(abs(first-last) > max)?(abs(first-last)):(max);
    printf("%d", max);
}

24.
Koristeći naredbu while i funkciju getchar() za čitanje karaktera iz ulazne sekvence
karaktera koja se sastoji od reči i jednostrukih navodnika (reči sadrže velika i mala slova
abecede). Potrebno je promeniti veličinu slova reči pod navodnicima na osnovu prve reči pod
navodnicima. Ako se prva reč sastoji samo od malih slova onda sve ostale reči pretvoriti u mala
slova, ako se prva reč sastoji samo od velikih slova sve ostale reči pretvoriti u velika slova i ako
prva reč počinje velikim slovom dok su sva ostala slova mala sve ostale reči treba da imaju prvo
slovo veliko dok su sva ostala mala. U svim ostalim slučajevima ne menja se veličina slova. Na
primer, ako prva reč počinje velikim i nakon toga ima par malih slova i onda ponovo neko veliko
slovo sve ostale reči ostaju nepromenjene.
Primer:
cc 'ovo JE TesTIRAnje' nb 'Ovo JE testiranje' gggg 'OVO jE TEstiraNJE' sss 'OvO je teSTiraNJE'
Ispis:
aa cc 'ovo je testiranje' nb 'Ovo Je Testiranje' gggg 'OVO JE TESTIRANJE' sss 'OvO je teSTiraNJE'

int main()
{
    int ch;
    int flag = 0, space = 0;
    int lower = 0, upper = 0, first = 0;
    int prev = -1;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == '\'') {
            flag = (flag+1)%2;
            space = lower = upper = first = 0;
        }
        else if (flag && ch == ' ') space = 1;
        else if (flag && !space) {
            if (ch >= 'a' && ch <= 'z') lower = 1;
            else if (ch >= 'A' && ch <= 'Z') upper = 1;
            if (prev == '\'' && ch >= 'A' && ch <= 'Z') first = 1;
            else if (ch >= 'A' && ch <= 'Z') first = 0;
        }
        else if (space) {
            if (first) {
                if (prev == ' ' && ch >= 'a' && ch <= 'z')  ch-=32;
                else if (prev != ' ' && ch >= 'A' && ch <= 'Z') ch+=32;
            }
            else if (lower && !upper) {
                if (ch >= 'A' && ch <= 'Z') ch+=32;
            }
            else if (!lower && upper) {
                if (ch >= 'a' && ch <= 'z') ch-=32;
            }
        }
        putchar(ch);
        prev = ch;
    }
}

25.
Korišćenjem naredbe while i funkcije getchar() za čitanje karaktera potrebno je testirati
jednakost ili nejednakost. Linija se sastoji od brojeva izmedju kojih je znak + ili - i podeljena je na
dva dela. Odvojena znakom =, < ili > pokazati da li leva i desna strana zadovoljavaju znak
(ne)jednakosti koji ih odvaja. U slučaju da je (ne)jednakost tačna, ispisati ‘DA’, u suprotnom,
‘NE’.
Primer: 15+48+65>17+38+110 Primer: 15-38+15+38=10-40+60
Ispis: NE Ispis: DA

int main()
{
	int ch, op1 = '+', op2 = '+', n = 0, r1 = 0, r2 = 0, znak = 0, flag = 1;
	while ((ch = getchar()) != EOF && ch != '\n') {
		if (ch >= '0' && ch <= '9') {
			n = n * 10 + ch - '0';
		}
		else if (ch == '+' || ch == '-') {
			if (flag) {
				if (op1 == '+') r1 += n;
				else if (op1 == '-') r1 -= n;
				op1 = ch;
			}
			else {
				if (op2 == '+') r2 += n;
				else if (op2 == '-') r2 -= n;
				op2 = ch;
			}
			n = 0;
		}
		else if (ch == '>' || ch == '=' || ch == '<') {
			if (op1 == '+') r1 += n;
			else if (op1 == '-') r1 -= n;
			n = 0;
			znak = ch;
			flag = 0;
		}
		else {
			printf("GRESKA");
			exit(1);
		}
	}
	if (op2 == '+') r2 += n;
	else if (op2 == '-') r2 -= n;
	switch (znak) {
	case('>'): if (r1 > r2) printf("DA"); else printf("NE"); break;
	case('='): if (r1 == r2) printf("DA"); else printf("NE"); break;
	case('<'): if (r1 < r2) printf("DA"); else printf("NE"); break;
	default: printf("GRESKA");
	}
	return 0;
}

26.
Koristeći naredbu while i funkciju getchar() za čitanje karaktera, obraditi ulaznu sekvencu
koja se sastoji od malih i velikih slova, cifara, i pravilno zatvorenih zagrada [ i ] tako da se sadržaj
između zagrada zameni izračunatim proizvodom maksimalnog broja pojavljivanja susednih istih
slova i maksimalnog broja susednih istih cifara unutar zagrada. Napomene: Mala i velika slova se
posmatraju kao različita. Između zagrada će uvek biti bar jedan karakter i bar jedna cifra.
Primer: aaa3[AAab3]abb[BC33mmm]
Ispis: aaa3[2]abb[6]
Objašnjenje:
[AAab3A] – ‘A’ se pojavljuje dva puta, ‘a’ se pojavljuje jednom, ‘b’ se pojavljuje jednom, ‘3’ se
pojavljuje jednom, ‘A’ se pojavljuje jednom. Kada pomnožimo broj pojavljivanja dobija se 2.
[B33mmm] – ‘B’ se pojavljuje jednom, ‘3’ se pojavljuje dva puta, ‘m’ se pojavljuje 3 puta. Kada
pomnožimo brojeve dobija se 6.

int main()
{
    int ch, prev = -1;
    int open = 0;
    int letterCount = 1, numberCount = 1;
    int maxLCount = 0, maxNCount = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == '[') open = 1;
        else if (ch == ']') {
            maxLCount = (letterCount > maxLCount)?(letterCount):(maxLCount);
            maxNCount = (numberCount > maxNCount)?(numberCount):(maxNCount);
            printf("[%d]", maxLCount*maxNCount);
            numberCount = letterCount = 1;
            maxLCount = maxNCount = 0;
            open = 0;
        }
        else if (open) {
            if (prev == ch && (ch >= '0' && ch <= '9')) numberCount++;
            else if (prev == ch) letterCount++;
            else {
                maxLCount = (letterCount > maxLCount)?(letterCount):(maxLCount);
                maxNCount = (numberCount > maxNCount)?(numberCount):(maxNCount);
                numberCount = 1;
                letterCount = 1;
            }
        }
        else if (!open) putchar(ch);
        prev = ch;
    }
    return 0;
}

27.
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu slova, cifara i zagrada. Izračunati zbir brojeva koji se nalaze unutar sekvence, pri
čemu se vrednosti brojeva koji se nalaze unutar malih zagrada udvostruče, a vrednosti
brojeva koji se nalaze unutar velikih zagrada kvadriraju pre nego što se dodaju u zbir. Ukoliko
se neki broj nalazi unutar oba tipa zagrada, potrebno je operacije množenja sa dva i
kvadriranja izvršiti redosledom od unutrašnje ka spoljašnjoj.
Primer: Ulaz:

md({3}g)a(sd5a)sad{(10sda)12}g11

Izlaz: 583
Objašnjenje:
Broj 3 se nalazi unutar malih i velikih zagrada, pošto su unutrašnje zagrade velike, a
spoljašnje male, u zbir se dodaje vrednost 18 (18 = 3^2 × 2),

broj 5 se nalazi unutar malih zagrada pa se u zbir dodaje vrednost 10 (10 = 5 × 2),
broj 10 se nalazi unutar malih i velikih zagrada, pošto su unutrašnje zagrade male, a
spoljašnje velike, u zbir se dodaje vrednost 400 (400 = (10 × 2)^2),

broj 12 se nalazi unutar velikih zagrada pa se u zbir dodaje vrednost 144 (144 = 12^2),
broj 11 se ne nalazi unutar zagrada i njegova vrednost se direktno dodaje u zbir (11).

int main()
{
    int ch, n = 0;
    int mala = 0, velika = 0;
    int sum = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9')
            n = n*10+ch-'0';
        else if (ch == '(') mala = 1;
        else if (ch == '{') velika = 1;
        else if (ch == ')') {
            mala = 0;
            n = 2*n;
            if (velika) sum+=n*n;
            else sum+=n;
            n = 0;
        }
        else if (ch == '}') {
            velika = 0;
            n = n*n;
            if (mala) sum+=2*n;
            else sum +=n;
            n = 0;
        }
    }
    if (n != 0) sum+=n;
    printf("%d", sum);
    return 0;
}

28.
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu slova, cifara i zagrada. Izračunati zbir brojeva koji se nalaze unutar sekvence, pri
čemu se vrednosti brojeva koji se nalaze unutar malih zagrada posmatraju kao negativni, a
vrednosti brojeva koji se nalaze unutar velikih zagrada se utrostruče pre nego što se dodaju
u zbir. Ukoliko se neki broj nalazi unutar oba tipa zagrada, potrebno je primeniti obe
transformacije.
Primer: Ulaz: md({3}g)a(sd5a)sad{(10sda)12}g11
Izlaz: 3
Objašnjenje:
Broj 3 se nalazi unutar malih i velikih zagrada, pa se u zbir dodaje vrednost -9 (−9 = −1 ⋅ 3 ⋅ 3),
broj 5 se nalazi unutar malih zagrada pa se u zbir dodaje vrednost -5 (−5 = −1 ⋅ 5),
broj 10 se nalazi unutar malih i velikih zagrada, primenjuju se obe transformacije i u zbir se
dodaje vrednost -30 (−30 = −1 ⋅ 10 ⋅ 3),
broj 12 se nalazi unutar velikih zagrada pa se u zbir dodaje vrednost 36 (36 = 12 . 3),
broj 11 se ne nalazi unutar zagrada i njegova vrednost se direktno dodaje u zbir (11).

int main()
{
    int ch, n = 0;
    int mala = 0, velika = 0;
    int sum = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9')
            n = n*10+ch-'0';
        else if (ch == '(') mala = 1;
        else if (ch == '{') velika = 1;
        else if (ch == ')') {
            mala = 0;
            n = n*(-1);
            if (velika) sum+=3*n;
            else sum+=n;
            n = 0;
        }
        else if (ch == '}') {
            velika = 0;
            n = 3*n;
            if (mala) sum+=(n*(-1));
            else sum +=n;
            n = 0;
        }
    }
    if (n != 0) sum+=n;
    printf("%d", sum);

    return 0;
}

29.
Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu
koja se sastoji od slova, cifara i zagrada. Program ispisuje sumu brojeva. Ako je broj unutar
zagrade formirati novi broj koji se sastoji od parnih pozicija i njega dodati u sumu. Ako je broj
van zagrada ili u ugnježdenim zagradama dodati na sumu obrnuti broj. Napomena, pozicije
cifara u broju računaju se sa leve strane, počevši od 1 (na primer u broju 13579 na poziciji 2
nalazi se cifra 3, na poziciji 4 nalazi se cifra 7).
Primer: Ulaz: md(q2345q(a31b)g141d)a41(sd45a)sad((145sda)1222)g
Izlaz: 634
Objašnjenje:
Suma se formira redom : 35 + 13 + 4 + 14 + 5 + 541 + 22 = 634
U zagradi (q2345q(a31b)g141d) nalaze se brojevi 2345 i 141. U broju 2345 na parnim pozicijama
nalaze se cifre 3 i 5, od kojih formiramo broj 35 i dodamo na sumu. U broju 141 na parnim
pozicijama nalazi se cifra 4, dakle na sumu se dodaje 4.
U ugnježdenoj zagrade se nalazi broj 31, dakle na sumu se dodaje (obrnuti broj) 13.
Van zagrada je broj 41, dakle treba da se doda na sumu broj 14.

int reverse(int n) {
    int reversed = 0;
    do {
        int digit = n % 10;
        reversed = reversed*10+digit;

    }while (n/=10);
    return reversed;
}

int cut(int n) {
    int result = 0, flag = 0;
    do {
        flag = (flag+1)%2;
        if (flag) continue;
        int digit = n % 10;
        result = result*10+digit;

    }while (n/=10);
    return result;
}

int main()
{
    int ch, n = 0;
    int count = 0;
    int sum = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9')
            n = n*10+ch-'0';

        else if (ch == '(') {
            if (count == 1) sum += cut(reverse(n));
            else sum += reverse(n);
            n = 0;
            count++;
        }
        else if (ch == ')') {
            if (count == 1) sum += cut(reverse(n));
            else sum += reverse(n);
            n = 0;
            count--;
        }
        else if ((ch < '0' || ch > '9') && n != 0) {
            if (count == 1) sum += cut(reverse(n));
            else sum += reverse(n);
            n = 0;
        }
    }
    printf("%d", sum);
    return 0;
}

30.
Koristeci naredbu while i funkciju getchar() za citanje karaktera, obraditi ulaznu
sekvencu koja se sastoji od brojva, crtica („-“) i zagrada ( „(“ i „)“ ), tako da se brojevi izmedju 
crtica zarotiraju za jedno mesto u levo, a ako neki broj okruzuje zagrada njega podeliti sa 2.
Pimer: 34(43)5-13(5)4-32(132)1-1(3)
34(43)5 => 43 okruzuje zagrada pa je 43/2 = 21, broj postaje 34215 i rotira se u levo pa postaje 42153
13(5)4 => 5 okruzuje zagrada pa je 5/2 = 2, broj postaje 1324 i rotira se levo pa postaje 3241
Slicno i za ostale...
Output: 42153-3241-26613-11

int brojCifara(int n) {
    int c = 0;
    do {
        c++;
    }while(n/=10);
    return c;
}

int power(int n, int k) {
    int result = 1;
    for (int i = 1; i <= k; i++)
        result*=n;
    return result;
}

int main()
{
    int ch;
    int n = 0, m = 0;
    int flag = 0;

    while ((ch = getchar()) != EOF && ch != '\n') {

        if (ch == '(') flag = 1;
        else if (ch == ')') {
            m/=2;
            n = n*power(10, brojCifara(m));
            n+=m;
            flag = 0;
            m = 0;
        }

        if (ch >= '0' && ch <= '9') {
            if (!flag) n = n*10+ch-'0';
            else m = m*10+ch-'0';
        }
        else if (ch == '-') {
            int prva = n/power(10, brojCifara(n)-1);
            int ostatak = n % power(10, brojCifara(n)-1);
            printf("%d%d", ostatak, prva);
            n = 0;
            putchar(ch);
        }

    }
    int prva = n/power(10, brojCifara(n)-1);
    int ostatak = n % power(10, brojCifara(n)-1);
    printf("%d%d", ostatak, prva);
    return 0;
}