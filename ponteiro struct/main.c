#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
        char nome [20];
        int idade;
}dados;

int main()
{
    int x=0;
    dados *point;


    point = (dados *) malloc(5 * sizeof(dados));

    do{
        fflush(stdin);
        printf("Nome:");
        gets(point[0].nome);
        strcpy(point[0].nome,strupr(point[0].nome));

        printf("Idade:");
        scanf("%d",&point[0].idade);
        x++;
        system("cls");

    }while(x<1);


    for(x=0; x<5; x++){
        printf("Nome: %s\n",point[x].nome);
        printf("Idade %d\n\n",point[x].idade);
    }

    return 0;
}
