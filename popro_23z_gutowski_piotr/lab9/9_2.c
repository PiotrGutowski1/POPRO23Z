/**
 * POPRO 23Z. Lab 9. Zadanie 2.
 *
 * Zespół projektowy: Julia Dollani, Piotr Gutowski
 * index: 318472
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DB 3

typedef struct {
	int id;
	char name[64];
	double salary;
	char *periodic_assessment;
} data_base_entry;


double generateMoney() {
	return (double)(rand() % 5001 + 5000);
}


int main(void) {

	srand( time(NULL) );
	FILE *fptr;

	data_base_entry *db = (data_base_entry *)malloc(MAX_DB * sizeof(data_base_entry));

	char name[] = "Jan Kowalski";
	char comment[] = "Jesteś super";

	for(int i = 0; i < MAX_DB; ++i) {
		db[i].id = i;
		db[i].salary = generateMoney();

		db[i].periodic_assessment = (char *)malloc(sizeof(char *));
		
		strcpy(db[i].name, name);
		strcpy(db[i].periodic_assessment, comment);
	}

	if( NULL == (fptr = fopen("baza.txt", "w")) )
		return 1;

	fprintf(fptr, "id | %64s | %8s | %64s\n", "name", "salary", "periodic assessment");

	for(int i = 0; i < MAX_DB; ++i)
		fprintf(fptr, "%2d | %64s | %8.2lf | %64s\n", 
				db[i].id, 
				db[i].name, 
				db[i].salary, 
				db[i].periodic_assessment
		);

	fclose(fptr);

	return 0;
}

