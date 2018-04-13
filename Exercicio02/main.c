#include <stdio.h>
#include <stdlib.h>

int main()
{
    float ms, km;
    printf("Digite a velocidade em Km/h:");
    scanf("%f",&km);

    ms = km/3.6;

    printf("%.2f Km/h equivale a %.2f m/s",km,ms);

    return 0;
}
