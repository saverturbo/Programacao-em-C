#include <stdio.h>
#include <stdlib.h>

int main()
{
   float  celcius, Kelv;
    printf("Por favor, iforme a temperatura em Celcuis: ");
    scanf("%f",&Kelv);
    celcius = Kelv - 273.15;


    printf("A temperatura %.2f equivale a %.2f em Kelvin " ,Kelv,celcius);



    return 0;
}
