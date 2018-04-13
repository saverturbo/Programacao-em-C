#include <stdio.h>
#include <stdlib.h>

int main()
{
    int soma=0, numero;

    printf("Digite um numero:");
    scanf("%d",&numero);

    if(numero <= 100000 && numero >= 10000){
            soma = soma + (numero / 10000);
            numero = numero % 10000;
    }
    if(numero <= 10000 && numero >= 1000){
                    soma = soma + (numero / 1000);
                    numero = numero % 1000;
    }
    if (numero <= 1000 && numero >= 100){
                        soma = soma + (numero / 100);
                        numero = numero % 100;

    }
    if(numero <= 100 && numero >= 10){

                            soma = soma + (numero / 10);
                            numero = numero % 10;
    }
    if(numero < 10 && numero > 0){
                                soma = soma + numero;
                                numero = 0;
    }
    printf("Soma dos digitos deste numero:%d",soma);
        return 0;
}
