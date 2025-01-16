/*
 * POPRO 23Z. Lab 9. Zadanie 3.
 *
 * Zespół projektowy: Julia Dollani, Piotr Gutowski
 * index: 318472
*/
#include <stdio.h>
#include <stdlib.h>

void fileAsHex(char *fileName);

int main(void) {

	char name[100];

	printf("Podaj nazwe pliku:\n> ");
	scanf("%s", name);

	fileAsHex(name);

	return 0;
}


void fileAsHex(char *fileName) {

	FILE *fptr;
	unsigned char *buffer;

	if( NULL == (fptr = fopen(fileName, "rb")) )
		exit(1);

	fseek(fptr, 0, SEEK_END);

	long fileSize = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

	if( NULL == (buffer = (unsigned char *)malloc(fileSize)) )
		exit(1);

	fread(buffer, sizeof(unsigned char), fileSize, fptr);
	fclose(fptr);

	printf("Plik w postaci szesnastkowej:\n");

	for(int i = 0; i < fileSize; ++i) {
		printf("%2x ", buffer[i]);
		if((i + 1) % 16 == 0)
			printf("\n");
	}
}


/*
program został przetestowany uzywajac pliku z zadania 1, jego wynikiem jest wyswietlenie danych w formacie szesnastkowym. dane sa wyswietlane jednak nieprawidlowo, bo zostaly zapisane w formacie binarnym.

*/

