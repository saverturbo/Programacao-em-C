#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[10];
    do{
        printf("Digite seu nome: ");
    gets(nome);

    if (strcmp(nome,"vanessa")== 0 || strcmp(nome,"Vanessa")==0){
        printf("Eu te amo!\n");
        printf("Volta pra mim\nPreciso muito de vc\nNao sei mais viver sem vc\n");
        system("pause");

    }else
        printf("Erro Fatal");

        system("cls");

    }while(strcmp(nome,"vanessa")!= 0);


    return 0;
}
