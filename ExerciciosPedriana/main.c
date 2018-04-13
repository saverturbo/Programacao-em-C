#include <stdio.h>
#include <stdlib.h>

int main()
{
    float miles, kilo;


    printf("Informe a distancia: ");
    scanf("%f",&miles);

    printf("Por favor aguarde...\n");

    kilo = miles * 1.6;

    printf("%.2f milhas equivale a %.2f Kilometros",kilo,miles);

    return 0;
}
