#include <stdio.h>
#include <math.h>

/**
 * POPRO - Lab 5 - Zadanie 1.
 * 
 * Zespół projektowy: Bartosz Bagiński, Krzysztof Dobosz, Piotr Gutowski.
 */

double triSide(double *x1,double *y1,double *x2, double *y2);
double triPeri(double *len1, double *len2, double *len3);
double triArea(double *a1, double *b1, double *a2, double *b2, double *a3, double *b3);

int main()
{
    double X1, X2, X3, Y1, Y2, Y3;

    X1 = 3;
    Y1 = 0;
    X2 = 6;
    Y2 = 0;
    X3 = 3;
    Y3 = 4;

    double x = triArea(&X1, &Y1, &X2, &Y2, &X3, &Y3);
    printf("Pole wynosi %.2lf", x);
}

double triSide(double *x1,double *y1,double *x2, double *y2)
{
    double lenX = fabs (*x2 - *x1);
    double lenY = fabs (*y2 - *y1);
    
    return sqrt( (lenX * lenX) + (lenY * lenY));
}

double triPeri(double *len1,double *len2, double *len3)
{
    return (*len1 + *len2 + *len3);
}

double triArea(double *a1, double *b1, double *a2, double *b2, double *a3, double *b3)
{
    double lenA = triSide(a1,b1,a2,b2);
    double lenB = triSide(a1,b1,a3,b3);
    double lenC = triSide(a2,b2,a3,b3);
    double periA = triPeri(&lenA,&lenB,&lenC); 
    double p = periA/2.0;
    double area = sqrt(p * (p - lenA) * (p - lenB) * (p - lenC));
    return area;
}