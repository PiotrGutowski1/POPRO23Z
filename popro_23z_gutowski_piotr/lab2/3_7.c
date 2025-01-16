#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] )
{
    /*wypisanie erroru dla zbyt malej ilosci wprowadzonych danych*/
    if(argc < 4)
    {
        puts("Zły format:oczekiwany format <sciezka> <imie> <pseudonim> <liczba> ... <liczba>\n");
        return 1;
    }

    printf("Hello World, %s %s\n", argv[1], argv[2]); //wypisanie imienia i pseudonimu na standardowym wyjsciu
    float sum = 0;
    double number = 0;
    int i;
    
    /*sumowanie parametow strumienia wejsciowego od 4 parametru(index 3)*/
    for(i = 3; i < argc; i++)
    {
        number = atof(argv[i]);
        sum = sum + number;
        printf("suma %f\n",sum);
    }
    /*obliczanie sredniej*/
    float counter = argc;
    float average = sum /(counter - 3); //odliczenie od ilosci parametrow ilosci parametrow 1-3 (indexy 0-2) nie liczonych do sredniej
    printf("Srednia = %f\n", average);
    return 0;
}