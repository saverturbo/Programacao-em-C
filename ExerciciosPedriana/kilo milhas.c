#include <stdio.h>
#include <stdlib.h>

int main()
{
    float premio, ganhador1, ganhador2, ganhador3;
    premio = 780000.00;
    printf("O primeiro premio foi de R$%.2f: \n",premio * 0.46);
    printf("O segundo premio foi de R$ %.2f: \n",premio * 0.32);
    printf("O terceiro premio de de R$ %.2f: ",premio * 0.22);

    return 0;
}

