#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX_L 10

/**
 * POPRO - Lab 3. Zadanie 2.
 * 
 * Zespol: Bartosz Baginski, Krzysztof Dobosz, Piotr Gutowski.
 * 
*/

bool shuffleString(char *str);

int main() {
    char text[MAX_L];
    scanf("%s",text);
    printf("Oryginalny tekst: %s\n", text);
    
    if(shuffleString(text) == false) return 1;
    
    printf("Po wymieszaniu: %s\n", text);
    
    return 0;
}

bool shuffleString(char *str) {
    int length = strlen(str);
    if(length != MAX_L){
        printf("zla dlugosc");
        return false;
    }
    srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Losowy indeks od 0 do i
        // Zamiana miejscami znaków na pozycjach i i j
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return true;
}