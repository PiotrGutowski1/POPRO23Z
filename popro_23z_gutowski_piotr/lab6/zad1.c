#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_VALUE 1
#define END_VALUE 90
#define ROWS 5
#define COLUMNS 10

/**
 * POPRO - Laboratorium 6. Zadanie 1.
 *
 * Zespół projektowy: Bartosz Bagiński, Krzysztof Dobosz, Piotr Gutowski
 */

void displayRow(int *array);

int main() {
	srand(time(NULL));

	int array[ROWS][COLUMNS];

	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLUMNS; j++) {
			printf("======%s", (j == COLUMNS - 1) ? "=\n" : "\0");
			i[array][j] = (rand() % (END_VALUE - START_VALUE + 1) + START_VALUE);
		}
		displayRow(array[i]);
	}

	for(int i = 0; i <= COLUMNS * 6; i++)
		printf("=");

	printf("\n");

	return 0;
}

void displayRow(int *array) {

	for(int i = 0; i < COLUMNS; i++)
		printf("| %3d %s", i[array], (i == COLUMNS - 1) ? "|\n" : "\0");

}

