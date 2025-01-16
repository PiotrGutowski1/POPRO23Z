#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Funkcja "pierwiastki" zwraca liczbę pierwiastków równania kwadratowego
//postaci a*x^2 + b*x + c=0
//oraz wpisuje wartości tych pierwiastków do zmiennych
//wskazywanych przez wskaźniki wsk_x1 i wsk_x2.
//
//Uwaga!
//W przypadku równania o jednym rozwiązaniu (funkcja zwraca 1)
//do zmiennych wskazywanych przez wsk_x1 i wsk_x2 ma być wpisana ta sama wartość. //W przypadku równania, które nie ma rozwiązań (funkcja zwraca 0),
//zmienne wskazywane przez wsk_x1 i wsk_x2 nie powinny być modyfikowane.

/**
 * POPRO - Lab 5 - Zadanie 3.
 * 
 * Zespół projektowy: Bartosz Bagiński, Krzysztof Dobosz, Piotr Gutowski.
 */

int pierwiastki(double a, double b, double c, double *wsk_x1, double *wsk_x2);

/*funkcja main wyświetla liczbę i wartość pierwiastków
oraz informcję o rodzaju wielomianu*/ 
int main(void) {
    double a, b, c, x1, x2;
    int liczba;

    a = 1.0;
    b = 1.0;
    c = -2.0;

    liczba = pierwiastki(a, b, c, &x1, &x2);
    
    switch(liczba) {
        case 0:
            printf("Równanie %.2lfx^2 + %.2lf + %.2lf nie ma rozwiązań.", a, b, c);
            break;
        
        case 1:
            printf("%.2lfx^2 + %.2lfx + %.2lf == (x - %.2lf)^2", a, b, c, x1);
            break;

        default:
            printf("%.2lfx^2 + %.2lfx + %.2lf == (x - %.2lf)(x - %.2lf)", a, b, c, x1, x2);
            break;
    }
}

int pierwiastki(double a, double b, double c, double *wsk_x1, double *wsk_x2) {
    double delta = (b * b) - 4 * a * c;

    if(delta < 0) return 0;

    *wsk_x1 = ((0 - b) - sqrt(delta)) / 2 * a;
    *wsk_x2 = (delta == 0) ? *wsk_x1 : ((0 - b) + sqrt(delta)) / 2 * a;

    return (*wsk_x1 == *wsk_x2) ? 1 : 2;
}