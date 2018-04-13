#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    int idade;
}dados;



int main(){
    int *ponteiro;
    int x,tamanho=0;
    char r;
    do{
        ponteiro = (int *) realloc(ponteiro,sizeof(int));
        fflush(stdin);
        printf("Numero:");

        scanf(" %d",&ponteiro);

    printf("Add outro [S/N]:");
    fflush(stdin);
    scanf("%c",&r);
    if(r == 's')
        tamanho ++;

    }while(r != 'n');

    for(x=0; x<tamanho;x++)
        printf("%d",ponteiro[x]);
    return 0;
}
