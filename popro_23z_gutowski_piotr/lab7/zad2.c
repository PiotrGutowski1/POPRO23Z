//Lab. 7, zadanie 2
//
//Imię i nazwisko: Piotr Gutowski, Bartosz Bagiński
//Nr albumu 318472,331195
//Data 20.11.2023
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <stdint.h>

typedef struct my_ints
{
        uint8_t abyte;
        uint16_t aword;
        uint32_t anint;
        uint64_t alongestint;
}my_ints_t;
//1. Remove memory leakage from the program - linia 60 kodu
int main() {
    printf("\n\n\nSize of my_ints_t is %lu\n",(unsigned long)sizeof(my_ints_t));
    //2. Comment the result of the above command
    // Komenda zwraca wartość 16 czyli rozmiar struktury my_ints_t wyrazony w bajtach wynosi 16. 
    //suma elementow struktury daje 15, a dodatkowy bajt wynika z paddingu, ktory wyrownoje pola pamieci do swojego naturalnego wyrownania.
    //wystepuje on po uint8_t abyte, ktore jest 1 bajtowe, a jest wyrownywane by ulozenie w pamieci bylo naturalne (co wielokrotnosc 2) 
    my_ints_t *m=NULL;
    int howmany=-1;
    unsigned int tries=0;
    for(;;) //preferred infinite loop in C 
    {
                tries++;
                printf("Type a number of structs in the array or 0 to exit:\n");
                howmany=-1;
                if ((scanf("%d",&howmany)!=1)||(howmany<0))
                {
                        printf("Invalid input, try again!\n\n");
                        continue;
                }
                if (howmany==0) break;
                printf("Allocating %lu bytes\n",sizeof(my_ints_t)*howmany);
                m=(my_ints_t*)malloc(sizeof(my_ints_t)*howmany);
                if (m==NULL)
                {
                printf("Bad alloc!\n");
                break;
                }
                for (uint64_t ii=0;ii<howmany;ii++) m[ii].anint=tries;
    }
    if (m!=NULL)
    {
            printf("In all array elements an .aint filed is set to %u\n",m[0].anint);
    }
    char e=0;
    printf("Type 'e' to exit\n"); 
    for(;;)
    {
    scanf("%c",&e);
    if (e=='e') break;
    }
    return 0;
    free(m); //zadanie 1.
}
                    

