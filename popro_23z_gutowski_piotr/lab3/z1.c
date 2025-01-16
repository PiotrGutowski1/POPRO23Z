
#include <stdio.h>
int main(int argc, char** argv) {
    short daysInYear = 365;
    char x = (char) daysInYear;
    int someNumber = 555;
    short castSomeNumber = (short) someNumber; char letter = 'a' + 1;
    int value = 1 + (int) 'a';
    printf("%d\n", daysInYear);
    printf("%d\n", x);
    printf("%d\n", someNumber);
    printf("%d\n", castSomeNumber);
    printf("%d\n", letter);
    printf("%d\n", value);
    float firstFloat = 1.443543322f;
    int castFloat = (int) firstFloat;
    float first = 1.44f;
    float second = 4.33f;
    float additionResult = first + second;
    float division = first / second;
    float addBig = 55554889857.1f + 0.00000001f;
    float divideBig = 555414.0f / 0.0000000001f;
    printf("%.6f\n", firstFloat);
    printf("%.6f\n", castFloat); // castFloat jest typu int natomiast specyfikator formatu jest odpowiedni dla float'a
    printf("%.6f\n", first);
    printf("%.6f\n", second);
    printf("%.6f\n", additionResult);
    printf("%.6f\n", division);
    printf("%.6f\n", addBig);
    printf("%.6f\n", divideBig); // do oczekiwanej liczby dodaje 38037504
    return 0;
}
