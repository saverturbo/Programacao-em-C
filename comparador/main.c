#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int maior = -999999999;
    int menor = 999999999;
    int x, q ,n;
    char  melhor[31] ;
    char pior [31];
    char nome[31];
    printf("Quantos alunos nesta turma: ");
    scanf("%i", &q);
     for (x = 1; x <= q; x++)
     {
         printf("Digite o nome do aluno: ");
         scanf("%s",nome);
         printf("Digite a nota de %s: ",nome);
         scanf("%i",&n);
         if (n > maior) {
            maior = n;
            strcpy(melhor,nome);
         }
         if (n < menor){
            menor = n;
            strcpy(pior,nome);
         }
     }
        printf("O maior nota foi: %i do aluno: %s.\n",maior,melhor);
        printf("O menor nota foi: %i do aluno: %s.\n",menor,pior);
        printf("\n\n");





    return 0;
}
