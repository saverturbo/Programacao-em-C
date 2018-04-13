#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"

void menu (){
    system("cls");
    printf("\t\tMENU DE OPÇÕES\n\n\t\t1-INSERIR\n\t\t2-REMOVER\n\t\t3-LISTAR TODOS\n\t\t4-SAIR\n======================================\nOpção:");
    scanf("%d",&option);


}

void empilhar(){

    fflush(stdin);
    printf("Digite o nome:");
    gets(conta[top].nome);
    printf("Digite o telefone:");
    scanf("%d",&conta[top].telefone);
    fflush(stdin);
    printf("Digite o e-mail:");
    gets(conta[top].e_mail);
    top ++;
    system("pause");
}

void desempilhar(){

    printf("Contato: %s excluído!",conta[top-1].nome);
    top --;
    system("pause");
}

void listar_todos(){
    for (i=top-1; i>=0; i--){
        printf("|Nome: %s|\n",conta[i].nome);
        printf("|Telefone: %d|\n",conta[i].telefone);
        printf("|E-mail: %s|\n\n",conta[i].e_mail);
    }

    system("pause");
}
