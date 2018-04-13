#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b[2][6]={0,0,0,0,0};
    int t , car, carro;
    int menu, opcaolocar ,opcaoliberar, confirmar , confirmar2 ;

    int    locarveiculo(){
           printf("Deseja locar outro veiculo? \n\n");
            printf("1 = SIM , 2 = NAO.\n");
            printf("Opcao:");
            scanf("%d",&opcaolocar);
            system("cls");
           }
    int    liberarveiculo(){
           printf("Deseja liberar outro veiculo? \n\n");
            printf("1 = SIM , 2 = NAO.\n");
            printf("Opcao:");
            scanf("%d",&opcaoliberar);
            system("cls");
           }
           //SISTEMA DE LOCACAO DE VEICULOS LIVRES

do{
    printf("\n * MENU DE LOCACAO DE VEICULOS *\n   ---------------------------\n\n[1] LOCAR VEICULOS\n\n[2] LIBERAR VEICULOS\n\n[3] LISTAR LOCADOS\n\n[4] SAIR\n\n Opcao:");
    scanf("%d",&menu);
    system("cls");


    if(menu == 1){

                    do{
    printf("\n               * LOCAR VEICULOS *\n-----------------------------------------------------------\n");
    for (t=0; t<=4; t++){
      if (b[0][t] == 1){         //Teste condicional de exibição de veiculo disponivel ou locado
        printf(" [0%d LOCADO.] ",t+1);
      }  else
        printf(" [Carro 0%d] ",t+1);

    }
    printf("\n-----------------------------------------------------------\n");

    printf("\nDigite o numero do carro para loca-lo ou digite 0 para retornar:");
    scanf("%d",&car);
        carro = car - 1;

    if(car > 0){
        printf("Informe o codigo do cliente: ");
    scanf("%d",&b[1][carro]);

    printf("Confirma Locacao?\n[1] = SIM\n[2] = NAO\n\n OPCAO:");
     scanf("%d",&confirmar);


    if((confirmar == 1) && (b[0][carro] == 0)){           //Teste condicional para bloqueio de veiculo ja locado
        b[0][carro] = 1;

        printf("\n* Carro 0%d Locado para o cliente %d*\n\n",car,b[1][carro]);
        locarveiculo();




    }else{
         if( (confirmar == 1 )&&( b[0][carro] == 1 ) ){
            printf("\n* ERRO: Carro ja locado! *\n\n");
            locarveiculo();

                system("cls");
         }else{
            if((confirmar == 2)&& (b[0][carro]==0 || (b[0][carro]==1))){
               printf("\nLocacao do veiculo 0%d cancelada.\n", car);
                locarveiculo();
            }
         }

      }
    }else
        system("cls");




}while (opcaolocar != 2 && car != 0);


    }else{
        if(menu == 2){

              //SISTEMMA DE LIBERACAO DE VEICULOS RESERVADOS
do{
   printf("               * LIBERAR VEICULOS *\n-----------------------------------------------------------\n");
    for (t=0; t<=4; t++){
      if (b[0][t] == 1){         //Teste condicional de exibição de veiculo disponivel ou locado
        printf("[0%d LOCADO.] ",t+1);
      }  else
        printf(" [Carro 0%d] ",t+1);

    }
    printf("\n-----------------------------------------------------------\n");

    printf("\nDigite o numero do carro para libera-lo ou digite 0 para retornar: ");
    scanf("%d",&car);
        carro = car - 1;
    //printf("Informe o codigo do cliente: ");
    //scanf("%d",&b[1][carro]);

        if(car > 0){
            printf("Confirma Liberacao?\n[1] = SIM\n[2] = NAO\n\n OPCAO:");
     scanf("%d",&confirmar2);


    if((confirmar2 == 1) && (b[0][carro] == 1)){           //Teste condicional para bloqueio de veiculo ja locado
        b[0][carro] = 0;

        printf("\n* Carro 0%d Liberado com sucesso *\n\n",car);
        liberarveiculo();




    }else{
         if( (confirmar2 == 1 )&&( b[0][carro] == 0 ) ){
            printf("\n* ERRO: Carro ja liberado! *\n\n");
            liberarveiculo();

                system("cls");
         }else{
            if((confirmar2 == 2)&& (b[0][carro]==1 || (b[0][carro]==0))){
                printf("\nLiberacao do veiculo 0%d cancelada.\n", car);
                liberarveiculo();
            }
         }

    }
        }else

            system("cls");


}while(opcaoliberar != 2 && car != 0);

                        //SISTEMA DE EXIBICAO DE VEICULOS LIVRE E LOCADOS.

        }else{
            if(menu == 3 ){ //Testa se o veiculo esta livre (0) ou  locado (1)
                printf("\n * LISTAR STATUS DE VEICULOS *\n   -------------------------\n");
                for (t=0; t<=4; t++) {
                    if(b[0][t] ==1){
                        printf("CARRO 0%d LOCADO PARA O CLIENTE: %d\n\n", t+1,b[1][t]);
                    }else
                         printf("CARRO 0%d LIVRE. \n\n", t+1);

                }

            }


                        system("pause");
                        system("cls");
        }




    }

}while(menu != 4);


    return 0;

}
