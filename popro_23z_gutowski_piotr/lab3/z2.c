
#include <stdio.h>
int main(int argc, char** argv) {
    short N = 10;
    int result = 1;
    int i = 1;
    while(i<=N)
    {
        result = result*i; //mnozymy poprzedni wynik przez wartosc "i" i przypisujemy wynik do zmiennej "result"
        i++; //inkrementujemy licznik i
    }
    printf("%d", result);
}