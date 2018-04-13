#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "bibliotecas/fdb.inc"

/* Definições */
#define MAX_CLIENTES 20
#define MAX_VEICULOS 50

/* Structs */
struct cliente_struct {
    char nome[50], end[100], email[50], cpf[12], hab[12];
    int idade, cadastrado;
};

struct veiculo_struct {
    char nome[40],modelo[15],cor[10], cliente_cpf[12];
    int val,num,cadastrado,locado,cliente_locado,dias,dm[2];
};

struct cliente_struct cliente[MAX_CLIENTES];
struct veiculo_struct veiculo[MAX_VEICULOS];

/* Funções */
int opcaolocar, opcaoliberar;
int locarveiculo();
int liberarveiculo();

carregar_clientes();
carregar_veiculos();
salvar_cliente(int indice);
salvar_veiculo(int indice);
salvar_locacao(int indice);
remover_cliente(int indice);
remover_veiculo(int indice);
remover_locacao(int indice);

/* Variáveis globais */
int TOTAL_CLIENTES_CADASTRADOS = 0;
int TOTAL_VEICULOS_CADASTRADOS = 0;
int TOTAL_VEICULOS_LOCADOS = 0;

/*============================================*/

int main() {
    setlocale(LC_ALL,"portuguese");

    /* Variáveis */

    int i=0,ml,ex=0,op=0,num,comp=0;
    char menu,mode[10],letra,mv=0,mv2=0,mv3=0,most[5],mp,bsc=0,mc,log[3],sen[3],nu[05], cpf_s[12];
    int t;
    int confirmar, confirmar2;
    int j = 0;

    carregar_clientes();
    carregar_veiculos();

    do { // Menu
        system("cls");
        printf("=========================================================\n");
        printf("|                   =====LOCAR =====        		|	\n");
        printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
        printf("|                    MENU DE OPÇÕES         		|	\n");
        printf("|                   	       			        |	\n");
        printf("=========================================================\n");
        printf("		    | -1- CLIENTE   |\n");
        printf("		    | -2- VEÍCULO   |\n");
        printf("		    | -3- LOCAÇÃO   |\n");
        printf("		    | -4- SAIR      |");
        printf("\nOPÇÃO: ");
        scanf(" %c",&mp);

        switch(mp){
            case '1': // Menu - clientes
                do{
                    system("cls");
                    printf("=========================================================\n");
                    printf("|                   =====LOCAR =====        		|	\n");
                    printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                    printf("|             MENU DE CADASTRO DE CLIENTES  		|	\n");
                    printf("|               CLIENTES CADASTRADOS: %02d                |	\n", TOTAL_CLIENTES_CADASTRADOS);
                    printf("=========================================================\n");
                    printf("		    |-0- BUSCAR   |\n");
                    printf("		    |-1- INSERIR  |\n");
                    printf("		    |-2- ATUALIZAR|\n");
                    printf("		    |-3- REMOVER  |\n");
                    printf("		    |-4- VOLTAR   |");
                    printf("\nOPÇÃO: ");
                    mc=0;
                    setbuf(stdin,NULL);
                    scanf(" %c",&mc);
                    switch(mc){

                        case '0': // Menu - buscar clientes
                            do { // Menu - buscar clientes
                                system("cls");
                                printf("=========================================================\n");
                                printf("|                   =====LOCAR =====        		|	\n");
                                printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                                printf("|             MENU DE CADASTRO DE CLIENTES  		|	\n");
                                printf("|                   	       			        |	\n");
                                printf("=========================================================\n");
                                printf("\n");
                                printf("DIGITE O CPF DO CLIENTE: ");
                                scanf(" %s", cpf_s);

                                // Laço que verifica se o cpf de um cliente é igual ao que digitou
                                for(i=0;i<MAX_CLIENTES;i++){
                                    if(strcmp(cpf_s, cliente[i].cpf) == 0) {
                                        system("cls");
                                        printf("=========================================================\n");
                                        printf("|                   =====LOCAR =====        		|	\n");
                                        printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                                        printf("|             MENU DE CADASTRO DE CLIENTES  		|	\n");
                                        printf("|                   	       			        |	\n");
                                        printf("=========================================================\n");
                                        printf("\n");
                                        printf(" CADASTRO LOCALIZADO\n\n");
                                        printf(" NOME: %s\n",cliente[i].nome);
                                        printf(" ENDEREÇO: %s \n",cliente[i].end);
                                        printf(" E-MAIL: %s \n",cliente[i].email);
                                        printf(" IDADE: %d anos\n", cliente[i].idade);
                                        printf(" CPF: %s \n",cliente[i].cpf);
                                        printf(" CNH: %s \n",cliente[i].hab);
                                        bsc=1;
                                        break;
                                    }

                                }

                                if(bsc==0) {
                                    system("cls");
                                    printf("=========================================================\n");
                                    printf("|                   =====LOCAR =====        		|	\n");
                                    printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                                    printf("|             MENU DE CADASTRO DE CLIENTES  		|	\n");
                                    printf("|                   	       			        |	\n");
                                    printf("=========================================================\n");
                                    printf("\nCLIENTE NÃO ESTÁ CADASTRADO\n\n\n");
                                }

                                printf("\n DESEJA BUSCAR OUTRO CLIENTE\n");
                                printf("      SIM (1) OU NÃO (2) \n");

                                bsc=0;
                                scanf(" %c",&mc);
                            } while(mc!='2'); // Menu - buscar clientes

                            break;
                        case '1':	// Menu - inserir cliente
                            bsc = 0;

                            // Laço que encontra um index livre para inserir os dados do cliente.
                            for(i = 0; i < MAX_CLIENTES; i ++) {
                                if(cliente[i].cadastrado == 0) {
                                    ex = i;
                                    break;
                                }
                            }

                            printf("\nDIGITE SEU NOME: ");
                            fflush(stdin);
                            gets(cliente[ex].nome);
                            printf("\n");
                            printf("DIGITE SEU ENDEREÇO: ");
                            gets(cliente[ex].end);
                            printf("\n");
                            printf("DIGITE SEU E-MAIL: ");
                            gets(cliente[ex].email);
                            printf("\n");
                            printf("DIGITE SUA IDADE: ");
                            fflush(stdin);
                            scanf("%d",&cliente[ex].idade);
                            printf("\n");
                            printf("DIGITE O NÚMERO DO SEU CPF: ");
                            fflush(stdin);
                            gets(cliente[ex].cpf);
                            printf("\n");
                            printf("DIGITE O NÚMERO DA SUA CNH: ");
                            fflush(stdin);
                            gets(cliente[ex].hab);

                            // Laço que verifica se há algum cliente cadastrado com o cpf informado acima
                            for(i = 0; i < MAX_CLIENTES; i ++) {
                                if(strcmp(cliente[i].cpf, cliente[ex].cpf) == 0 && cliente[i].cadastrado == 1) {
                                    bsc = 1;
                                    break;
                                }
                            }

                            if(bsc == 1) {
                                printf("\nCLIENTE JÁ CADASTRADO COM ESTE CPF.\n");
                            } else {
                                printf("\n");
                                printf("CLIENTE SALVO COM SUCESSO!\n");
                                cliente[ex].cadastrado = 1;
                                TOTAL_CLIENTES_CADASTRADOS ++;
                                salvar_cliente(ex);
                            }

                            printf("\n");
                            system("pause");
                            break;

                        case '2': // Menu - atualizar dados do cliente
                            bsc=0;
                            printf("DIGITE O CPF DO CLIENTE QUE DESEJA ATUALIZAR O CADASTRO: ");
                            scanf(" %s", cpf_s);

                            // Laço que verifica se o CPF informado está cadastrado
                            for(i=0;i<MAX_CLIENTES;i++){
                                if(strcmp(cpf_s, cliente[i].cpf) == 0) {
                                    struct cliente_struct cliente_atualizacao;
                                    system("cls");
                                    printf("=========================================================\n");
                                    printf("|                   =====LOCAR =====        		|	\n");
                                    printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                                    printf("|             MENU DE CADASTRO DE CLIENTES  		|	\n");
                                    printf("|                   	       			        |	\n");
                                    printf("=========================================================\n");
                                    printf("\n");
                                    printf("O CLIENTE  ESTÁ CADASTRADO\n\n");

                                    printf(" NOME: %s\n",cliente[i].nome);
                                    printf(" ENDEREÇO: %s \n",cliente[i].end);
                                    printf(" E-MAIL: %s \n",cliente[i].email);
                                    printf(" IDADE: %i anos\n",cliente[i].idade);
                                    printf(" CPF: %s \n",cliente[i].cpf);
                                    printf(" CNH: %s \n",cliente[i].hab);
                                    printf("\n");

                                    printf("DIGITE OS DADOS NOVAMENTE (use 0 para manter o mesmo):\n");
                                    printf("\n");

                                    printf("DIGITE SEU NOME: ");
                                    fflush(stdin);
                                    //gets(cliente[i].nome);
                                    gets(cliente_atualizacao.nome);
                                    if(strcmp(cliente_atualizacao.nome, "0") != 0) {
                                        strcpy(cliente[i].nome, cliente_atualizacao.nome);
                                    }

                                    printf("\n");
                                    printf("DIGITE O SEU ENDEREÇO: ");
                                    //gets(cliente[i].end);
                                    gets(cliente_atualizacao.end);
                                    if(strcmp(cliente_atualizacao.end, "0") != 0) {
                                        strcpy(cliente[i].end, cliente_atualizacao.end);
                                    }

                                    printf("\n");
                                    printf("DIGITE O SEU E-MAIL: ");
                                    //gets(cliente[i].email);
                                    gets(cliente_atualizacao.email);
                                    if(strcmp(cliente_atualizacao.email, "0") != 0) {
                                        strcpy(cliente[i].email, cliente_atualizacao.email);
                                    }

                                    printf("\n");
                                    printf("DIGITE SUA IDADE: ");
                                    fflush(stdin);
                                    scanf(" %i", &cliente_atualizacao.idade);
                                    if(cliente_atualizacao.idade != 0) {
                                        cliente[i].idade = cliente_atualizacao.idade;
                                    }

                                    printf("\n");
                                    printf("DIGITE O NUMERO DO SEU CPF: ");
                                    fflush(stdin);
                                    gets(cliente_atualizacao.cpf);
                                    if(strcmp(cliente_atualizacao.cpf, "0") != 0) {
                                        strcpy(cliente[i].cpf, cliente_atualizacao.cpf);
                                    }

                                    printf("\n");
                                    printf("DIGITE O NÚMERO DA SUA CNH: ");
                                    gets(cliente_atualizacao.hab);
                                    if(strcmp(cliente_atualizacao.hab, "0") != 0) {
                                        strcpy(cliente[i].cpf, cliente_atualizacao.cpf);
                                    }

                                    printf("\n");
                                    printf("CADASTRO ATUALIZADO!\n");

                                    salvar_cliente(i);

                                    bsc=1;
                                    break;
                                }


                            }
                            if(bsc==0){

                                printf("\n");
                                printf("CLIENTE NÃO CADASTRADO!\n");
                            }

                            printf("\n");
                            system("pause");

                            break;

                    case '3': // Menu - exclusão do cliente
                    comp=0;
                    printf(" DIGITE O CPF DO CLIENTE QUE DESEJA EXCLUIR: ");
                    scanf(" %s", cpf_s);

                    for(i=0;i<=30;i++){
                        if(strcmp(cpf_s, cliente[i].cpf) == 0){
                            printf("\n");
                            printf("O CLIENTE  ESTÁ CADASTRADO \n");
                            printf("\n");
                            printf(" NOME: %s\n",cliente[i].nome);
                            printf(" ENDEREÇO: %s \n",cliente[i].end);
                            printf(" E-MAIL: %s \n",cliente[i].email);
                            printf(" IDADE: %i anos\n",cliente[i].idade);
                            printf(" CPF: %s \n",cliente[i].cpf);
                            printf(" CNH: %s \n",cliente[i].hab);
                            printf("\n");
                            ex=i;

                            printf("TEM CERTEZA MESMO DA EXCLUSÃO? \n");
                            printf("    SIM (1) OU NÃO (2)\n");
                            mc=0;
                            scanf(" %c",&mc);
                            system("cls");
                            //system("pause");
                            comp=1;
                        }
                    }
                    if(comp==0){
                        printf("\n");
                        printf("CLIENTE NÃO ENCONTRADO!\n");
                        printf("\n");
                        system("pause");
                    }

                    if(mc=='1' && comp==1){
                        cliente[ex].cadastrado = 0;
                        remover_cliente(ex);
                        TOTAL_CLIENTES_CADASTRADOS --;
                        printf("CADASTRO EXCLUIDO COM SUCESSO!\n");
                        system("pause");
                    }
                    break;

                }//fim do switch clt

                printf("\n\n\n");
            }while(mc!='4');//menu cliente
            break;

            case '2'://veiculo
            system("cls");
            do{


                printf("=========================================================\n");
                printf("|                   =====LOCAR =====        		|	\n");
                printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                printf("|             MENU DE CADASTRO DE VEÍCULOS  		|	\n");
                printf("|               VEÍCULOS CADASTRADOS: %02d                |	\n", TOTAL_VEICULOS_CADASTRADOS);
                printf("=========================================================\n");
                printf("		    |-0- BUSCAR   |\n");
                printf("		    |-1- INSERIR  |\n");
                printf("		    |-2- ATUALIZAR|\n");
                printf("		    |-3- VOLTAR   |");
                printf("\nOPÇÃO:");
                scanf(" %c",&mv);






                fflush(stdin);
                system("cls");
                switch(mv){

                    case '0'://BUSCA DE VEÍCULOS CADASTRADO

                    do{
                        comp=0;
                        printf("=========================================================\n");
                        printf("|                   =====LOCAR =====        		|	\n");
                        printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                        printf("|               MENU DE BUSCA DE VEÍCULOS  		|	\n");
                        printf("|                   	       			        |	\n");
                        printf("=========================================================\n");


                        printf("INFORME O NUMERO DO VEICULO:\n");
                        scanf("%i",&num);
                        printf("\n");
                        fflush(stdin);
                        for(i=0;i<20;i++){
                            if(num > 0) {
	                            if(num==veiculo[i].num){
	                                printf("CADASTRO DO VEICULO \n");
	                                printf("\n");
	                                printf("NOME:  %s \n",veiculo[i].nome);
	                                printf("MOD : %s \n",veiculo[i].modelo);
	                                printf("COR  : %s \n",veiculo[i].cor);
	                                printf("VALOR:  R$ %i\n",veiculo[i].val);

	                                comp=1;
	                                break;


	                            }
	                        }
                        }
                        if(comp==0){
                            printf("CADASTRO NÃO ENCONTRADO!\n ");
                        }


                        printf("\n");
                        printf("DESEJA FAZER UMA NOVA BUSCA?\n");
                        printf("    SIM: 1 ou NÃO: 2\n");
                        scanf("%d",&op);
                        system("cls");


                        fflush(stdin);
                    }while(op!=2);
                    system("cls");
                    break;

                    case '1':   //CADASTRO
                    bsc = 0;
                    printf("=========================================================\n");
                    printf("|                   =====LOCAR =====        		|	\n");
                    printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                    printf("|             MENU DE CADASTRO DE VEÍCULOS  		|	\n");
                    printf("|                   	       			        |	\n");
                    printf("=========================================================\n");

                    for(i = 0; i < MAX_VEICULOS; i ++) {
                        if(veiculo[i].num == 0) {
                            ex = i;
                            break;
                        }
                    }

                    printf("INSIRA O NOME DO VEÍCULO: ");
                    gets(veiculo[ex].nome);
                    printf("\n");
                    printf("INSIRA O MODELO DO VEÍCULO: ");
                    scanf(" %s",veiculo[ex].modelo);
                    printf("\n");
                    printf("INSIRA  A  COR  DO VEÍCULO: ");
                    //scanf(" %s",veiculo[cad1].cor);
                    scanf(" %s",veiculo[ex].cor);
                    printf("\n");
                    printf("INSIRA O VALOR DE LOCAÇÃO: ");
                    //scanf(" %i",&veiculo[cad1].val);
                    scanf(" %i",&veiculo[ex].val);
                    printf("\n");
                    printf("INSIRA O NUMERO DO VEÍCULO: ");
                    //scanf(" %d",&veiculo[cad1].num);
                    scanf(" %d",&veiculo[ex].num);

                    printf("\n");

                    // Laço que verifica se há algum veículo com o número informado no cadastro
                    for(i = 0; i < MAX_VEICULOS; i ++) {
                        if(veiculo[i].num == veiculo[ex].num && veiculo[i].cadastrado == 1) {
                            bsc = 1;
                            break;
                        }
                    }

                    if(bsc == 1) {
                        printf("* JÁ EXISTE UM VEÍCULO COM ESTE NÚMERO *\n");
                    } else {
                        printf("* VEÍCULO CADASTRADO COM SUCESSO *\n");
                        veiculo[ex].cadastrado = 1;
                        salvar_veiculo(ex);
                        TOTAL_VEICULOS_CADASTRADOS ++;
                    }

                    printf("\n");
                    system("pause");
                    system("cls");
                    break;

                    case '2': //ATUALIZAR DADOS

                    do{

                        printf("=========================================================\n");
                        printf("|                   =====LOCAR =====        		|	\n");
                        printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                        printf("| 	       ATUALIZAR DADOS DE VEÍCULOS	       	|	\n");
                        printf("|                   	       			        |	\n");
                        printf("=========================================================\n");
                        printf("		    |-1- ATUALIZAR|\n");
                        printf("		    |-2- REMOVER  |\n");
                        printf("		    |-3- VOLTAR   |");
                        printf("\nOPÇÃO:");
                        scanf(" %c",&mv2);

                        system("cls");
                        switch(mv2){

                            case '1':
                            do{
                                comp = 0;
                                printf("=========================================================\n");
                                printf("|                   =====LOCAR =====        		|	\n");
                                printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                                printf("| 	       				      	 	|	\n");
                                printf("|                   	       			        |	\n");
                                printf("=========================================================\n");

                                printf("INFORME O NUMERO DO VEICULO:");
                                scanf(" %d", &num);
                                printf("\n");
                                for(i=0;i<20;i++){
                                    if(num==veiculo[i].num){
                                        printf("CADASTRO DO VEICULO \n");
                                        printf("\n");
                                        printf("Nome:  %s \n",veiculo[i].nome);
                                        printf("Mode : %s \n",veiculo[i].modelo);
                                        printf("Cor  : %s \n",veiculo[i].cor);
                                        printf("Valor:  R$ %i\n",veiculo[i].val);
                                        ex = i;
                                        comp = 1;
                                        break;
                                    }
                                }

                                printf("\n");

                                if(comp == 1) {
                                    if(veiculo[ex].locado == 1) {
                                        printf("VEÍCULO LOCADO! LIBERE-O PARA ATUALIZAR!\n");
                                    } else {
                                        printf("INSIRA O NOVO VALOR DE LOCAÇÃO DO VEÍCULO:");
                                        scanf(" %d",&veiculo[ex].val);
                                        printf("\n");
                                        printf("VALOR SALVO COM SUCESSO!\n");
                                        printf("\n");
                                        salvar_veiculo(ex);

                                        printf("Nome:  %s \n",veiculo[ex].nome);
                                        printf("Mode : %s \n",veiculo[ex].modelo);
                                        printf("Cor  : %s \n",veiculo[ex].cor);
                                        printf("Valor:  R$ %i\n",veiculo[ex].val);

                                        printf("\n");
                                    }
                                } else {
                                    printf("VEÍCULO NÃO ENCONTRADO.\n\n");
                                }

                                printf("DESEJA ATUALIZAR DADOS DE OUTRO VEÍCULO?\n");
                                printf("        SIM (1) OU NÃO (2)\n");
                                scanf(" %c",&mv2);


                                system("cls");

                            }while(mv2!='2');
                            break;

                            case '2':  //EXCLUSÃO DADOS CADASTRAIS DE VEÍCULOS
                            do{
                                comp=0;
                                printf("=========================================================\n");
                                printf("|                   =====LOCAR =====        		|	\n");
                                printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                                printf("| 	       				      	 	|	\n");
                                printf("|                   	       			        |	\n");
                                printf("=========================================================\n");

                                printf("INFORME O NUMERO DO VEICULO:");
                                scanf("%d",&num);
                                printf("\n");

                                for(i=0;i<20;i++){

                                    if(num==veiculo[i].num){
                                        ex=i;
                                        comp = 1;
                                        printf("CADASTRO DO VEICULO \n");
                                        printf("\n");
                                        printf("Nome:  %s \n",veiculo[i].nome);
                                        printf("Mode : %s \n",veiculo[i].modelo);
                                        printf("Cor  : %s \n",veiculo[i].cor);
                                        printf("Valor:  R$ %i\n",veiculo[i].val);
                                        break;
                                    }
                                }

                                if(comp == 0) {
                                    printf("\nVEÍCULO NÃO ENCONTRADO.\n\n");

                                    printf("\n");
                                    printf("PARA FAZER UMA NOVA BUSCA (1)\n");
                                    printf("PARA VOLTAR (2)\n");
                                    scanf(" %c",&mv3);
                                    if(mv3=='2'){
                                        mv3='3';
                                    }
                                    printf("\n");

                                } else {
                                    printf("\n");
                                    printf("DESEJA REALMENTE EXCLUIR OS DADOS DESTE VEÍCULO?\n");
                                    printf("\n");
                                    printf("PARA EXCLUIR (1)\n");
                                    printf("PARA FAZER UMA NOVA BUSCA (2)\n");
                                    printf("PARA VOLTAR (3)\n");

                                    scanf(" %c",&mv3);
                                    printf("\n");

                                    if(mv3=='1'){

                                            if(veiculo[ex].locado == 1) {
                                                printf("VEÍCULO ESTÁ LOCADO! LIBERE-O PARA REMOVER!\n");
                                            } else {
                                                strcpy(veiculo[ex].nome,"");
                                                strcpy(veiculo[ex].modelo,"");
                                                strcpy(veiculo[ex].cor,"");
                                                veiculo[ex].val=0;
                                                veiculo[ex].num=0;
                                                veiculo[ex].cadastrado = 0;

                                                remover_veiculo(ex);

                                                TOTAL_VEICULOS_CADASTRADOS --;

                                                printf("DADOS DO VEÍCULO EXCLUIDO COM SUCESSO!\n");
                                            }
                                        printf("\n");
                                        system("pause");
                                    }
                                    printf("\n\n");

                                }

                                if( mv=='2' ){

                                    system("cls");
                                }

                            }while( mv3!='3' );
                            system("cls");
                        }

                        system("cls");
                    }while(mv2!='3');

                }
            }while(mv!='3');



            break;//veiculo
            case '3'://locação
            system("cls");
            do{
                printf("=========================================================\n");
                printf("|                   =====LOCAR =====        		|	\n");
                printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                printf("|              MENU LOCAÇÃO DE VEÍCULO			|	\n");
                printf("|               VEÍCULOS LOCADOS: %02d  	                |\n", TOTAL_VEICULOS_LOCADOS);
                printf("=========================================================\n");
                printf("		    |-1- LOCAR VEICULOS  |\n");
                printf("		    |-2- LIBERAR VEICULOS|\n");
                printf("		    |-3- LISTAR LOCADOS  |\n");
                printf("		    |-4- VOLTAR          |");
                printf("\nOPÇÃO:");
                scanf(" %c",&menu);
                system("cls");


                if(menu == '1'){

                    do{
                    	comp = 0;
                        printf("=========================================================\n");
                        printf("|                   =====LOCAR =====        		|	\n");
                        printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                        printf("|              	 LOCAR VEICULOS				|	\n");
                        printf("|                   	       			        |	\n");
                        printf("=========================================================\n");
                        for(i = 0; i < MAX_VEICULOS; i ++) {
                            if(veiculo[i].cadastrado == 1) {
                                printf("\n		    |- %02d - %s", veiculo[i].num, veiculo[i].nome);
                            }
                        }

                        printf("\n");
                        printf("\nDIGITE O NÚMERO DO CARRO PARA LOCA-LO: ");
                        scanf(" %d",&num);

                        for(i = 0; i < MAX_VEICULOS; i ++) {
                            if(veiculo[i].num == num) {
                                if(veiculo[i].locado == 1) {
                                    comp = 1;
                                }
                                num = i;
                                break;
                            }
                        }

                        if(comp == 1) {
                        	printf("\n* ERRO: CARRO JÁ LOCADO! *\n\n");
				            locarveiculo();
                        } else {
				            if(veiculo[num].cadastrado == 1) {
    	                        printf("\n\nCADASTRO DO VEICULO\n\n");
    	                        printf("Nome:  %s \n",veiculo[num].nome);
                                printf("Mode : %s \n",veiculo[num].modelo);
                                printf("Cor  : %s \n",veiculo[num].cor);
                                printf("Valor:  R$ %i\n",veiculo[num].val);

    	                        printf("\n");
    	                        printf("DIGITE O CPF DO CLIENTE: ");
    	                        scanf(" %s", cpf_s);

    	                        for(i=0;i<=30;i++){
    	                            if(strcmp(cpf_s, cliente[i].cpf) == 0 && cliente[i].cadastrado == 1) {
    	                                ex=i;
    	                                comp = 1;
    	                                printf("\n");
    	                                printf(" NOME: %s\n",cliente[i].nome);
    	                                printf(" ENDEREÇO: %s \n",cliente[i].end);
    	                                printf(" E-MAIL: %s \n",cliente[i].email);
    	                                printf(" IDADE: %i anos\n",cliente[i].idade);
    	                                printf(" CPF: %s \n",cliente[i].cpf);
    	                                printf(" CNH: %s \n",cliente[i].hab);
                                        break;
    	                            }
    	                        }

    	                        if(comp == 0) {
    	                        	printf("\n* ERRO: CLIENTE NÃO EXISTE. *\n\n");
    	                        	locarveiculo();
    	                        } else {
                                    printf("\n");
                                    printf("INFORME A QUANTIDADE DE DIAS:");
                                    scanf(" %d",&veiculo[num].dias);

                                    printf("VALOR A SER PAGO: %d\n",veiculo[num].dias*veiculo[num].val);

                					printf("\n");
    		                        printf("CONFIRMAR LOCAÇÃO?\n");
    		                        printf("SIM (1)    NÃO (2)\nOPÇÃO:");
    		                        scanf("%d",&confirmar);


    		                        if(confirmar == 1) {
                                        //sprintf(veiculo[num].cliente_cpf, "%s", cpf_s);
                                        strcpy(veiculo[num].cliente_cpf, cpf_s);
    		                        	veiculo[num].locado = 1;

                                        salvar_locacao(num);

                                        TOTAL_VEICULOS_LOCADOS ++;

                                        time_t t = time(NULL);
                                        struct tm tm = *localtime(&t);

                                		veiculo[num].dm[0] = tm.tm_mday;
                                		veiculo[num].dm[1] = tm.tm_mon + 1;

                					    printf("\n* CARRO FOI LOCADO PARA: %s (CPF: %s)*\n\n", cliente[ex].nome, cpf_s);
                                        locarveiculo();
    		                        } else {
    		                        	locarveiculo();
    		                        }
                            	}
	                        } else {
    	                    	printf("\n");
    				            printf("VEÍCULO NÃO CADASTRADO!\n\n");
    				            locarveiculo();
                            }
                        }
                    } while (opcaolocar != 2);

                }else{
                    if(menu == '2'){

                        //SISTEMMA DE LIBERACAO DE VEICULOS RESERVADOS
                        do{
                            printf("=========================================================\n");
                            printf("|                   =====LOCAR =====        		|	\n");
                            printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                            printf("|              	 LIBERAR VEICULOS			|	\n");
                            printf("|                   	       			        |	\n");
                            printf("=========================================================\n");

                            for(i = 0; i < MAX_VEICULOS; i ++) {
                                if(veiculo[i].cadastrado == 1) {
                                    printf("\n		    |- %02d - %s", veiculo[i].num, veiculo[i].nome);
                                }
                            }

                            printf("\n");
                            printf("\nDIGITE O NÚMERO do CARRO PARA LIBERA-LO: ");
                            scanf(" %d",&num);

                            // Laço para pegar o índice do veículo onde o número do veículo está
                            for(i = 0; i < MAX_VEICULOS; i ++) {
                                if(veiculo[i].num == num && veiculo[i].cadastrado == 1) {
                                    num = i;
                                    break;
                                }
                            }

                            if(veiculo[num].cadastrado == 1) {
                            	if(veiculo[num].locado == 1) {
	                                printf("CADASTRO DO VEICULO \n");
	                                printf("\n");
	                                printf("Nome:  %s \n",veiculo[num].nome);
	                                printf("Mode : %s \n",veiculo[num].modelo);
	                                printf("Cor  : %s \n",veiculo[num].cor);
	                                printf("Valor:  R$ %i\n\n",veiculo[num].val);

	                                printf("CONFIRMAR LIBERAÇÃO?\n ");
		                            printf("SIM (1) OU NÃO (2)\n OPÇÃO");
		                            scanf("%d",&confirmar2);

		                            if(confirmar2 == 1) {
		                            	printf("\n* CARRO %02d LIBERADO COM SUCESSO \n\n", num+1);
										veiculo[num].locado = 0;
                                        remover_locacao(num);
                                        TOTAL_VEICULOS_LOCADOS --;
	                                	liberarveiculo();
		                            } else {
		                            	liberarveiculo();
		                            }
		                        } else {
		                        	printf("\n* ERRO: CARRO JÁ LIBERADO! *\n\n");
		                        	liberarveiculo();
		                        }
                            } else {
                            	printf("\n* ERRO: CARRO NÃO EXISTE! *\n\n");
                            	liberarveiculo();
                            }


                            system("cls");
                        }while(opcaoliberar != 2);

                        //SISTEMA DE EXIBICAO DE VEICULOS LIVRE E LOCADOS.

                    }else{
                        if(menu == '3' ) {

                            printf("=========================================================\n");
                            printf("|                   =====LOCAR =====        		|	\n");
                            printf("|           * LOCADORA DE CARRO MARANHENSE *  		|	\n");
                            printf("|              	 LISTAR VEICULOS			|	\n");
                            printf("|                   	       			        |	\n");
                            printf("=========================================================\n");

                            for(i = 0; i < MAX_VEICULOS; i ++) {
                                if(veiculo[i].cadastrado == 1) {
                                    if(veiculo[i].locado == 0) {
                                        printf("\n|- %d - %s | LIVRE\n", veiculo[i].num, veiculo[i].nome);
                                    } else {
                                        // Laço para pegar o nome do cliente pelo CPF

                                        for(j = 0; j < MAX_CLIENTES; j ++) {
                                            if(strcmp(cliente[j].cpf, veiculo[i].cliente_cpf) == 0) {
                                                printf("\n|- %d - %s | LOCADO \n CLIENTE: %s (CPF: %s) (DIA: %02d/%02d) (Q.DIAS: %d)\n", veiculo[i].num, veiculo[i].nome, cliente[j].nome, veiculo[i].cliente_cpf, veiculo[i].dm[0], veiculo[i].dm[1], veiculo[i].dias);
                                                break;
                                            }
                                        }
                                    }
                                }
                            }

                            printf("\n\n");

                            system("pause");
                        }



                        system("cls");
                    }

                }

            }while(menu != '4');

            break;//locação
            case '4':


            break;//nenhuma das opções

        }//switchMP

    }while(mp!='4');//MP

    salvar_clientes();
    salvar_veiculos();

    return 0;

}

int locarveiculo(){
    printf("DESEJA LOCAR OUTRO VEÍCULO? \n\n");
    printf("1 = SIM , 2 = NAO.\n");
    printf("Opcao:");
    scanf(" %d",&opcaolocar);
    system("cls");
}
int liberarveiculo(){
    printf("DESEJA LIBERAR OUTRO VEÍCULO? \n\n");
    printf("1 = SIM , 2 = NAO.\n");
    printf("Opcao:");
    scanf(" %d",&opcaoliberar);
    system("cls");
}

carregar_clientes() {
    int k;
    char *string = (char*) malloc(500);

    for(k = 0; k <= MAX_CLIENTES; k ++) {
        string[0] = '\0';
        sprintf(string, "clientes/%d.txt", k);
        if(fdb_open(string)) {
            sprintf(cliente[k].nome, "%s", fdb_GetString("Nome"));
            sprintf(cliente[k].end, "%s", fdb_GetString("Endereco"));
            sprintf(cliente[k].email, "%s", fdb_GetString("Email"));
            sprintf(cliente[k].cpf, "%s", fdb_GetString("CPF"));
            cliente[k].idade = fdb_GetInt("Idade");
            sprintf(cliente[k].hab, "%s", fdb_GetString("Habilitacao"));
            cliente[k].cadastrado = 1;
            fdb_close();
            TOTAL_CLIENTES_CADASTRADOS ++;
        } else {
            cliente[k].cadastrado = 0;
        }
    }

    free(string);
}

carregar_veiculos() {
    int k,a;
    char *string = (char*) malloc(500);

    for(k = 0; k < MAX_VEICULOS; k ++) {
        string[0] = '\0';
        sprintf(string, "veiculos/%d.txt", k);
        if(fdb_open(string)) {
            sprintf(veiculo[k].nome, "%s", fdb_GetString("Nome"));
            sprintf(veiculo[k].modelo, "%s", fdb_GetString("Modelo"));
            sprintf(veiculo[k].cor, "%s", fdb_GetString("Cor"));
            veiculo[k].val = fdb_GetInt("Valor");
            veiculo[k].num = fdb_GetInt("Numero");
            veiculo[k].locado = 0;
            veiculo[k].cadastrado = 1;
            fdb_close();
            TOTAL_VEICULOS_CADASTRADOS ++;
        }
    }

    for(k = 0; k < MAX_VEICULOS; k ++) {
        string[0] = '\0';
        sprintf(string, "locacoes/%d.txt", k);
        if(fdb_open(string)) {
            for(a = 0; a < MAX_VEICULOS; a ++) {
                if(fdb_GetInt("Numero") == veiculo[a].num) {
                    sprintf(veiculo[a].cliente_cpf, "%s", fdb_GetString("Cliente-CPF"));
                    veiculo[a].dias = fdb_GetInt("Dias-Locacao");
                    veiculo[a].dm[0] = fdb_GetInt("Dia");
                    veiculo[a].dm[1] = fdb_GetInt("Mes");
                    veiculo[a].locado = 1;
                    veiculo[a].cadastrado = 1;
                    fdb_close();
                    TOTAL_VEICULOS_LOCADOS ++;
                    break;
                }
            }
        }
    }
    free(string);
}

salvar_cliente(int indice) {
    char *string = (char*) malloc(15 + 3);
    sprintf(string, "clientes/%d.txt", indice);
    fdb_create(string);
    fdb_SetString("Nome", cliente[indice].nome);
    fdb_SetString("Endereco", cliente[indice].end);
    fdb_SetString("Email", cliente[indice].email);
    fdb_SetString("CPF", cliente[indice].cpf);
    fdb_SetInt("Idade", cliente[indice].idade);
    fdb_SetString("Habilitacao", cliente[indice].hab);
    fdb_save();
    free(string);
}

salvar_veiculo(int indice) {
    char *string = (char*) malloc(15 + 3);
    sprintf(string, "veiculos/%d.txt", indice);
    fdb_create(string);
    fdb_SetString("Nome", veiculo[indice].nome);
    fdb_SetString("Modelo", veiculo[indice].modelo);
    fdb_SetString("Cor", veiculo[indice].cor);
    fdb_SetInt("Valor", veiculo[indice].val);
    fdb_SetInt("Numero", veiculo[indice].num);
    fdb_save();
    free(string);
}

salvar_locacao(int indice) {
    char *string = (char*) malloc(15 + 3);
    sprintf(string, "locacoes/%d.txt", indice);
    fdb_create(string);
    fdb_SetInt("Numero", veiculo[indice].num);
    fdb_SetString("Cliente-CPF", veiculo[indice].cliente_cpf);
    fdb_SetInt("Dias-Locacao", veiculo[indice].dias);
    fdb_SetInt("Dia", veiculo[indice].dm[0]);
    fdb_SetInt("Mes", veiculo[indice].dm[1]);
    free(string);
}

remover_cliente(int indice) {
    char *string = (char*) malloc(15 + 3);
    sprintf(string, "clientes/%d.txt", indice);
    fdb_remove(string);
}

remover_veiculo(int indice) {
    char *string = (char*) malloc(15 + 3);
    sprintf(string, "veiculos/%d.txt", indice);
    fdb_remove(string);
}

remover_locacao(int indice) {
    char *string = (char*) malloc(15 + 3);
    sprintf(string, "locacoes/%d.txt", indice);
    fdb_remove(string);
}

salvar_clientes() {
    int a;
    char *string = (char*) malloc(500);

    for(a = 0; a < MAX_CLIENTES; a ++) {
        sprintf(string, "clientes/%d.txt", a);
        if(cliente[a].cadastrado) {
            fdb_create(string);
            fdb_SetString("Nome", cliente[a].nome);
            fdb_SetString("Endereco", cliente[a].end);
            fdb_SetString("Email", cliente[a].email);
            fdb_SetString("CPF", cliente[a].cpf);
            fdb_SetInt("Idade", cliente[a].idade);
            fdb_SetString("Habilitacao", cliente[a].hab);
            fdb_save();
        } else {
            if(fdb_exist(string)) {
                fdb_remove(string);
            }
        }
    }

    free(string);
}

salvar_veiculos() {
    int a;
    char *string = (char*) malloc(500);

    for(a = 0; a < MAX_VEICULOS; a ++) {
        if(veiculo[a].cadastrado) {

            sprintf(string, "veiculos/%d.txt", a);
            fdb_create(string);
            fdb_SetString("Nome", veiculo[a].nome);
            fdb_SetString("Modelo", veiculo[a].modelo);
            fdb_SetString("Cor", veiculo[a].cor);
            fdb_SetInt("Valor", veiculo[a].val);
            fdb_SetInt("Numero", veiculo[a].num);
            fdb_save();


            sprintf(string, "locacoes/%d.txt", a);
            if(veiculo[a].locado == 1) {
                fdb_create(string);
                fdb_SetInt("Numero", veiculo[a].num);
                fdb_SetString("Cliente-CPF", veiculo[a].cliente_cpf);
                fdb_SetInt("Dias-Locacao", veiculo[a].dias);
                fdb_SetInt("Dia", veiculo[a].dm[0]);
                fdb_SetInt("Mes", veiculo[a].dm[1]);
                fdb_save();
            } else {
                if(fdb_exist(string)) {
                    fdb_remove(string);
                }
            }
        } else {
            sprintf(string, "veiculos/%d.txt", a);
            if(fdb_exist(string)) {
                fdb_remove(string);
            }
        }
    }
    free(string);
}
