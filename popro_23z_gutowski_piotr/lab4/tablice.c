#include <stdio.h>
#include <string.h>

/**
 * POPRO - Lab 3. Zadanie 3.
 *
 * Zespół: Bartosz Bagiński, Krzysztof Dobosz, Piotr Gutowski.
 */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Wykorzystanie: %s <input_string>\n", argv[0]);
        return 1;
    }

    char *input_string = argv[1];
    int digit_count[10] = {0}; // Inicjalizacja tablicy do zliczania cyfr

    for (int i = 0; i < strlen(input_string); i++) {
        char ch = input_string[i];
        if (ch >= '0' && ch <= '9') {
            int digit = ch - '0';
            digit_count[digit]++;
        }
    }

    printf("Zliczone cyfry:\n");
    for (int i = 0; i < 10; i++) {
        if (digit_count[i] > 0) {
            printf("%d: %d\n", i, digit_count[i]);
        }
    }

    return 0;
}
