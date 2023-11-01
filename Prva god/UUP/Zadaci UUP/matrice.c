0.
Napisati funkciju koja za uneti broj n pravi matricu kao u primeru za n=45371. Prva
vrsta matrice su cifre broja, svaka sledeća donja vrsta umanjuje broj iz gornje vrste naizmenično za 1
i 2. Prilikom oduzimanja kada se dođe do 0, kreće se opet od 9. Implementirati odgovarajuće ispise
matrice radi testiranja.

4 5 3 7 1
3 4 2 6 0
1 2 0 4 8
0 1 9 3 7
8 9 7 1 6

int main()
{
    int n = 45371;
    int c = 1;
    int mat[5][5];
    for (int j = 4; j >= 0; j--, n/=10) {
        mat[0][j] = n % 10;
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mat[i][j] = mat[i-1][j] - c;
            if (mat[i][j] < 0) mat[i][j] += 10;
        }
        c = (c+2)%2+1;
    }

    for (int i = 0; i < 5; i++, putchar(10)) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", mat[i][j]);
        }
    }

    return 0;
}

1.
Napisati funkciju koja za uneti broj n pravi matricu kao u primeru za n=45371.
Poslednja vrsta su cifre broja, a svaka slededa gornja vrsta uvedava broj naizmenično za 2 i 1.
Prilikom sabiranja kada se dođe do 9, krede se opet od 0. Implementirati odgovarajude ispise matrice
radi testiranja.

0 1 9 3 7
9 0 8 2 6
7 8 6 0 4
6 7 5 9 3
4 5 3 7 1

int main()
{
    int n = 45371;
    int c = 2;
    int mat[5][5];
    for (int j = 4; j >= 0; j--, n/=10) {
        mat[4][j] = n % 10;
    }

    for (int i = 3; i >=0; i--) {
        for (int j = 0; j < 5; j++) {
            mat[i][j] = (mat[i+1][j] + c)%10;
        }
        c = (c+2)%2+1;
    }

    for (int i = 0; i < 5; i++, putchar(10)) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", mat[i][j]);
        }
    }

    return 0;
}

2.
Napisati funkciju koja od date matrice pravi novu matricu tako što svaki element
matrice zamenjuje minimumom iz kolone i vrste u kojoj se nalazi element. Napraviti testni program
koji učitava matricu od korisnika i ispisuje rezultat. Primer:

2 3 5 7 5     1 2 2 2 2
3 5 9 2 8     1 2 2 2 2
1 8 2 5 6     1 1 1 1 1
7 3 4 5 4     1 3 2 2 3
1 3 9 6 5     1 1 1 1 1

#define SIZE 50

int main() {

    int n, M[SIZE][SIZE], T[SIZE][SIZE], min;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &M[i][j]);
            T[j][i] = M[i][j];
        }
    }
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            min = INT_MAX;
            for (int k = 0; k < n; k++) {
                if (M[i][k] < min) min = M[i][k];
                if (T[j][k] < min) min = T[j][k];
            }
            printf("%d ", min);
        }
        printf("\n");
    }
    return 0;
}

3.
Napisati funkciju koja od date matrice pravi novu matricu tako što svaki element
matrice zamenjuje zbirom njemu susednih elemenata u vrsti, ako element ima samo jedan susedni
element onda je zbir jednak tom elementu. Napraviti testni program koji učitava matricu od
korisnika i ispisuje učitanu matricu i rezultat. Primer:

2 3 5 2 1     3 7 5 6 2
3 5 1 2 1     5 4 7 2 2
1 2 2 5 3     2 3 7 5 5
7 3 2 5 4     3 9 8 6 5
1 3 3 1 5     3 4 4 8 1

#define SIZE 50

int main() {

    int n, M[SIZE][SIZE], N[SIZE][SIZE];
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf_s("%d", &M[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) N[i][j] = M[i][j + 1];
            else if (j == n - 1) N[i][j] = M[i][j - 1];
            else N[i][j] = M[i][j - 1] + M[i][j + 1];
        }
    }
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", N[i][j]);
        printf("\n");
    }
    return 0;
}

4.
Napisati funkciju koja za uneti broj n pravi matricu kao u datim primerima. Cifre broja n
se postavljaju na sporednu dijagonalu, a zatim se vrste popunjavaju redom dupliranim brojevima,
kada se dođe do 9, slededi broj je 0. Cifra na sporednoj dijagonali se uvek duplira sa desne strane.
n=45901 n=999 n=90

2 2 3 3 4   8 8 9    8 9
3 4 4 5 5   8 9 9    0 0
8 8 9 9 0   9 9 0
9 0 0 1 1
1 1 2 2 3

#define SIZE 10

int broj_cifara(int n) {
    int r = 0;
    while (n) {
        n /= 10;
        r++;
    }
    return r;
}

int main() {

    int n, A[SIZE], M[SIZE][SIZE], flag = 0;
    scanf_s("%d", &n);
    int k = broj_cifara(n) - 1;
    for (int i = n; i > 0; i /= 10) {
        A[k--] = i % 10;
    }
    k = broj_cifara(n);
    for (int i = 0; i < k; i++) {
        flag = 0;
        for (int j = 0; j < k; j++) {
            if (j == k - i || j == k - i - 1) M[i][j] = A[i];
            else if (j > k - i) {
                if (flag == 0) A[i]++;
                if (A[i] > 9) A[i] -= 10;
                M[i][j] = A[i];
                flag = (flag + 1) % 3;
            }
            else {
                M[i][j] = A[i] - (k - i - j) / 2;
                if (M[i][j] < 0) M[i][j] += 10;
            }
        }
    }
    printf("\n\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) printf("%d ", M[i][j]);
        printf("\n");
    }
    return 0;
}

5.
Napisati funkciju koja za uneti broj n pravi kvadratnu matricu kao u datim primerima,
cifre broja se postavljaju na središnju kolonu, ili na dve središnje kolone ako je parna dimenzija
matrice, a zatim se kolone popunjavaju redom dupliranim brojevima, kada se dođe do 9, slededi broj
je 0. U slučaju neparne dimenzije cifra sa središnje kolone se uvek duplira u koloni ispod.
n=45901 n=9622 n=90

5 6 0 1 2      0 7 3 3     9 0
5 6 0 1 2      9 6 2 2     9 0
4 5 9 0 1      9 6 2 2
4 5 9 0 1      8 5 1 1
3 4 8 9 0

int broj_cifara(int n) {
    int c = 0;
    while (n) {
        c++;
        n /= 10;
    }
    return c;
}

int main()
{
    int n, A[SIZE],B[SIZE], M[SIZE][SIZE];
    scanf("%d", &n);
    int k = broj_cifara(n)-1;
    for (int i = n; i; i /= 10) {
        B[k] = i % 10;
        A[k--] = i % 10;
    }
    k = broj_cifara(n);

    if (k % 2 == 1) {
        int flag = 0, flag2 = 0;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == k/2) M[i][j] = A[j];
                else if (i > k/2) {
                    if (flag == 1) A[j]--;
                    if (A[j] < 0) A[j] = 9;
                    M[i][j] = A[j];
                }
                else M[i][j] = 0;
            }
            if (i > k/2) flag = (flag+1) % 2;
        }

        for (int i = k/2-1; i >= 0; i--) {
            for (int j = 0; j < k; j++) {
                if (flag2 == 0) B[j]++;
                if (B[j] > 9) B[j] = 0;
                M[i][j] = B[j];
            }
            flag2 = (flag2+1) % 2;
        }

    }

    if (k % 2 == 0) {
        int flag = 0, flag2 = 0;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == k/2) M[i][j] = A[j];
                else if (i > k/2) {
                    if (flag == 1) A[j]--;
                    if (A[j] < 0) A[j] = 9;
                    M[i][j] = A[j];
                }
                else M[i][j] = 0;
            }
            if (i >= k/2) flag = (flag+1) % 2;
        }

        for (int i = k/2-1; i >= 0; i--) {
            for (int j = 0; j < k; j++) {
                if (flag2 == 1) B[j]++;
                if (B[j] > 9) B[j] = 0;
                M[i][j] = B[j];
            }
            flag2 = (flag2+1) % 2;
        }

    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }

    return 0;
}


6.
Napisati funkciju koja za uneti broj n pravi matricu kao u datim primerima, cifre broja
se postavljaju na sporednu i glavnu dijagonalu, na glavnoj diganoli u obrnutom redosledu. Zatim se
kolone popunjavaju tako što se između cifara sa dijagnola upisuju brojevi za jedan vedi, a izvan
brojevi za jedan manji od broja na dijagonalama. Smatra se da posle 9 dolazi 0 (0 je za jedan veda od 9).
n=45901  n=9445   n=90

1 9 8 4 4    5 5 5 9     0 9
2 0 8 5 5    4 4 4 0     0 9
2 1 9 6 5    4 4 4 0
2 0 8 5 5    5 5 5 9
1 9 8 4 4

int main() {
    int n, i, j, niz[SIZE], mat[SIZE][SIZE], k = 0;
    scanf("%d", &n);

    while (n) {
        niz[k++] = n % 10;
        n /= 10;
    }

    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {

            if (i == j || i + j == k - 1)
                mat[i][j] = niz[j];
            else if (i < j && i + j < k - 1 || i > j && i + j > k - 1) {
                mat[i][j] = niz[j] - 1;
                if (mat[i][j] < 0) mat[i][j] = 9;
            }
            else{
                mat[i][j] = niz[j] + 1;
                if (mat[i][j] > 9) mat[i][j] = 0;
            }

        }
    }

    for (i = 0; i < k; i++, printf("\n")) {
        for (j = 0; j < k; j++) {
            printf("%d ", mat[i][j]);
        }
    }
    return 0;
}

7.
Napisati funkciju koja za uneti broj n pravi matricu kao u datim primerima, cifre broja
se postavljaju na sporednu i glavnu dijagonalu, a zatim se vrste popunjavaju tako što se između
cifara sa dijagnola upisuju brojevi za jedan manji, a izvan brojevi za jedan vedi od broja na
dijagonalama. Smatra se da posle 9 dolazi 0 (0 je za jedan veda od 9).

n=45901 n=9445 n=90
4 3 3 3 4    9 8 8 9    9 9
6 5 4 5 6    5 4 4 5    0 0
0 0 9 0 0    5 4 4 5
1 0 9 0 1    5 4 4 5
1 0 0 0 1

int broj_cifara(int n) {
    int c = 0;
    while (n) {
        c++;
        n /= 10;
    }
    return c;
}

int main()
{
    int n, A[SIZE], M[SIZE][SIZE];
    scanf("%d", &n);
    int k = broj_cifara(n)-1;
    for (int i = n; i; i /= 10) {
        A[k--] = i % 10;
    }
    k = broj_cifara(n);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (j == k-i-1 || j == i) M[i][j] = A[i];
            else M[i][j] = 0;
        }
    }

    int r = k/2;
    if (k % 2 == 1) r = k/2+1;

    for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    if (i < r) {
                        if (j > i && j < k-i-1) {
                            M[i][j] = A[i]-1;
                            if (M[i][j] < 0) M[i][j] = 9;
                        }
                        else if(j < i || j > k-i-1) {
                            M[i][j] = A[i]+1;
                            if (M[i][j] > 9) M[i][j] = 0;
                            }
                    }
                    else {
                        if (j < i && j > k-i-1) {
                        M[i][j] = A[i]-1;
                        if (M[i][j] < 0) M[i][j] = 9;
                        }
                        else if(j > i || j < k-i-1) {
                        M[i][j] = A[i]+1;
                        if (M[i][j] > 9) M[i][j] = 0;
                        }
                    }
                }
            }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }

    return 0;
}

8.
Korisnik prvo unosi broj N. Zatim unosi matricu N x N . Za svaku vrstu ispisati najvedi neparan broj
u toj vrsti, i koliko se puta on pojavio. Za svaku kolonu ispisati najmanji paran broj u toj koloni, i koliko se
puta on pojavio. Ukoliko se u vrsti ne nalazi ni jedan neparan broj tu vrstu izostaviti u ispisu, takođe ako
se u koloni ne nalazi ni jedan paran tu kolonu izostaviti. Pretpostaviti da je maksimalna dimenzija
matrice 100 x 100.
primer:
4
2 2 13 13
5 1 7  19
0 3 1  3
1 2 3  4
izlaz:

red 1: 13 2
red 2: 19 1
red 3: 3 2
red 4: 3 1
kolona 1: 2 1
kolona 2: 2 2
kolona 4: 4 1

#define SIZE 100

int main()
{
    int n;
    int M[SIZE][SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
    }
    for (int i = 0; i < n; i++) {
        int max = INT_MIN, element = 0, brojac = 0;
        for (int j = 0; j < n; j++) {
            if (M[i][j] % 2 == 1) {
                if (M[i][j] == max) brojac++;
                if (M[i][j] > max) {
                    max = M[i][j];
                    element = M[i][j];
                    brojac = 1;
                }
            }
        }
        if (max != INT_MIN) printf("Vrsta %d: %d %d\n", i+1, element, brojac);
    }
    for (int i = 0; i < n; i++) {
        int min = INT_MAX, element = 0, brojac = 0;
        for (int j = 0; j < n; j++) {
            if (M[j][i] % 2 == 0 && M[j][i] != 0) {
                if (M[j][i] == min) brojac++;
                if (M[j][i] < min) {
                    min = M[j][i];
                    element = M[j][i];
                    brojac = 1;
                }
            }
        }
        if (min != INT_MAX) printf("Kolona %d: %d %d\n", i+1, element, brojac);
    }
    return 0;
}

9.
Napraviti funkciju koja za unetu matricu dimenzija N x N pravi novu matricu čija se polja formiraju
na slededi način. Svako polje u novoj matrici je jednako razlici sume susednih polja iz učitane matrice
(iznad, ispod, levo, desno) i vrednosti sa trenutnog polja. Korisnik učitava ceo broj N i matricu.
( učitana matrica ) ( nova matrica )

n = 3
5 3 6    1 13 -2
3 5 1    9 3  13
2 1 3    2 9  -1

Objašnjenje primera: 1 = 3 + 3 – 5
13 = 6 + 5 + 5 – 3
-2 = 1 + 3 - 6

#define SIZE 100
#define MAX(A,B) ((A>B)?(A):(B))

int provera(int x, int n) {
    return (x >= 0 && x < n);
}

int main()
{
    int n;
    int M[SIZE][SIZE], N[SIZE][SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int gore = 0, dole = 0, levo = 0, desno = 0;
            if (provera(i-1, n)) gore = 1;
            if (provera(i+1, n)) dole = 1;
            if (provera(j-1, n)) levo = 1;
            if (provera(j+1, n)) desno = 1;

            if (gore == 1) N[i][j] += M[i-1][j];
            if (dole == 1) N[i][j] += M[i+1][j];
            if (levo == 1) N[i][j] += M[i][j-1];
            if (desno == 1) N[i][j] += M[i][j+1];

            N[i][j] -= M[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", N[i][j]);
        printf("\n");
    }
    return 0;
}

10.
Napraviti funkciju koja za unetu matricu dimenzija N x N (N>1) pravi novu matricu čija se polja
formiraju na slededi način. Svako polje u novoj matrici ima vrednost zbira maksimuma svih brojeva iz
početne matrice koji nisu u istoj vrsti ili koloni kao to polje i broja u tom polju. Korisnik učitava 
ceo broj N i matricu.( učitana matrica ) ( nova matrica )

n = 3
5 3 7    10 6 12
3 5 1    10 12 6
2 1 3    9  8  8

Objašnjenje primera:
b 0,0 = a 0,0 + max a 1,1 , a 1,2 , a 2,1 , a 2,2 = 5 + 5 = 10
b 1,1 = a 1,1 + max a 0,0 , a 0,2 , a 2,0 , a 2,2 = 5 + 7 = 12

#define SIZE 100
#define MAX(A,B) ((A>B)?(A):(B))

int main()
{
    int n;
    int M[SIZE][SIZE], N[SIZE][SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int max = INT_MIN;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (k != i && l != j) {
                        max = MAX(M[k][l], max);
                    }
                }
            }
            N[i][j] = M[i][j] + max;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", N[i][j]);
        printf("\n");
    }
    return 0;
}



11.
Korisnik učitava ceo broj N i matricu celih pozitivnih brojeva dimenzije N x N. Napraviti funkciju
koja od unete matrice pravi novu matricu čiji se elementi formiraju na slededi način. Svaki element u
novoj matrici jednak je absolutnoj vrednosti razlike minimalnog elementa iz susednih kolona i
maksimalnog elementa iz susednih vrsta. Pretpostaviti da je maksimalna dimenzija matrice 100 x 100.
Primer:
Uneti dimenzije matice: 3
Uneti elemente matrice:
1 2 3
4 5 6
7 8 9
Izlaz :
4 5 4
7 8 7
4 5 4

#define SIZE 100
#define MAX(A,B) ((A>B)?(A):(B))
#define MIN(A,B) ((A<B)?(A):(B))

int provera(int x, int n) {
    return (x >= 0 && x < n);
}

int main()
{
    int n;
    int M[SIZE][SIZE], N[SIZE][SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int max = INT_MIN, min = INT_MAX;
            int dole = 0, gore = 0, desno = 0, levo = 0;
            
            if (provera(i+1, n)) dole = 1;
            if (provera(i-1, n)) gore = 1;
            if (provera(j+1, n)) desno = 1;
            if (provera(j-1, n)) levo = 1;

            for (int k = 0; k < n; k++) {
                if (dole) max = MAX(max, M[i+1][k]);
                if (gore) max = MAX(max, M[i-1][k]);
                if (desno) min = MIN(min, M[k][j+1]);
                if (levo) min = MIN(min, M[k][j-1]);
            }
            N[i][j] = abs(min - max);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", N[i][j]);
        printf("\n");
    }
    return 0;
}

12.
Napisati program koja za unete brojeve n i m formira matricu kao u primeru. Matrica
treba da bude dimenzija m x m, popunjava se spiralno, sa početkom u gornjem levom
uglu. Prva vrednost koja se upisuje u matricu je broj n. Kada se dođe do ivice matrice,
prelazi se na naredni veći broj. Posle 9 se prelazi na 0. 0 ≤ n ≤ 9, 0 ≤ m ≤ 9
n=3 m=5
3 3 3 3 4
7 7 7 8 4
6 1 2 8 4
6 0 9 9 4
6 5 5 5 5

#define SIZE 100
int pom(int i, int j, int m) {
	return (i >= 0 && j >= 0 && i < m && j < m);
}

int main()
{
	int M[SIZE][SIZE], n, m, i, j, smer = 0, brojac = 1;
	int x[] = {1, 0, -1, 0};
	int y[] = {0, 1, 0, -1};
	scanf_s("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) M[i][j] = -1;
	}
	i = j = 0;

	while (brojac <= m * m) {
		int k = i + y[smer], l = j + x[smer];
		if (pom(k, l, m) && M[k][l] == -1) {
			M[i][j] = n;
			i = k;
			j = l;
		}
		else {
			n++;
			if (n > 9) n = 0;
			M[i][j] = n;
			smer = (smer + 1) % 4;
			i = i + y[smer];
			j = j + x[smer];
		}
		brojac++;
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) printf("%d ", M[i][j]);
		printf("\n");
	}
	return 0;
}


13.
Napisati program koja za unete brojeve n i m formira matricu kao u primeru. Matrica
treba da bude dimenzija m x m, popunjava se spiralno, sa početkom u gornjem desnom
uglu. Prva vrednost koja se upisuje u matricu je broj n. Kada se dođe do ivice matrice,
prelazi se na broj koji je za 2 veći. Posle 9 se prelazi na 1. 0 ≤ n ≤ 9, 1 ≤ m ≤ 9.
n=3 m=5
5 3 3 3 3
5 3 1 1 1
5 3 1 9 9
5 5 5 7 9
7 7 7 7 9

#define SIZE 50
int provera(int i, int j, int m) {
    return i >= 0 && j >= 0 && i < m && j < m;
}

int main() {

    int M[SIZE][SIZE], n, m, i, j, smer = 0, brojac = 0;
    int x[] = {-1, 0, 1, 0};
    int y[] = { 0, 1, 0, -1};
    scanf_s("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) M[i][j] = -1;
    }
    i = 0;
    j = m;
    while (brojac <= m * m) {
        int k = i + y[smer], l = j + x[smer];
        if (provera(k, l, m) && M[k][l] == -1) {
            M[i][j] = n;
            i = k;
            j = l;
        }
        else {
            n += 2;
            if (n > 9) n = 1;
            M[i][j] = n;
            smer = (smer + 1) % 4;
            i = i + y[smer];
            j = j + x[smer];
        }
        brojac++;
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) printf("%d ", M[i][j]);
        printf("\n");
    }
    return 0;
}

14.
Napisati program koja učitava kvadratnu matricu brojeva od 0 do 9 i posmatra
redom elemente po kolonama matrice u vidu “zmije”, prvo se posmatra prva kolona od
gore na dole, zatim druga od dole na gore, treća opet od gore na dole, itd. Program
treba da izbroji i ispiše koliki je najduži uzastopni broj pojavljivanja istog broja u
opisanom redosledu posmatranja elemenata matrice. Ispisati broj ponavljanja.
Primer matrice:
3 4 1 6
1 2 9 8
5 6 6 1
2 3 1 1
elemente posmatramo u sledećem redosledu: 3 1 5 2 3 6 2 4 1 9 6 1 1 1 8 6
Ispis: broj ponavljanja:3

#define SIZE 100
int main()
{
	int M[SIZE][SIZE], T[SIZE][SIZE];
	int n, i, j, max = 0, brojac = 0, prethodni = -1;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf_s("%d", &M[i][j]);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			T[i][j] = M[j][i];
	}
	for (i = 0; i < n; i++) {
		for (j = (i % 2 == 0) ? 0 : n - 1; (i % 2 == 0) ? j < n : j >= 0; (i % 2 == 0) ? j++ : j--) {
			if (T[i][j] == prethodni) {
				brojac++;
				prethodni = T[i][j];
			}
			else {
				if (brojac > max) max = brojac;
				brojac = 1;
				prethodni = T[i][j];
			}
			printf("%d ", T[i][j]);
		}
	}
	if (brojac > max) max = brojac;
	printf("\n%d", max);
	return 0;
}


15.
Napisati program koja učitava kvadratnu matricu brojeva od 0 do 9 i posmatra redom
elemente po vrstama matrice u vidu “zmije”, prvo se posmatra prva vrstu sa leva na
desno, zatim druga sa desna na levo, treća opet sa leva na desno itd. Program treba da
izbroji i ispiše kolika je najduža sekvenca brojeva koji su poređani redom rastuće u
opisanom redosledu posmatranja elemenata matrice. Ispisati dužinu sekvence.
Primer matrice:
3 4 1 6
2 1 3 1
3 4 5 5
2 3 4 5
elemente posmatramo u sledećem redosledu: 3 4 1 6 1 3 1 2 3 4 5 5 5 4 3 2
Ispis: duzina sekvence: 5

#define SIZE 100
int main()
{
	int M[SIZE][SIZE];
	int n, i, j, max = 0, brojac = 0, prethodni = -1;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf_s("%d", &M[i][j]);
	}
	for (i = 0; i < n; i++) {
		for (j = (i % 2 == 0) ? 0 : n - 1; (i % 2 == 0) ? j < n : j >= 0; (i % 2 == 0) ? j++ : j--) {
			if (M[i][j] > prethodni) {
				brojac++;
				prethodni = M[i][j];
			}
			else {
				if (brojac > max) max = brojac;
				brojac = 1;
				prethodni = M[i][j];
			}
			printf("%d ", M[i][j]);
		}
	}
	if (brojac > max) max = brojac;
	printf("\n%d", max);
	return 0;
}

16.
Za zadatu matricu velicine n*n i vrednost k, obrnuti svaki prsten matrice u
smeru kazaljke na satu za k puta.
Ulaz:                                    Ulaz:
6 8 Izlaz:                            4 2 Izlaz:

3 2 6 4 5 8    4 2 3 4 9 0    8 1 7 5   7 8 8 1
7 4 3 2 7 1    3 2 9 4 9 0    8 7 4 6   0 4 4 7
0 5 6 9 2 3    2 7 6 9 2 7    7 4 4 9   1 4 7 5
0 7 9 4 9 4    9 2 9 4 2 3    0 1 3 7   3 7 9 6
9 2 2 9 4 9    4 3 4 5 7 2
4 3 2 4 3 2    3 1 8 5 4 6

#define SIZE 200

void siftuj(int *niz, int k, int n) {
    while (k) {
        for (int i = n-1; i > 0; i--) {
            int temp = niz[i];
            niz[i] = niz[i-1];
            niz[i-1] = temp;
        }
        k--;
    }
}

int main() {

    int n, k, mat[SIZE][SIZE], niz[SIZE];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    }

    int brojac = 0;

    while (brojac <= n/2 - 1) {
        int dim = 0;
        for (int i = brojac; i < n-brojac-1; i++) {
            for (int j = brojac; j < n-brojac; j++)
                if (i == brojac || j == n-1-brojac) {
                    niz[dim++] = mat[i][j];
                }
        }
        for (int i = n-1-brojac; i > brojac; i--) {
            for (int j = n-1-brojac; j >= brojac; j--)
                if (i == n-1-brojac || j == brojac) {
                    niz[dim++] = mat[i][j];
                }
        }

        siftuj(niz, k, dim);
        dim = 0;
        for (int i = brojac; i < n-brojac-1; i++) {
            for (int j = brojac; j < n-brojac; j++)
                if (i == brojac || j == n-1-brojac) {
                    mat[i][j] = niz[dim++];
                }
        }
        for (int i = n-1-brojac; i > brojac; i--) {
            for (int j = n-1-brojac; j >= brojac; j--)
                if (i == n-1-brojac || j == brojac) {
                    mat[i][j] = niz[dim++];
                }
        }

        brojac++;
    }
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}

17.
Napisati program koji za unetu kvadratnu matricu veličine n generiše drugu
matricu po sledećem principu: Glavna dijagonala prve matrice treba da postane
sporedna dijagonala nove matrice. Isto važi i za sporednu dijagonalu (glavna i
sporedna dijagonala menjaju mesta). Obratite pažnju da obe dijagonale
posmatramo s leva na desno. Polja koja se ne nalaze na dijagonalama treba da
dobiju vrednost maksimalnog parnog suseda polja na istoj poziciji prve matrice
(susedi su elementi koji se nalaze ispod, iznad, levo i desno u odnosu na
posmatrani element). Ako neko polje nema parne susede, upisuje se 0. Na kraju
ispisati novu matricu.
Ulaz: Izlaz:

4
2 6 1 4    9 2 6 7
3 5 6 8    4 1 8 6
4 1 8 0    0 5 6 8
9 6 3 7    2 0 8 4

#define SIZE 100

int main()
{
    int n;
    int M[SIZE][SIZE], N[SIZE][SIZE];
    int D1[SIZE], D2[SIZE];
    int d1 = 0, d2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) D1[d1++] = M[i][j];
            else if (j == n-i-1) D2[d2++] = M[i][j];
        }
    }
    d1--; d2--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) N[i][j] = D2[d2--];
            else if (j == n-i-1) N[i][j] = D1[d1--];
            else {
                int gore = 0, dole = 0, levo = 0, desno = 0;
                int max = 0;
                
                if (i+1 >= 0 && i+1 < n) dole = 1;
                if (i-1 >= 0 && i-1 < n) gore = 1;
                if (j+1 >= 0 && j+1 < n) desno = 1;
                if (j-1 >= 0 && j-1 < n) levo = 1;

                if (dole)
                    if (M[i-1][j] > max && M[i-1][j] % 2 == 0) max = M[i-1][j];
                if (dole)
                    if (M[i+1][j] > max && M[i+1][j] % 2 == 0) max = M[i+1][j];
                if (desno)
                    if (M[i][j+1] > max && M[i][j+1] % 2 == 0) max = M[i][j+1];
                if (levo)
                    if (M[i][j-1] > max && M[i][j-1] % 2 == 0) max = M[i][j-1];
                N[i][j] = max;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", N[i][j]);
        printf("\n");
    }
    return 0;
}

18.
Napisati program koji ucitava matricu dimenzija NxN, sortira joj elemente po kolonama u neopadajucem poretku, a zatim
sortira cele kolone tako da elementi u poslednjem redu matrice budu u nerastucem poretku.
n = 5
3 6 7 5 3
5 6 2 9 1
2 7 0 9 3
6 0 6 2 6
1 8 7 9 2

2 0 0 1 1
5 6 2 2 2
9 6 6 3 3
9 7 7 5 3
9 8 7 6 6

#define SIZE 20

void bubble_sort(int *niz, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (niz[j] > niz[j+1]) {
                int temp = niz[j];
                niz[j] = niz[j+1];
                niz[j+1] = temp;
            }
        }
    }
}

void swap(int mat[SIZE][SIZE], int kolona, int target, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == target) {
                int temp = mat[i][target];
                mat[i][target] = mat[i][kolona];
                mat[i][kolona] = temp;
            }
        }
    }
}

int main()
{
    int n, mat[SIZE][SIZE], niz[SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            niz[i] = mat[i][j];
        }
        bubble_sort(niz, n);
        for (int i = 0; i < n; i++) {
            mat[i][j] = niz[i];
        }
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < n-1; j++) {
            if (mat[n-1][j] < mat[n-1][j+1])
                swap(mat, j, j+1, n);
        }
    }

    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}

19.
Napisati program u kojem korisnik unosi matricu velicine n x m. Za svaku kolonu matrice proveriti da li je palindrom.
Kolona je palindrom ako se brojevi poklapaju kada se cita odozgo na dole i odozdo na gore. Ako kolona nije palindrom,
treba je rotirati k puta, gde je k najveci element te kolone. Na kraju ispisati promenjenu matricu.
4 5
1 2 2 2
6 3 1 1
5 8 1 1
6 3 3 1
7 2 1 2

6 2 1 2
7 3 3 1
1 8 1 1
6 3 2 1
5 2 1 2

#define SIZE 20

int palindrom(int *niz, int m) {
    for (int i = 0, j = m-1; i < j; i++, j--) {
        if (niz[i] != niz[j]) return 0;
    }
    return 1;
}

int max(int *niz, int m) {
    int max = 0;
    for (int i = 0; i < m; i++) {
        if (niz[i] > max) max = niz[i];
    }
    return max;
}

void siftuj(int *niz, int m, int k) {
    while (k) {
        for (int i = 0; i < m; i++) {
            int temp = niz[i];
            niz[i] = niz[m-1];
            niz[m-1] = temp;
        }
        k--;
    }
}

int main()
{
    int n, m, mat[SIZE][SIZE], niz[SIZE];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            niz[i] = mat[i][j];
        }
        if (palindrom(niz, m))
            continue;
        else {
            int k = max(niz, m);
            siftuj(niz, m, k);
            for (int i = 0; i < m; i++) {
                mat[i][j] = niz[i];
            }
        }
    }

    printf("\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}

20.
Za zadatu matricu velicine m x n izdvojiti sve kvadratne podmatrice (3 x 3 ili vece) ciji se ugaoni elementi ne
pojavljuju u ostatku te podmatrice. Za svaku podmatricu ispisati koordinate njenog gornjeg levog ugla i velicinu.
4 6
1 2 3 4 1 3
3 1 4 1 5 9
2 4 1 7 6 8
5 5 3 1 9 2

(0, 3) dimenzija 3 x 3
(1, 2) dimenzija 3 x 3
(0, 2) dimenzija 4 x 4

#define SIZE 20

void pronadji(int mat[SIZE][SIZE], int n, int m) {
    for (int x = 3; x <= n; x++) {
        for (int y = 3; y <= m; y++) {
            if (x != y) continue;
            for (int i = 0; i < n - x + 1; i++) {
                for (int j = 0; j < m - y + 1; j++) {
                    int c1 = mat[i][j], c2 = mat[i][y+j-1], c3 = mat[x+i-1][j], c4 = mat[x+i-1][y+j-1];
                    int brojac = 0;
                    for (int p = i; p < x+i; p++) {
                        for (int q = j; q < y+j; q++){
                            if (mat[p][q] == c1 || mat[p][q] == c2 || mat[p][q] == c3 || mat[p][q] == c4)
                                brojac++;
                        }
                    }
                    if (brojac == 4) {
                        printf("(%d, %d) dimenzija %d x %d\n", i, j, x, x);
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m, mat[SIZE][SIZE];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    pronadji(mat, n, m);
    return 0;
}