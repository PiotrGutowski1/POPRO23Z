//Lab. 7, zadanie 3
//Bartosz Bagiński, Piotr Gutowski
//Nr albumu 331195, 318472
//Data 21.11.2023
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M (4)
#define N (5)

//allocates memory for a 2D array of given dimensions
//returns NULL on bad alloc or invalid user input
//no printf or scanf inside!
int* alloc2D(int x, int y) {
    if(x < 1 || y < 1) return NULL;

    int* ptr = (int*)malloc(x * y * sizeof(int));
    return ptr;
}

//fills a 2D array of given dimensions so that array[i][j]=10*i+j;
//no printf or scanf inside!
void fill2D(int* array, int x, int y) {
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            *(array + i * y + j) = 10 * i + j;
}


//prints a 2D array in a pretty way!
//no scanf inside!
void print2D(int* array, int x, int y) {
    printf("\n");
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            printf("\t%4d%c", *(array + i * y + j), (j == y - 1) ? '\n' : '\0');
    printf("\n");
}

int main()
{
    int array2D_stat[M][N];
    int *array2D_dyn=NULL;

//allocate array2D_dyn using 'alloc2D' so that it is equivallent to array2D_stat
    array2D_dyn = alloc2D(M, N);

//fill array2D_stat using 'fill2D'
    fill2D((int*)array2D_stat, M, N);

//fill array2D_dyn using 'fill2D'
    fill2D(array2D_dyn, M, N);

//print array2D_stat using 'print2D'
    print2D((int*)array2D_stat, M, N);

//print array2D_dyn using 'print2D'
    print2D(array2D_dyn, M, N);

//Explain the result of 'printf'
// funkcja printf (72 linia) printuje elementy tabeli w petli traktujac ją
// jako jednowymiarowa, natomiast funkcja printf z 75 linii drukuje element [0][1], 
// ktory zostal zmodyfikowany przez wskaznik h, w linii 67. 
//Warning! Do not do such things unless you have a very good reason!
    char *h=(char*)array2D_stat;

    h[5] = 2;

    printf("\n");
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            printf("\t%4d%c", *(h + i * N + j), (j == N - 1) ? '\n' : '\0');
    printf("\n");

    printf("Element array2D_stat[0][1] is now: %d\n",array2D_stat[0][1]);

    return 0;
}