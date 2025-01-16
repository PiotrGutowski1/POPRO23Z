








#include "vecin.h"


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
    
    double dot_product=0.0;
    //(c) calculate dot product of v1 and v2 using functions defined in veccalc.h. Provide full error handling. 
    printf("\nv1 * v2 = %f\n",dot_product);


    //(d) calculate v3=v1+v2 using functions defined in veccalc.h. Provide full error handling. 
    printf("\nv1+v2=v3\n");
    //(e) use vec_print_to_compare to inspect whether the sum is correct
    
    

    return 0;
}


//Task 3:
//Answer 1:
//Answer 2:



