#include <stdio.h>
#include <stdlib.h>

    int soma_digitos(){
            int numero, soma=0;

   printf("Digite o numero que deseja somar os algarismos:");
   scanf("%d",&numero);

   do{
        if(numero <= 100000 && numero >= 10000){
            soma = soma + (numero / 10000);
            numero = numero % 10000;
        }else{

                if(numero <= 10000 && numero >= 1000){
                    soma = soma + (numero / 1000);
                    numero = numero % 1000;
                }else{
                    if (numero <= 1000 && numero >= 100){
                        soma = soma + (numero / 100);
                        numero = numero % 100;

                    }else{
                        if(numero <= 100 && numero >= 10){

                            soma = soma + (numero / 10);
                            numero = numero % 10;
                        }else{
                            if(numero < 10 && numero > 0){
                                soma = soma + numero;
                                numero = 0;
                        }
                    }
                }
            }
        }
   }while(numero > 0);
            return (soma);
    }

int main()
{
    int soma;
    soma = soma_digitos();
   printf("\nA soma de todos os digitos e igual a:%d",soma);
    return 0;
}
