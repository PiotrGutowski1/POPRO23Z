
#include <stdio.h>
#define TABLE_SIZE 10
int main(int argc, char** argv) {
    char* names[TABLE_SIZE] =  {
    "Jan", "Piotr", "Michal", "Pawel", "Jakub", "Stefan", "Robert","Mariusz", "Tadeusz", "Konrad"
    };
    int times[TABLE_SIZE] = {
    56, 60, 51, 44, 66, 50, 49, 62, 43, 70
    };
    /*deklaracja i inicjalizacja dla wartosci tymczasowych najlepszego czasu i jego indeksu w tabeli times, uzywanych w petli for*/
    int best = times[0]; //inicjalizuje z wartoscia pierwszego elementu tabeli, dlatego potem w for zaczynam od i=1 dla indexu 1 czyli drugiego elemetnu 
    int best_number = 0;
    
    while (1) 
        {
        printf("Choose an option: 1 - calculate; 2 - exit program\n");
        int option;
        scanf("%d", &option);
        
        switch (option) 
            {
            case 1:
            /*petla for sprawdza przechodzi przez wszystkie elementy tabeli */   
            for (int i = 1; i < TABLE_SIZE; i++)
                {
                /*if sprawdza czy wartosc dla danej wartosci i jest nizsza niz obecnie najnizsza i ja ustawia jesli tak*/    
                if (times[i]<=best)
                    {
                    best = times[i];
                    best_number = i;
                    }
                }
            printf("Najlepszy czas (%d sekund(y)) uzyskał %s\n",times[best_number],names[best_number]);

            break;
            case 2:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Wrong option choose once again\n");
            
            } 
        
    
        }
    return 0; 
    }