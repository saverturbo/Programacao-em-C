#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, option, top=0, pilha[5];
    do{
        system("cls");
        printf("Menu \n\n1-Inserir Numero\n2-Remover Numero\n3-Listar Numeros\n4-Sair\n\nOpcao:");
        scanf("%d",&option);

        switch (option){
            case 1:
                if(top <= 4){
                    printf("Digite um Numero:");
                scanf("%d",&pilha[top]);
                printf("Numero inserido com sucesso\n\n");
                top ++;
                system("pause");
                }else{
                    system("cls");
                    printf("ERRO - Pilha Cheia\n");
                    system("pause");
                }
                    break;

            case 2:

                printf("Ultimo numero removido: %d\n",pilha[top-1]);
                top = top - 1;
                system("pause");

                    break;

            case 3:
                if(top > 0){
                        system("cls");
                    printf("Pilha\n\n");
                    for(i=top-1; i>=0 ; i--){

                        printf("|%d|\n",pilha[i]);

                    }
                    system("pause");

                }else{
                    system("cls");
                    printf("Pilha Vazia\n");
                    system("pause");

                }
                break;
        }





    }while(option != 4);
    return 0;
}
