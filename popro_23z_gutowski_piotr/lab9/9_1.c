/**
 * POPRO 23Z. Lab 9. Zadanie 1.
 *
 * Zespół projektowy: Julia Dollani, Piotr Gutowski
 * index: 318472
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT 100

int main(void) {

	double *s, *s_txt, *s_bin;
	short i;
	FILE *textPtr, *binPtr;

	/**
	 * Inicjalizacja tablicy oraz wskaźników do plików. Przygotowanie do
	 * zapisu oraz próba skorzystania z funkcji.
	 */
	
	s = (double *) malloc(MAX_INT * sizeof(double));

	for(i = 0; i < MAX_INT; ++i)
		s[i] = sqrt( (double)(i + 1) );


	if( NULL == (textPtr = fopen("sqrt.txt", "w")) )
		return 1;

	if( NULL == (binPtr = fopen("sqrt.bin", "wb")) )
		return 1;

	for(i = 0; i < MAX_INT; ++i) {
		fprintf(textPtr, "%f\n", s[i]);
		fwrite((s + i), sizeof(double), 1, binPtr);
	}

	fclose(textPtr);
	fclose(binPtr);

	/**
	 * Ponowna inicjalizacja wskaźników do plików - tym razem w trybie
	 * odczytu. Przygotowanie tablic do zapisu.
	 */

	s_txt = (double *) malloc(MAX_INT * sizeof(double));
	s_bin = (double *) malloc(MAX_INT * sizeof(double));

	if( NULL == (textPtr = fopen("sqrt.txt", "r")) )
		return 1;

	if( NULL == (binPtr = fopen("sqrt.bin", "rb")) )
		return 1;

	for(i = 0; i < MAX_INT; ++i) {
		fscanf(textPtr, "%lf\n", (s_txt + i));
		fread((s_bin + i), sizeof(double), 1, binPtr);
	}
	
	fclose(textPtr);
	fclose(binPtr);

	/**
	 * Porównanie plików.
	 */
	
	for(i = 0; i < MAX_INT && fabs(s_txt[i] - s_bin[i]) < 0.000001; ++i);

	printf("\nDla dokładności 0.000001 porownanie %szostalo zakonczone sukcesem.", (i < MAX_INT) ? "nie " : "");

    for(i = 0; i < MAX_INT && fabs(s_txt[i] - s_bin[i]) < 0.0000001; ++i);

	printf("\nDla dokładności 0.0000001 porownanie %szostalo zakonczone sukcesem.", (i < MAX_INT) ? "nie " : "");

	return 0;

	/**
	 * Wynikowe liczby w poszczególnych tablicach są de facto takie same,
	 * lecz z racji zmiennoprzecinkowej reprezentacji występują w nich drobne
	 * różnice bitowe. Nie pozwala to na jednoznaczne porównanie za pomocą
	 * operatora == - stosujemy fabs() (wartość bezwzględna) w celu sprawdzenia,
	 * czy różnica jest mniejsza niż pewien mały margines błędu.
     * Dla dokładności rzędu 0.000001 wartości są porownywalne, a roznice wystepuja od dokadnosci 0.0000001
     * 
     * Plik w formacie tekstowym ma 901 bajtow, a plik w formacie binarnym 800, co oznacza, ze zapis w formacie binarnym jest efektywniejszy.
	 * natomiast pliki w formacie tekstowym, są czytelne dla czlowieka.
     */

};

