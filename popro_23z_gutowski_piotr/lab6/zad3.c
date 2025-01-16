#include <stdio.h>

/**
 * POPRO - Laboratorium 6. Zadanie 3.
 *
 * Zespół projektowy: Bartosz Bagiński, Krzysztof Dobosz, Piotr Gutowski
 */


struct Punkt {
	double x;
	double y;
};

typedef struct Punkt Punkt;

int main() {

	Punkt punkt[20];
	for(int i = 0; i < 20; i++) {
		punkt[i].x = (double)i;
		punkt[i].y = (double)i * 0.5;
	}

	for(int i = 0; i <= 20; i++)
		for(int j = 0; j < 40; j++) {
			if(40 - 2*i == j) {
				printf("* \n");
				break;
			}
			printf("  ");
		}

	return 0;
}

