// Lab. 7, zadanie 1
//
//Imię i nazwisko: Piotr Gutowski, Bartosz Bagiński
//Nr albumu 318472,331195
//Data 20.11.2023
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Wyliczenie stosujemy, gdy chcemy oznaczyc wiele
// predefiniowanych rodzajow jakiejs cechy
// Jest to wygodniejszy zapis rownowazny const
// int OWOC=0; const int WARZYWO=1; const int INNY=2;
enum Rodzaj{OWOC, WARZYWO, INNY};
#define MAX_LEN 16
#define MAX_LICZBA_PRZED 10

struct Przedmiot // Struktura jest zbiorem pol, opisanym typami zmiennych 
{
        char nazwa[MAX_LEN];
        char kolor[MAX_LEN];
        float cena;
        enum Rodzaj rodzaj;
};
struct Klient
{
        char imie[MAX_LEN];
        float gotowka;
        int liczba_przed;
        // Polem struktury moze byc inna struktura, 
        // lub tablica struktur
        struct Przedmiot koszyk[MAX_LICZBA_PRZED];
};
void print_przedmiot(struct Przedmiot p)
{
        // Do pol struktury odwolujemy sie operatorem "."
        printf("%s jest %s i kosztuje %f.\n", p.nazwa, p.kolor, p.cena);
}
void opisz_przedmiot(struct Przedmiot* p, const char* nazwa, const char* kolor,
        enum Rodzaj rodzaj, float cena)
{
        // Do pol wskaznika na strukture odwolujemy sie operatorem "->"
        strcpy(p->nazwa, nazwa);
        strcpy(p->kolor, kolor);
        p->cena = cena;
        p->rodzaj = rodzaj;
}
/*
1(a) Dlaczego napisy kopiujemy do struktury, a nie przypisujemy (czyli dlaczego
w funkcji opisz_przedmiot nie mozna napisać po prostu p->nazwa=nazwa)?
Odpowiedz:
Napis jest tablicą charow, a w jezyku C nie mozna przypisac zawartosci tablicy do innej tablicy w prosty sposob uzywajac "=", 
nalezy skopiowac jej zawartosc uzywajac funkcji strcpy.
*/
// 2 Wprowadzić prostą modyfikację do funkcji 'zaplac', dzięki której sprawdzimy,
// czy klienta stać na same owoce
void zaplac(struct Klient* k)
{
        float suma = 0.0;
        float sumaOwoce = 0.0;
        int n;
        for(n = 0; n < k->liczba_przed; n++)
        {
                suma += k->koszyk[n].cena;
                if(k->koszyk[n].rodzaj == OWOC)
                {
                    sumaOwoce += k->koszyk[n].cena;
                }
        }
        if(sumaOwoce < k->gotowka)
                printf("Klient %s zaplacil za owoce %f.\n", k->imie, sumaOwoce);
        else
                printf("Klient %s nie moze zaplacic %f za owoce!\n", k->imie, sumaOwoce);
        if(suma < k->gotowka)
                printf("Klient %s zaplacil %f.\n", k->imie, suma);
        else
                printf("Klient %s nie moze zaplacic %f!\n", k->imie, suma);        
}
// struktura moze byc przekazywana przez wskazanie lub wartosc
void dodaj_przedmiot(struct Klient* k, struct Przedmiot p)
{
        k->koszyk[k->liczba_przed]=p;
        k->liczba_przed++;
}
/*
1(b) Co się stanie jeżeli zmodyfikujemy pola struktury p wewnątrz
funkcji dodaj_przedmiot?
Odpowiedź :
Zmiana pol struktury p wenątrz funckji dodaj_przedmiot nie będzie widoczna poza tą funkcją poniewaz przekazujemy tą strukturę poprzez wartosc, a nie poprzez wskaznik.
*/

int main() {
        // Zmienne odwolujace sie do struktur definiujemy podobnie do typow podstawowych
        struct Przedmiot banan, pomarancza, pomidor, mleko;
        opisz_przedmiot(&banan, "Banan", "zolty", OWOC, 1.0);
        opisz_przedmiot(&pomarancza, "Pomarancza", "pomaranczowa", OWOC, 1.5);
        opisz_przedmiot(&pomidor, "Pomidor", "czerwony", WARZYWO, 1.2);
        opisz_przedmiot(&mleko, "Mleko", "biale", INNY, 2.0);

        print_przedmiot(banan);
        print_przedmiot(pomarancza);
        print_przedmiot(pomidor);
        print_przedmiot(mleko);
        // 3 Doprowadzić do tego, aby program kompilował się bez "warningów". Nalezalo zmienic specyfikator %d na %lu poniewaz funckja sizeof zwraca long unsined int, a nie po prostu int.
        printf("\nRozmiar struktury Przedmiot: %lu\n", sizeof(struct Przedmiot)); // rozmiar struktury jest suma rozmiarow typow ktore zawiera printf("Rozmiar struktury Klient: %d\n\n", sizeof(struct Klient));
        // dlaczego tu jest taki rozmiar?
        // do struktur rowniez mozemy przypisac pamiec dynamicznie
        struct Klient* klient = (struct Klient*)malloc(sizeof(struct Klient));
        klient->gotowka = 3.0;
        klient->liczba_przed = 0;
        strcpy(klient->imie, "Ala");
        // dlaczego tu robimy tak, a nie poprostu przypisujemy? (tak samo jak w odpowiedzi na pytanie 1a wyzej)
        dodaj_przedmiot(klient, banan);
        dodaj_przedmiot(klient, pomarancza);
        dodaj_przedmiot(klient, mleko);
        zaplac(klient);
        // obowiązkiem programisty jest zwalnianie wczesniej zaalokowanej pamieci:
        free(klient);
        return 0;
}

