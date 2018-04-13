#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mostracarros()
{
int i;
char b[6]={'d','d','d','d','d'};
    printf("--------------------\n");
    printf("Listagem de Carros\n");
    printf("--------------------\n");
    for (i=0; i<=4; i++){

      if (b[i] == 'd'){
        printf("[Carro %d] ",i+1);
      }  else
        printf("[---]");

    }
    return (0);
}



int main()
{
    char b[6]={'d','d','d','d','d'};
    int car;
    char op[2] ;

    do{
    system("cls");
    mostracarros();

    printf("\n\n");
    printf("Digite o numero do carro: \n");
    scanf("%d",&car);

    if( b[car] == 'd'){
        b[car] = '--';
        printf("Carro %d Reservado\n",car);
    }else
        printf("ERRO: Carro ja alugado!\n");
    printf("Deseja reservar outro veiculo? [S/N] ");
    scanf("%s",op);
}while((op != 'N') || (op!= 'n'));
    return 0;
}
