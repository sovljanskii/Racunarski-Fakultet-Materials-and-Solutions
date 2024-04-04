0.
Napisati funkciju pom koja proverava da li argument ima sve cifre manje od 5.
Koristeći tu funkciju, pomnožiti sve parne brojeve u intervalu koji unosi korisnik,
a da zadovoljavaju traženo svojstvo.

int pom(int arg) {
	int cifra;
	while (arg) {
		cifra = arg % 10;
		arg = arg / 10;
		if (cifra > 5) return 0;
	}
	return 1;
}
int main()
{
	int x, y, rezultat = 1;
	scanf("%d %d", &x, &y);
	for (int i = x; i <= y; i++) {
		if (pom(i) == 1 && i % 2 == 0) rezultat *= i;
	}
	printf("%d", rezultat);
	return 0;
}

1.
Napisati funkciju test koja proverava da li broj ima cifru t (brojevi n i t su
argumenti). Koristeći tu funkciju, pomnožiti sve brojeve u intervalu koji unosi
korisnik, a da zadovoljavaju traženo svojstvo.

int pom(int n, int t) {
	int cifra;
	while (n) {
		cifra = n % 10;
		n = n / 10;
		if (cifra == t) return 1;
	}
	return 0;
}
int main()
{
	int x, y, rezultat = 1, t;
	scanf("%d %d %d", &x, &y, &t);
	for (int i = x; i <= y; i++) {
		if (pom(i, t) == 1) rezultat *= i;
	}
	printf("%d", rezultat);
	return 0;
}

2.
Napisati funkciju pom koja proverava da li je argument veći od obrnutog broja.
Koristeći tu funkciju, sabrati sve brojeve koji unosi korisnik (kraj je kada se unese
nula), a da zadovoljavaju traženo svojstvo.

int reverse(int n) {
	int cifra, reversed = 0;
	while (n) {
		cifra = n % 10;
		n = n / 10;
		reversed = reversed * 10 + cifra;
	}
	return reversed;
}
int pom(int n) {
	return (n > reverse(n)) ? (1) : (0);
}
int main()
{
	int x, rezultat = 0;
	do {
		scanf("%d", &x);
		if (pom(x) == 1) rezultat += x;
	} while (x);
	printf("%d", rezultat);
	return 0;
}

3.
Napisati funkciju test koja proverava da li su prve dve cifre argumenta veće od
zadnje dve. U slučaju da je broj jednocifren ili dvocifren smatrati da je uslov
ispunjen.
Koristeći tu funkciju, sabrati sve brojeve koji unosi korisnik, a da zadovoljavaju
traženo svojstvo. Kraj je kada se naidje na broj koji nije ispunio svojstvo.

int reverse(int n) {
	int cifra, reversed = 0;
	while (n) {
		cifra = n % 10;
		n = n / 10;
		reversed = reversed * 10 + cifra;
	}
	return reversed;
}

int test(int n) {
	if (n > 0 && n < 100) return 1;
	int reversed = reverse(n), c1, c2, brojac = 0;
	while (n != 0) {
		if (brojac == 2) return 1;
		c1 = n % 10;
		c2 = reversed % 10;
		n /= 10;
		reversed /= 10;
		brojac++;
		if (c2 > c1) continue;
		else return 0;
	}
}

int main()
{
	int x, rezultat = 0;
	do {
		scanf("%d", &x);
		if (test(x) == 1) rezultat = rezultat + x;
	} while (test(x) != 0);
	printf("%d", rezultat);
	return 0;
}

4.
Napisati funkciju pom koja izračunava broj koji se dobija uklanjanjem prve i
poslednje cifre argumenta. Napraviti zbir brojeva koji se dobijaju primenom
funkcije na brojeve koje unosi korisnik ( korisnik unosi brojeve dok ne unese
nula).

int broj_cifara(int n) {
	int cifra = 0;
	while (n) {
		n = n / 10;
		cifra++;
	}
	return cifra;
}

int pom(int n) {
	int cifra, rezultat = 0, brojCifara = broj_cifara(n), brojac = 0, p = 1;
	while (n != 0) {
		cifra = n % 10;
		n = n / 10;
		brojac++;
		if (brojac == 1) continue;
		if (brojac == brojCifara) break;
		rezultat = rezultat + p * cifra;
		p = p * 10;
	}
	return rezultat;
}

int main()
{
	int x, rezultat = 0;
	do {
		scanf("%d", &x);
		rezultat = rezultat + pom(x);
	} while (x);
	printf("%d", rezultat);
	return 0;
}

5.
Napisati funkciju test koja izračunava broj koji se dobija od svih neparnih cifara
argumenta. Napraviti zbir brojeva koji se dobijaju primenom funkcije na brojeve
koje unosi korisnik ( korisnik unosi brojeve dok ne unese nula).

int test(int n) {
	int cifra, rezultat = 0, p = 1;
	while (n) {
		cifra = n % 10;
		n = n / 10;
		if (cifra % 2 == 0) continue;
		rezultat = rezultat + p * cifra;
		p *= 10;
	}
	return rezultat;
}

int main()
{
	int x, rezultat = 0;
	do {
		scanf("%d", &x);
		rezultat = rezultat + test(x);
	} while (x);
	printf("%d", rezultat);
	return 0;
}

6.
Napisati funkciju pom koja vraca koliko broj ima parnih cifara. Sabrati sve
neparne rezultate koje vraca funkcija za brojeve koje unosi korisnik ( korisnik
unosi brojeve dok ne unese nula).
primer: 12 22 426 0
rezultat: 4 (1+0+3)

int pom(int n) {
	int cifra, rezultat = 0;
	while (n) {
		cifra = n % 10;
		n = n / 10;
		if (cifra % 2 == 0) rezultat++;
	}
	return rezultat;
}

int main()
{
	int x, rezultat = 0;
	do {
		scanf("%d", &x);
		if (pom(x) % 2 == 1) rezultat += pom(x);
	} while (x);
	printf("%d", rezultat);
	return 0;
}

7.
Napisati funkciju fun koja vraca da li broj ima paran broj neparnih cifara
argumenta. Napraviti zbir brojeva koji ispunjavaju uslov ( korisnik unosi brojeve
dok ne unese nula).
primer: 11 22 421 1357 0
rezultat: 1368 (DA, NE, NE, DA)

int fun(int n) {
	int cifra, rezultat = 0;
	while (n) {
		cifra = n % 10;
		n = n / 10;
		if (cifra % 2 == 1) rezultat++;
	}
	return (rezultat % 2 == 0 && rezultat != 0) ? (1) : (0);
}

int main()
{
	int x, rezultat = 0;
	do {
		scanf_s("%d", &x);
		if (fun(x) == 1) rezultat += x;
	} while (x);
	printf("%d", rezultat);
	return 0;
}

8.
Napisati funkciju pom(int arg) koja vrada najvedu razliku između susednih cifara argumenta
(pretpostavimo da argument uvek ima bar dve cifre). Zatim ispisati sve brojeve iz intervala koji unosi
korisnik a kojima je najveda razlika između cifara manja od 3.

int pom(int arg) {
    int c1, c2, r, razlika = 0;
    while (arg) {
        c1 = arg % 10;
        arg /= 10;
        if (arg == 0) break;
        c2 = arg % 10;
        r = abs(c1 - c2);
        if (razlika < r) razlika = r;
    }
    return razlika;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (pom(i) < 3) printf("%d ", i);
    }
    return 0;
}

9.
Napisati funkciju pom(int arg) koja vrada najmanju razliku između susednih cifara argumenta
(pretpostavimo da argument uvek ima bar dve cifre). Zatim ispisati sve brojeve iz intervala koji unosi
korisnik a kojima je najmanja razlika između cifara veda od 5.

int pom(int arg) {
    int c1, c2, r, razlika = 0;
    while (arg) {
        c1 = arg % 10;
        arg /= 10;
        if (arg == 0) break;
        c2 = arg % 10;
        r = abs(c1 - c2);
        if (razlika < r) razlika = r;
    }
    return razlika;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (pom(i) > 5) printf("%d ", i);
    }
    return 0;
}

10.
Napisati funkciju pom(int arg, int k) koja vrada broj dobijen kada se iz argumenta arg uklone sve
cifre manje od k (vratiti nula ako se izbace sve cifre). Sabrati brojeve koje vrada ova funkcija za 3
broja koja korisnik unese, i za k=5.

int pom(int arg, int k) {
    int cifra, razlika = 0, p = 1;
    while (arg) {
        cifra = arg % 10;
        arg = arg / 10;
        if (cifra < k) continue;
        razlika = razlika + p * cifra;
        p *= 10;
    }
    return razlika;
}
int main()
{
    int a, b, c, rezultat;
    scanf("%d %d %d", &a, &b, &c);
    rezultat = pom(a, 5) + pom(b, 5) + pom(c, 5);
    printf("%d", rezultat);
    return 0;
}

11.
Napisati funkciju pom(int arg, int k) koja vrada broj dobijen kada se iz argumenta arg uklone sve
cifre vede od k (vratiti nula ako se izbace sve cifre). Sabrati brojeve koje vrada ova funkcija za 3 broja
koja korisnik unese, i za k=6.

int pom(int arg, int k) {
    int cifra, rezultat = 0, p = 1;
    while (arg) {
        cifra = arg % 10;
        arg = arg / 10;
        if (cifra > k) continue;
        rezultat = rezultat + p * cifra;
        p *= 10;
    }
    return rezultat;
}

int main()
{
    int a, b, c, rezultat;
    scanf("%d %d %d", &a, &b, &c);
    rezultat = pom(a, 6) + pom(b, 6) + pom(c, 6);
    printf("%d", rezultat);
    return 0;
}

12.
Napisati funkciju int pom(int arg, int delilac) koja vrada broj koji se dobije kada se iz argumena
arg izbace sve cifre koji nisu deljive argumentom delilac (delilac је u opsegu *2,9+). Zatim korišdenjem
funkcije pom ispisati sve brojeve iz intervala koji unosi korisnik kojima su cve cifre deljive sa 3.

int pom(int arg, int delilac) {
    int cifra, rezultat = 0, p = 1;
    while (arg) {
        cifra = arg % 10;
        arg = arg / 10;
        if (cifra % delilac != 0) continue;
        rezultat = rezultat + p * cifra;
        p *= 10;
    }
    return rezultat;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (pom(i, 3) == i) printf("%d ", i);
    }
}

13.
Napisati funkciju int pom(int arg, int delilac) koja vrada broj koji se dobije kada se iz argumena
arg izbace sve cifre deljive argumentom delilac (delilac је u opsegu *2,9+). Zatim korišdenjem funkcije
pom ispisati sve brojeve iz intervala koji unosi korisnik koji nemaju ni jednu parnu cifru.

int pom(int arg, int delilac) {
    int cifra, rezultat = 0, p = 1;
    while (arg) {
        cifra = arg % 10;
        arg = arg / 10;
        if (cifra % delilac == 0) continue;
        rezultat = rezultat + p * cifra;
        p *= 10;
    }
    return rezultat;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (pom(i, 2) == i) printf("%d ", i);
    }
}

14.
Napisati funkciju int pom(int arg) koja vrada broj koji se dobije kada se iz argumenta izbaci
njegova najveda cifra (ako ima više jednakih najvedih cifara izbaciju se sve). Zatim napisati program u
kome korisnik unosi brojeve, a ispisuje se razlika unetog broja i broja koji se dobije kada se iz unetog
broja izbaci najveda cifra. Program se završava kada korisnik unese 0.

int maxCifra(int n) {
    int cifra, max = 0;
    while (n) {
        cifra = n % 10;
        n = n / 10;
        if (cifra > max) max = cifra;
    }
    return max;
}

int pom(int arg) {
    int cifra, rezultat = 0, p = 1, max = maxCifra(arg);
    while (arg) {
        cifra = arg % 10;
        arg = arg / 10;
        if (cifra == max) continue;
        rezultat = rezultat + p * cifra;
        p *= 10;
    }
    return rezultat;
}

int main()
{
    int x;
    do {
        scanf("%d", &x);
        printf("%d\n", x - pom(x));
    } while (x);
    return 0;
}

15.
Napisati funkciju int pom(int arg) koja vrada broj koji se dobije kada se iz argumenta izbaci
njegova najmanja cifra (ako ima više jednakih najmanjih cifara izbaciju se sve). Zatim napisati
program u kome korisnik unosi brojeve, a ispisuje se zbir unetog broja i broja koji se dobije kada se iz
unetog broja izbaci najmanja cifra. Program se završava kada korisnik unese 0.

int minCifra(int n) {
    int cifra, min = 9;
    while (n) {
        cifra = n % 10;
        n = n / 10;
        if (cifra < min) min = cifra;
    }
    return min;
}

int pom(int arg) {
    int cifra, rezultat = 0, p = 1, min = minCifra(arg);
    while (arg) {
        cifra = arg % 10;
        arg = arg / 10;
        if (cifra == min) continue;
        rezultat = rezultat + p * cifra;
        p *= 10;
    }
    return rezultat;
}

int main()
{
    int x;
    do {
        scanf("%d", &x);
        printf("%d\n", x + pom(x));
    } while (x);
    return 0;
}

16.
Napisati funkciju int pom(int arg) koja vrada broj koji se dobije kada se iz argumenta arg
izbace sve proste cifre. Za određivanje da li je cifra prosta napisati dodatnu funkciju int prost(int
n) koja vrada 1 ukoliko je broj n prost, ili 0 ukoliko je n složen broj. Zatim korišdenjem funkcije pom
ispisati sve brojeve iz intervala koji unosi korisnik koji imaju sve proste cifre. Napomena: 0 i 1 se ne
ubrajaju u proste brojeve!

int prost(int n) {  
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int provera(int n) {
    int c;
    while (n != 0) {
        c = n % 10;
        n = n / 10;
        if (c == 1 || c == 0) return 1;
    }
    return 0;
}
int pom(int arg) {
    int c, r = 0, p = 1;
    while (arg != 0) {
        c = arg % 10;
        arg = arg / 10;
        if (prost(c) == 1) continue;
        r = r + p * c;
        p = p * 10;
    }
    return r;
}
int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (pom(i) == 0 && provera(i) == 0) printf("%d ", i);
    }
}

17.
Napisati funkciju int pom(int n) koja vrada kvadrat proizvoda prve i poslednje cifre broja, i
dodatnu funkciju int obilan(int n) koja vrada 1 ukoliko je broj n obilan broj, ili 0 ukoliko nije. Broj
n je obilan ako mu je zbir svih pravih delilaca strogo vedi od n. Korišdenjem napisanih funkcija ispisati sve
obilne brojeve iz intervala koji unosi korisnik koji su manji od kvadrata proizvoda svoje prve i poslednje
cifre.

int reverse(int n) {
    int c, r = 0;
    while (n != 0) {
        c = n % 10;
        n = n / 10;
        r = r * 10 + c;
    }
    return r;
}
int pom(int arg) {
    int c1 = 0, c2 = 0;
    int rev = reverse(arg);
    while (arg != 0) {
        c1 = arg % 10;
        c2 = rev % 10;
        break;
    }
    return (c1*c2)*(c1*c2);
}
int obilan(n) {
    int r = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) r = r + i;
    }
    if (r > n) return 1;
    return 0;
}
int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (obilan(i) == 1 && i < pom(i)) printf("%d ", i);
    }
}

18.
Napisati funkciju int pom(int n) koja vrada kvadrat zbira prve i poslednje cifre broja, i
dodatnu funkciju int oskudan(int n) koja vrada 1 ukoliko je broj n oskudan broj, ili 0 ukoliko nije.
Broj n je oskudan ako mu je zbir svih pravih delilaca strogo manji od n.Korišdenjem napisanih funkcija
ispisati sve oskudne brojeve iz intervala koji unosi korisnik koji su vedi od kvadrata zbira svoje prve i
poslednje cifre.

int reverse(int n) {
    int c, r = 0;
    while (n != 0) {
        c = n % 10;
        n = n / 10;
        r = r * 10 + c;
    }
    return r;
}
int pom(int arg) {
    int c1 = 0, c2 = 0;
    int rev = reverse(arg);
    while (arg != 0) {
        c1 = arg % 10;
        c2 = rev % 10;
        break;
    }
    return (c1+c2)*(c1+c2);
}
int oskudan(n) {
    int r = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) r = r + i;
    }
    if (r < n) return 1;
    return 0;
}
int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (oskudan(i) == 1 && i > pom(i)) printf("%d ", i);
    }
}

19.
Napisati funkciju int pom(int n) koja vrada proizvod pravih prostih delilaca broja, i dodatnu
funkcijuint prost(int n) koja vrada 1 ukoliko je broj nprost broj, ili 0 ukoliko nije.Korišdenjem
napisanih funkcija ispisati sve brojeve koji su jednaki proizvodu svojih pravih prostih delilacaiz intervala
koji unosi korisnik.

int prost(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int pom(int arg) {
    int r = 1;
    for (int i = 1; i < arg; i++) {
        if (prost(i) == 1 && arg % i == 0) r = r * i;
    }
    return r;
}
int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (pom(i) == i) printf("%d ", i);
    }
}

20.
Napisati funkciju int armstrong(int n) koja proverava da li je zadati broj n
Armstrongov. Broj je armstrongov ako može da se dobije kao zbir svih svojih cifara
stepenovanih na broj cifara.
Na primer, broj 153 je Armstrongov jer .
Takođe, broj 1634 je Armstrongov jer
Napisati program koji pita korisnika da unese ceo broj n, i potom pomoću gore opisane
funkcije ispisuje prvih n Armstrongovih brojeva, počevši od 0. Na primer, za n=12, treba
ispisati:
0 1 2 3 4 5 6 7 8 9 153 370

int broj_cifara(int n) {
    int c = 0;
    while (n != 0) {
        n = n / 10;
        c++;
    }
    return c;
}
int armstrong(int n) {
    int c, r = 0, m = broj_cifara(n), temp = n;
    while (n != 0) {
        c = n % 10;
        n = n / 10;
        (int)r = r + pow(c, m);
    }
    if (temp == r) return 1;
    return 0;
}
int main() {
    int n, k = 0, i = 0;
    scanf_s("%d", &n);
    while (k != n) {
        if (armstrong(i) == 1) {
            printf("%d ", i);
            k++;
        }
        i++;
    }
}

21.
Napisati funkciju int sumaSimetricnih(int n) koja proverava da li za zadati broj n važi
da mu je suma svim simetričnih cifara (prve i poslednje, druge i pretposlednje,...)
jednaka broju cifara.
Na primer, za sledeće brojeve važi traženi uslov: 1, 11, 132, 3221, 2132
Ispisati sve brojeve iz intervala koje unosi korisnik takve da važi da im je zbir simetričnih
cifara jednak broju cifara, na primer za interval 10 i 350 treba ispisati:
11, 20, 132, 231, 330

int broj_cifara(int n) {
    int c = 0;
    while (n != 0) {
        n = n / 10;
        c++;
    }
    return c;
}
int reverse(int n) {
    int c, r = 0;
    while (n != 0) {
        c = n % 10;
        n = n / 10;
        r = r * 10 + c;
    }
    return r;
}
int sumaSimetricnih(int n) {
    int c1, c2, dig = broj_cifara(n), rev = reverse(n);
    int brojac = 1, mid = dig / 2 + 1;
    while (n != 0) {
        c1 = n % 10;
        c2 = rev % 10;
        if (brojac == mid && dig % 2 == 1) c1 = 0;
        n = n / 10;
        rev = rev / 10;
        brojac++;
        if (c1 + c2 != dig) return 0;
        if ((brojac == mid && dig % 2 == 0) || (brojac == mid+1 && dig % 2 == 1)) break;
    }
    return 1;
}
int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (sumaSimetricnih(i) == 1) printf("%d ", i);
    }
}

22.
Napisati funkciju int swap(int arg, int x, int y) koja vraća ceo broj koji se dobije
kada se celom broju arg zamene cifre na pozicijama x i y. Pozicije se gledaju od
poslednje cifre i počinju od 1. Ispisati sve brojeve iz intervala koje unosi korisnik takve da
su strogo veći od broja koji se dobije zamenom cifre jedinica i cifre stotina.
Napomena: funkcija swap(7683, 1, 2) vraća broj 7638, u broju 7683 cifra 3 je na poziciji
1, a cifra 8 je na poziciji 2
Primer: 4270 4320
Ispis: 4270 4271 4280 4281 4290 4291 4300 4301 4302 4310 4311 4312 4320

int swap(int arg, int x, int y) {
    int c, c1, c2, r = 0, brojac = 1, p = 1;
    int temp = arg;
    while (temp != 0) {
        c = temp % 10;
        temp = temp / 10;
        if (brojac == x) c1 = c;
        if (brojac == y) c2 = c;
        brojac++;
    }
    brojac = 1;
    while (arg != 0) {
        c = arg % 10;
        arg = arg / 10;
        if (brojac == x) c = c2;
        if (brojac == y) c = c1;
        r = r + p * c;
        p = p * 10;
        brojac++;
    }
    return r;
}

int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (swap(i,1,3) < i) printf("%d ", i);
    }
}

23.
Napisati funkciju int zameniNajmanjom(int arg, int x) koja vraća ceo broj koji se
dobije kada se u celom broju arg cifra na poziciji x zameni najmanjom cifrom broja.
Pozicije se gledaju od poslednje cifre i počinju od 1. Ako je najmanja cifra na datoj
poziciji, ostaje isti broj. Korišćenjem date funkcije ispisati sve brojeve iz intervala (u kom
su brojevi veći od 100) koje unosi korisnik takve da im cifra stotina nije najmanja cifra.
Napomena: funkcija zameniNajmanjom(7683, 2) vraća broj 7633, u broju 7683 na
poziciju 2 se postavlja cifra 3 koja je najmanja cifra datog broja.
Primer: 230 250
Ispis: 230, 231, 240, 241

int najmanja(int n) {
    int c, min = 9;
    while (n != 0) {
        c = n % 10;
        n = n / 10;
        if (c < min) min = c;
    }
    return min;
}
int zameniNajmanjom(int arg, int x) {
    int c, r = 0, min = najmanja(arg), brojac = 1, p = 1;
    while (arg != 0) {
        c = arg % 10;
        arg = arg / 10;
        if (brojac == x) c = min;
        brojac++;
        r = r + p * c;
        p = p * 10;
    }
    return r;
}
int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    for (int i = a; i < b; i++) {
        if (zameniNajmanjom(i,3) != i) printf("%d ", i);
    }
}

24.
Napisati funkciju int pom(int n) koja provera da li je prosleđeni argument Fibonačijev broj,
ako jeste vraća njegovu poziciju u Fibonačijevom nizu (za broj 1 vraća 2, za 2 vraća 3, za 3 vraća
4, itd...) u slučaju da broj nije Fibonačijev funkcija vraca -1. Proveriti za svaki broj iz intervala
[n,m] da li je njegov zbir cifara Fibonačijev broj i ako jeste ispisati njegovu poziciju u
Fibonačijevom nizu.
Primer: 10 50
Ispis: 2 3 4 5 6 3 4 5 6 4 5 6 5 6 7 5

int pom(int n) {
    int a = 0, b = 1, sledeci, brojac = 1;
    for (int i = 0; i < n; i++) {
        if (n == 0) return 1;
        if (n == 1) return 2;
        sledeci = a + b;
        a = b;
        b = sledeci;
        brojac++;
        if (sledeci == n) return brojac;
    }
    return -1;
}
int zbir_cifara(int n) {
    int c, r = 0;
    while (n != 0) {
        c = n % 10;
        n = n / 10;
        r = r + c;
    }
    return r;
}
int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (pom(zbir_cifara(i)) != -1) printf("%d ", pom(zbir_cifara(i)));
    }
}

25.
Napisati funkciju int cut(int n, int k) koja prima broj n i poziciju k. Pozicija se računa od cifre
jedinica i počinje od 1. Funkcija cut(n, k) vraća broj formiran tako što se cifre broja n okrenu oko
pozicije k. Na primer, za n=123456 i k=3 rezultat je 456123, za n=123 i k=2 rezultat je 312. Broj k
će uvek biti manji od broja cifara broja n i veći od nule. Funkciju iskoristiti za ispis svih brojeva iz
intervala [a, b], koji unosi korisnik, za koje važi da kada se okrenu oko cifre stotina dobije se broj
strogo veći od broja koji se dobija okretanjem oko cifre desetica (1000 <= a <= b).
Primer: 1220 1304
Ispis: 1220 1221 1222 1300 1301 1302 1303 1304

int cut(int n, int k) {
    int c, desni = 0, levi = 0, brojac = 1, poz;
    int p1 = 1, p2 = 1, flag = 0, temp = n;
    while (temp) {
        c = temp % 10;
        if (brojac == k) poz = brojac;
        brojac++;
        temp /= 10;
    }
    brojac = 1;
    while (n) {
        c = n % 10;
        if (flag) {
            levi = levi + p2 * c;
            p2 *= 10;
        }
        else {
            desni = desni + p1 * c;
            p1 *= 10;
        }
        if (brojac == poz) flag = 1;
        brojac++;
        n /= 10;
    }
    return (p2 * desni + levi);
}

int main()
{
    int l1, l2;
    scanf_s("%d %d", &l1, &l2);
    for (int i = l1; i <= l2; i++) {
        if (cut(i, 3) > cut(i, 2)) printf("%d ", i);
    }
    return 0;
}

26.
Napisati funkciju double aritmeticka_sredina(int n, int m) koja vraća aritmetičku sredinu
prvih m cifara broja n. Podrazumevati da m neće biti veći broj od broja cifara broja n. Napisati i
iskoristiti pomoćnu funkciju int broj_cifara(int n) koja vraća broj cifara broja n. Korišćenjem
datih funkcija ispisati sve brojeve iz intervala koji korisnik unese takve da im je aritmetička
sredina prve 2 cifre manja od broja cifara.
Primer: 400 500
Ispis: 400 401 402 403 404 405 406 407 408 409 410 411 412 413 414 415 416 417 418 419

int broj_cifara(int n) {
    int c = 0;
    while (n != 0) {
        n = n / 10;
        c++;
    }
    return c;
}
int reverse(int n) {
    int c, r = 0;
    while (n != 0) {
        c = n % 10;
        n = n / 10;
        r = r * 10 + c;
    }
    return r;
}
double aritmeticka_sredina(int n, int m) {
    int br = reverse(n), r = 0, c, brojac = 0;
    while (br != 0) {
        c = br % 10;
        br = br / 10;
        brojac++;
        r = r + c;
        if (brojac == m) break;
    }
    return (r / m);
}
int main()
{
    int l1, l2;
    scanf_s("%d %d", &l1, &l2);
    for (int i = l1; i < l2; i++) {
        if (aritmeticka_sredina(i, 2) < broj_cifara(i)) printf("%d ", i);
    }
    return 0;
}

27. Napisati funkciju pom(int arg) koja za prosleđeni broj vraća njemu najbliži kvadrat nekog
prirodnog broja. Ako su dva kvadrata podjednako blizu prosleđenoj vrednosti, vratiti veći.
Primeniti funkciju pom na sve brojeve iz intervala koji unosi korisnik i ispisati rezultate.
Primer: Ulaz: 3 22
Izlaz: 4 4 4 4 9 9 9 9 9 9 16 16 16 16 16 16 16 16 25 25

#define MIN(A,B) ((A<B)?(A):(B))

int pom(int arg) {
    int prethodni = 0, trenutni = 0;
    int broj = 1;

    while (arg >= trenutni) {
        prethodni = trenutni;
        trenutni = broj*broj;
        broj++;
    }

    if (abs(arg-trenutni) > abs(arg-prethodni)) return prethodni;
    else return trenutni;

}

int main () {
    int l1, l2;
    scanf("%d %d", &l1, &l2);
    for (int i = l1; i <= l2; i++) {
        printf("%d ", pom(i));
    }
    return 0;
}

28. Napisati funkciju pom(int arg) koja za prosleđeni broj vraća njemu najbliži prost broj.
Ako su dva prosta broja podjednako blizu prosleđenoj vrednosti, vratiti manji. Primeniti
funkciju pom na sve brojeve iz intervala koji unosi korisnik i ispisati rezultate.
Primer: Ulaz: 8 22
Izlaz: 7 7 11 11 11 13 13 13 17 17 17 19 19 19 23

int prost(int n) {
    for (int i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int f(int arg) {
    int prime1 = 2, prime2 = 2;
    for (int i = 2; 1; i++) {
        if (prost(i)) prime1 = i;
        if (prime1 > arg) break;
    }
    for (int i = 2; i < prime1; i++) {
        if (prost(i) && i == prime1) break;
        if (prost(i)) prime2 = i;
    }
    return (abs(arg-prime1) < abs(prime2-arg))?(prime1):(prime2);

}

int main () {
    int l1, l2;
    scanf("%d %d", &l1, &l2);
    for (int i = l1; i <= l2; i++) {
        printf("%d ", f(i));
    }
    return 0;
}

29.
Napisati funkciju pom(int arg) koja za prosleđeni broj pronalazi cifru koja se nalazi na sredini
broja. Ukoliko se broj sastoji od parnog broja cifra, vratiti veću srednju cifru.
Napisati program koji ispisuje sve brojeve iz intervala koji korisnik unese ukoliko je broj iz
intervala deljiv kubom svoje srednje cifre.
Primer: Ulaz: 819 1030
Izlaz: 819 824 837 864 910 911 912 913 914 915 916 917 918 919
920 928 1010 1011 1012 1013 1014 1015 1016 1017 1018 1019 1024
Objašnjenje za funkciju pom:
Na primer arg = 52617, funkcija pom treba da vrati cifru u sredini (na poziciji 3), dakle cifru 6.
Na primer arg = 526173, razmatramo cifru 6 (koja se nalazi na poziciji 3) i cifru 1 (koja se nalazi
na poziciji 4). Funkcija treba da vrati cifru koja je veća max(6, 1), dakle cifru 6.

int brojCifara(int arg) {
    int brojac = 0;
    while (arg) {
        brojac++;
        arg /= 10;
    }
    return brojac;
}

int pom(int arg) {
    int br = brojCifara(arg);
    if (br & 1) {
        int brojac = 0;
        while (arg) {
            if (brojac == br/2) return arg % 10;
            brojac++;
            arg /= 10;
        }
    }
    else {
        int brojac = 0;
        int leva = 0, desna = 0;
        while (arg) {
            if (brojac == br/2 - 1) desna = arg % 10;
            else if (brojac == br/2) leva = arg % 10;
            brojac++;
            arg /= 10;
        }
        return (desna > leva)?(desna):(leva);
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++) {
        int srednjaCifra = pom(i);
        if (pom(i) != 0 && i % (int)pow(pom(i), 3) == 0)
            printf("%d ", i);
    }
    return 0;
}

30.
Napisati funkciju pom(int arg) koja za prosledjeni broj kreira i vraca najveci broj koji moze da se dobije 
pomeranjem njegovih cifara. Npr. za 1537 funkcija vraca 7531, za 3771 funkcija vraca 7731. Koristeci funkciju
ispisati sve parne brojeve koje funkcija vraca za interval koji korisnik unese.
Input: 0 30
Output: 0 2 4 6 8 2 22 32 42 52 62 72 82 92

int maxDigit(int n) {
    int max = 0;
    do {
        int digit = n % 10;
        if (digit > max) max = digit;
    }while(n/=10);
    return max;
}

int checkMax(int n) {
    int counter = 0;
    int max = maxDigit(n);
    do {
        int digit = n % 10;
        if (digit == max) counter++;
    }while(n/=10);
    return counter;
}

int removeMax(int arg) {
    int rez = 0, p = 1;
    int max = maxDigit(arg);
    do{
        int digit = arg % 10;
        if (digit == max) continue;
        rez = rez+digit*p;
        p*=10;
    }while(arg/=10);
    return rez;
}

int pom(int arg) {
    int rez = 0;
    while(arg) {
        int max = maxDigit(arg);
        int count = checkMax(arg);
        for (int i = 0; i < count; i++) {
            rez = rez*10+max;
        }
        arg = removeMax(arg);
    }
    return rez;

}

int main()
{
    int start = 0, end = 30;
    for (int i = start; i <= end; i++) {
        if (pom(i) % 2 == 0) printf("%d ", pom(i));
    }
    return 0;
}

32.
Napisati funkciju double harmonic(int n) koja za prosledjeni broj racuna Harmonijski red 
(1 + 1/2 + 1/3 + 1/4 + 1/5 ... 1/n). Zatim napisati funkciju pom(int n, int k) koja ce harmonijskom redu
od n clanova uzeti prvih k cifara posle decimale i tako formirati broj, tom broju izbaciti sve proste cifre. 
Funkcija treba da vrati taj broj.  Korisnik unosi interval i treba da se ispisu svi brojevi za koje vazi da 
funkcija pom za k = 4, vraca trocifren broj.
Primer.   Za n = 9 i k = 4  ->  harmonijski red je 2.82896, prve 4 cifre posle decimale su 8289. 
Kada se izbace proste cifre iz tog broja, dobija se 889.
Input: 80 150
Output: 80 87 93 96 120 124 125 126 130 132 150


double harmonic(int n) {
    double rez = 0;
    for (int i = 1; i <= n ;i++) {
        rez+= 1.0/i;
    }
    return rez;
}

int power(int n, int k) {
    int result = 1;
    for (int i = 1; i <= k; i++)
        result*=n;
    return result;
}

int prost(int n) {
    if (n == 0 || n == 1) return 0;
    for (int i = 2; i<=n/2; ++i)
        if (n % i == 0) return 0;
    return 1;
}

int pom(int n, int k) {
    double rez = harmonic(n);
    int kCif = rez*power(10, k);
    kCif %= power(10, k);

    int r = 0, p = 1;

    do{
        int dig = kCif%10;
        if (prost(dig)) continue;
        r = r+dig*p;
        p*=10;
    }while(kCif/=10);
    return r;
}

int main()
{
    int start = 80, end = 150;
    for (int i = start; i <= end; i++) {
        if (pom(i, 4) >= 100 && pom(i, 4) <= 999) printf("%d ", i);
    }
    return 0;
}
