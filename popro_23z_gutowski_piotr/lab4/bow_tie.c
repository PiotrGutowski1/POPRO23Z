#include <stdio.h>

/**
 * POPRO - Lab 3. Zadanie 1.
 *
 * Zespół: Bartosz Bagiński, Krzysztof Dobosz, Piotr Gutowski.
 * 
 * Obrazek muchy będzie wyglądał poprawnie dla N = M.
 */

int main() {
        int N, M;

        printf("Podaj liczbe kolumn i liczbe wierszy po sobie.\nnp. 2 3 -> 2 kolumny, 3 wiersze.\n");
        scanf("%d %d", &N, &M);

        for(int i = 0; i < M; i++) {
                for(int j = 0; j < N; j++)
                        printf("%s", ((j > i && j + 1 < M - i) || (j >= M - i && j + 1 <= i)) ? "." : "*");
                printf("\n");
        }
        return 0;
}
