#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>



int main()


{
    system("color 5f");
    SetConsoleTitle("\tARQUIVOS EM C");
 struct local{
    char log[20];
    char numero[15];
    char bairro[20];
    char cidade[20];
};

//typedef local;


struct contato{
    char nome[20];
    char tel[20];
    struct local endereco;

};
//typedef contato;

struct contato pessoa;

    FILE *gravador, *registro;
int x = 0;

        char busca[20];

char esc;
/*
do{
        system("cls");
        printf(" [1] - [CADASTRO] \n [2] - [BUSCA]\n [3] - [LISTAR]\n [4] - [SAIR]\n\nOpcao:");
        scanf("%c",&esc);
        fflush(stdin);

switch (esc){

case '1':
       printf("Nome:");
       gets(pessoa.nome);
       printf("Telefone:");
        gets(pessoa.tel);

        printf("Endereco:\nRua:");
            gets(pessoa.endereco.log);
        printf("Numero:");
            gets(pessoa.endereco.numero);
        printf("Bairro:");
            fflush(stdin);
            gets(pessoa.endereco.bairro);

     gravador = fopen("contatos.txt","ab");

            fwrite(&pessoa,sizeof(struct contato),1,gravador);

            printf("Salvo!");
    fclose(gravador);
    break;

case '2':

    printf("Nome ou Telefone:");
           gets(busca);
           x=0;
        gravador = fopen("contatos.txt","rb");
            while(fread(&pessoa,sizeof(struct contato),1,gravador)>0){


                if((strcmp(busca,pessoa.nome)==0) || (strcmp(busca,pessoa.tel)==0)){
                    x++;

                    if (x > 1){

                        printf("[%d CONTATOS ENCONTRADOS]",x);
                    }else{
                        printf("[%d CONTATO ENCONTRADO]",x);
                    }
                    printf("\nNome:%s\n",strupr(pessoa.nome));
                    printf("Telefone:%s\n",pessoa.tel);
                    printf("Endereco:%s\n",pessoa.endereco.log);
                    printf("Numero:%s\n",pessoa.endereco.numero);
                    printf("Bairro:%s\n",pessoa.endereco.bairro);

                }

                    if((x == 0) && (fgetc(gravador)==EOF)){
                        puts("Nada encontrado");
                        getchar();
                    }


            }getchar();
        fclose(gravador);
        break;

case '3':
    gravador = fopen("contatos.txt","rb");
            while(fread(&pessoa,sizeof(struct contato),1,gravador)>0){


                    printf("\nNome:%s\n",strupr(pessoa.nome));
                    printf("Telefone:%s\n",pessoa.tel);
                    printf("Endereco:%s\n",pessoa.endereco.log);
                    printf("Numero:%s\n",pessoa.endereco.numero);
                    printf("Bairro:%s\n",pessoa.endereco.bairro);
            }
        fclose(gravador);
        getchar();
        break;
case '4':
    esc = '4';
    break;
default :
    puts("Opcao invalida");
    break;

}

}while(esc != '4');*/
int day;
struct data {
    char day[3];
    char month[3];
    char year[3];

};

struct data Data1;
struct data Data2;

printf("Entre uma data: [dd/mm/aaaa]:");

gets(Data1.day);
gets(Data1.month);
gets(Data1.year);


day = atoi(day);

printf("%d",day);

    return 0;
}
