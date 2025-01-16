








#include "vecin.h"
#include "vecout.h"
#include "veccalc.h"


int main()
{
    static_vector_t v1,v2,v3;
    
    printf("\n\n\nSTART:\n");
    //(a) insert your name here:
     printf("Author: Piotr Gutowski, Krzysztof Dobosz, Bartosz Baginski\n");

    printf("Define v1:\n");
    switch(vec_fromkeyboard(&v1))
    {
        case _VEC_OK:
            break;
        case _VEC_NULL:
            printf("Error: NULL pointer\n");
            return 0;
        case _VEC_DIM:
            printf("Error: invalid vector length\n");
            return 0;
        case _VEC_INPUT:
            printf("Error: not a number\n");
            return 0;
        default:
            printf("Error: unknown\n");
            return 0;
     }
    
    printf("\nDefine v2:\n");
    switch(vec_fromkeyboard(&v2))
    {
        case _VEC_OK:
            break;
        case _VEC_NULL:
            printf("Error: NULL pointer\n");
            return 0;
        case _VEC_DIM:
            printf("Error: invalid vector length\n");
            return 0;
        case _VEC_INPUT:
            printf("Error: not a number\n");
            return 0;
        default:
            printf("Error: unknown\n");
            return 0;
     }
    
    //(b) display v1 and v2 here using functions defined in vecout.h
    vec_print_vertically(&v1);
    vec_print_vertically(&v2);
    double dot_product=0.0;
    //(c) calculate dot product of v1 and v2 using functions defined in veccalc.h. Provide full error handling. 
    int error = 0;
    dot_product = vec_dotproduct(&v1,&v2,&error);
    switch(error)
    {
        case _VEC_OK:
            break;
        case _VEC_NULL:
            printf("Error: NULL pointer\n");
            return 0;
        case _VEC_DIM:
            printf("Error: invalid vector length\n");
            return 0;
        case _VEC_INPUT:
            printf("Error: not a number\n");
            return 0;
        default:
            printf("Error: unknown\n");
            return 0;
     }
    printf("\nv1 * v2 = %f\n",dot_product);


    //(d) calculate v3=v1+v2 using functions defined in veccalc.h. Provide full error handling. 
    int error_sum = 0;
    vec_sum(&v1,&v2,&v3,&error_sum);
    switch(error_sum)
        {
            case _VEC_OK:
                break;
            case _VEC_NULL:
                printf("Error: NULL pointer\n");
                return 0;
            case _VEC_DIM:
                printf("Error: invalid vector length\n");
                return 0;
            case _VEC_INPUT:
                printf("Error: not a number\n");
                return 0;
            default:
                printf("Error: unknown\n");
                return 0;
        }

    printf("\nv1+v2=v3\n");
    vec_print_vertically(&v3);
    //(e) use vec_print_to_compare to inspect whether the sum is correct
    vec_print_to_compare(&v1,&v2,&v3);
    
    

    return 0;
}

/*
//Task 3:
Answer 1: W językach C i C++ istnieje konstrukcja nazywana "include guard". 
Wykorzystana w pliku nagłówkowym instrukcja warunkowa ma na celu zapobieżenie sytuacji, 
w której wielokrotne "dołączenie" go za pomocą dyrektywy include (np. w kilku plikach źródłowych) spowoduje tylukrotne wklejenie zawartości.

Answer 2: Składowe programu są napisane poprawnie, jednak w żadnym z miejsc nie dochodzi do zdefiniowania funkcji, 
które deklaruje plik veccin.c oraz które są wykorzystywane w składowych. 
Ten błąd zostaje odkryty na etapie konsolidacji, wskutek czego linker nie jest uruchamiany, a plik wynikowy nie powstanie.
*/



