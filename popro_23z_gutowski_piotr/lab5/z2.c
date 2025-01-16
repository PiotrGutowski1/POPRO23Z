#include <stdio.h>

/**
 * POPRO - Lab 5 - Zadanie 2.
 * 
 * Zespół projektowy: Bartosz Bagiński, Krzysztof Dobosz, Piotr Gutowski.
 */

int a = 8;

/**
 * Funkcja niezwracająca wartości, wypisuje łańcuch znaków na podstawie
 * podanego adresu oraz liczbę.
 */
void info(char *nazwa_bloku, int zmienna) {
    printf("W bloku %s zmienna a = %d\n", nazwa_bloku, zmienna);
}

/**
 * Funkcja wywołująca inną funkcję.
 * 
 * Jako że a nie jest zdefiniowane w zasięgu tej funkcji, funkcja() korzysta
 * z globalnej definicji a.
 */
void funkcja() {
    info("funkcji", a);
}

/**
 * Funkcja sumująca.
 */
int suma(int x, int y) {
    return x + y;
}

/**
 * Deklaracja funkcji - "zapowiedź" nastąpienia definicji funkcji w późniejszym czasie.
 */
void czy_parzysta(const int);

/**
 * Trzy funkcje zwiększające wartość liczby o 1.
 * 
 * liczba_zwiekszona zwraca zwiększoną o 1 wartość zmiennej X - zdefiniowanej tylko
 * w lokalnym zakresie. zwieksz_liczbe zwiększa lokalną wartość i nic z nią dalej
 * nie robi. Obie te funkcje nie zmieniają permanentnie stanu podanej zmiennej,
 * jako że do dyspozycji mają tylko jej wartość.
 * 
 * zwieksz_przez_adres otrzymuje adres danej zmiennej, za pomocą którego może zwiększyć
 * podaną zmienną. Nowa wartość zostaje zapisana w pamięci pod tym samym adresem, stąd
 * jest dostępna również w zakresie danej funkcji.
 */

int liczba_zwiekszona(int x) {
    return ++x;
}

void zwieksz_liczbe(int a) {
    ++a;
}

void zwieksz_przez_adres(int* x) {
    (*x)++;
}

int main() {
    int a = 20;

    info("main", a); // przesłanianie zmiennej, w zasięgu funkcji main jest a = 20
    funkcja(); // funkcja() skorzysta z globalnego int a = 8
    
    int b = 9;
    int wynik = suma(a, b); // <=> int wynik = a + b

    printf("\na + b = %d\n\n", wynik);

    czy_parzysta(a);
    czy_parzysta(b);
    printf("\na + 1 = %d\n", liczba_zwiekszona(a)); // zwróci 21, ale a dalej == 20

    zwieksz_liczbe(a); // nic nie zmienia w skali main()
    printf("Zmienna 'a' po wywolaniu zwieksz_liczbe = %d\n", a);

    zwieksz_przez_adres(&a); // skorzysta z adresu, więc a w zakresie main() zmieni wartość
    printf("Zmienna 'a' po zwieksz_przez_adres = %d\n", a);

    return 0;
}

/**
 * Definicja wcześniej zadeklarowanej funkcji.
 */
void czy_parzysta(const int x) {
    if(x % 2 == 0)
        printf("Liczba %d jest parzysta!\n", x);
    else
        printf("Liczba %d jest nieparzysta!\n", x);
}