#include <stdio.h>
#include <stdlib.h>

void calculadora(){
    int v1,v2;
    char cara;
    printf("Digite o primeiro valor: ");
    scanf("%d",&v1);
    printf("Digite o segundo valor: ");
    scanf("%d",&v2);
    fflush(stdin);
    printf("\nInforme a operacao: \n + Somar \n - Subtrair \n / Dividir \n * Multiplicar\nEscolha:");
    scanf("%c",&cara);

    if (cara == '+'){

        printf("\nResultado: %d",v1 + v2);
    }else{
        if (cara == '-'){

            printf("\nResultado: %d \n\n\n",v1 - v2);
        }else{
            if(cara == '/'){

                printf("\nResultado: %d",v1 / v2);
            }else{
                printf("\nResultado: %d",v1 * v2);
            }
        }
    }
}

int main()

{

    calculadora();

    return 0;
}
