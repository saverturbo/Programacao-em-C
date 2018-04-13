#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x;
    char cont;
    float resultado = 0;
    float numero = 0;

    printf("******:ADIVINHA NUMERO:******");
    printf("\n\n");
    printf("PENSE EM UM NUMERO!\n\n");
    printf("Aperte ENTER para continuar");
    scanf("%c",&cont);
    printf("\n\n");
    printf("MULTIPLIQUE ESSE NUMERO POR 2...\n\n");
    printf("Aperte ENTER para continuar");
    scanf("%c",&cont);
    printf("\n\n");
    printf("ADICIONE 10 AO RESULTADO...\n\n");
    printf("Aperte ENTER para continuar");
    scanf("%c",&cont);
    printf("\n\n");
    printf("DIVIDA O RESULTADO POR 2...\n\n");
    printf("Aperte ENTER para continuar");
    scanf("%c",&cont);
    printf("\n\n");
    printf("DIGITE O RESULTADO OBTIDO: ");
    scanf("%f",&resultado);
    printf("\n\n");
    printf("PROCESSANDO");
    for (x = 1; x <=10; x++){
        printf(">");
    }
    printf(">\n\n");
    numero = resultado - 5;
    printf("\n\n");
    printf("O NUMERO QUE VOCE PENSOU FOI: %.0f\n\n",numero);
    printf("Aperte ENTER para SAIR...");
    scanf("%c",&cont);
    scanf("%c",&cont);

    return 0;
}
