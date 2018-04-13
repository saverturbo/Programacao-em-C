#include <stdio.h>
#include <stdlib.h>

int main()
{
    float desc, pag, prod;

    printf("Digite o valor do produto(R$): ");
    scanf("%f",&prod);
    printf("Digite o valor a pagar: ");
    scanf("%f",&pag);
    if (prod >= pag){


    prod = (pag * 100)/prod;
    desc = 100 - prod;


    printf("O valor do produto com desconto (R$): %.2f \n",pag);
    printf("O desconto foi de %.0f porcento\n",desc);

    }else{
        printf("Opercao invalida.");
    }




        return 0;
}
