#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char nome[31], sobrenome[31], nascimento[11];
    int idade;

    printf("Nome: ");
    gets(nome);

    printf("Sobrenome: ");
    gets(sobrenome);

    printf("Idade: ");
    scanf("%d", &idade);

    fflush(stdin);

    printf("Data de nascimento: ");
    gets(nascimento);

    printf("\nNome completo: %s %s\n", nome, sobrenome);
    printf("Idade: %d\n", idade);
    printf("Data de nascimento: "); puts(nascimento);

    return 0;
}
