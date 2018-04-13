
#include <stdio.h>
#include <string.h> // Biblioteca para manipulação de strings
#include <stdlib.h>
#include <conio.h>
#include <ctype.h> //Biblioteca para manipulação de caracteres.


typedef struct Agenda
{
        char nome[20];
        char tel[15];
}tab_agenda;

// Protótipos
void Inclusao(void); // prototipo da função de inclusão, void  nao recebe nada.
void Listar(void); // prototipo da função de listar. idem acima
void Ordenar(void); // prototipo da função de ordenar. idem acima
void Pesquisar(void); // prototipo da função de pesquisa. idem acima
void Menu(void); // prototipo da função de menu. idem acima
char ValidaResp(); // prototipo da função de validaresp recebe o valor op

static int qntd = 0;
tab_agenda Tab[50];
FILE *fp;


int main (){

    Menu();
    system("pause");
}



/*##############################################################*/
//                                                                                                                                            //
//                                                                                                                                            //
//                      INICIO DAS FUNÇÕES                                                                                     //
//                                                                                                                                            //
//                                                                                                                                            //
/*##############################################################*/




//Função para incluir dados no arquivo agenda.txt

void Inclusao(void){
     int add = 0, escrita;



     if ((fp = fopen("agenda.txt", "a")) == NULL)
     {
        printf ("Erro! Arquivo não pode ser aberto!\n");
        printf ("Faltam dados!\n");
        getch();
        //fecha programa
        exit(1);
     }

       printf ("Digite o nome....: ");
       gets(Tab[add].nome);
       printf ("Digite o Telefone: ");
       gets(Tab[add].tel);
       escrita = fwrite(&Tab[add], sizeof(struct Agenda) ,1,fp);

       if (escrita == 1) {
           printf(" \n Salvo com sucesso! ");

       }
          // add++;
           //op = ValidaResp();
           qntd++;

     fclose (fp);
}



// Ordena alfabeticamente
void Ordenar(void){



    tab_agenda vet;
    int numconts,i,j,k,escrita;
    char *string_a, *string_b;


        numconts = qntd; // numconts recebe a quantidade de contatos inscritos
        //enquanto i for menos que numconts executa isso
        for ( i = 0 ; i < numconts ; i++ ){
            //damos o valor de nome a string_a
               string_a = Tab[i].nome;
                //enquanto j for menos que numconts executa isso, claoq ue j inicia com o acrescimento de i
               for ( j = i+1 ; j < numconts ; j++ ){
                   //damos o valor do nome subsequente a string_b
                   string_b = Tab[j].nome;
                   //faz a comparação com strcmp
                   if ( strcmp ( string_a, string_b ) > 0 ){
                        vet = Tab[i];
                        Tab[i] = Tab[j];
                        Tab[j] = vet;
                   }
               }
        }
    //Remove o arquivo agenda.txt
    remove("agenda.txt");
    if ((fp = fopen("agenda.txt", "w+")) == NULL){
        // Pode ocorrer erro caso não haja permissão de leitura e/ou escrita (comum em linux)
        printf ("Erro!\n");
        getch();
        exit(1);
    }
     // Inicia a reescrita com os nomes ordenados
    for ( k = 0 ; k < numconts ; k++ ){
         //fwrite abre o arquivo para escrita
           escrita = fwrite (&Tab[k], sizeof(struct Agenda) ,1,fp);
           //apos a escrita retorna valor 1 se diferente houve erro
           if (escrita != 1) {

               // Pode ocorrer erro caso não haja permissão de leitura e/ou escrita (comum em linux)
               printf(" \n Erro ! ");
           }
    }
     //fclose: fecha o arquivo e salva
     fclose(fp);
     printf("\n Lista Ordenada! \n");
     getch();
}

// Pesquisar contato pelo nome

void Pesquisar(void){
     int indice = 0, leitura = 1, cont = 0;
     char nome[20];

     if ((fp = fopen("agenda.txt", "r")) == NULL){
         // Pode ocorrer erro caso não haja permissão de leitura e/ou escrita (comum em linux)
         printf (" O arquivo da lista não pode ser aberto!\n");
         printf (" Insira dados!\n");
         getch();
         exit(1);
     }
     printf ("Digite o nome: ");
     gets(nome);

    //fread: file read, "lê arquivo"
    //sizeof(operador): é usado para  saber o tamanho de variáveis
    //sizeof serve tambem para garantir a portabilidade
     leitura = fread(&Tab[indice], sizeof(struct Agenda), 1, fp);

        while (leitura == 1){
            //faz a comparação com "strcmp" em todos os indices da estrutura nome por algo igual ao digitado
            //nome digita com a posição nome no indice x por exemplo (x é um numero)
            if (strcmp(nome, Tab[indice].nome) == 0 ){

            printf ("\nNome ......: %s\nTelefone ..: %s\n", Tab[indice].nome, Tab[indice].tel);

            //adiciona ao contador
            cont++;
            }
            indice++;//incrementa indice

            /*
            fread: Lê uma matriz de elementos a partir do fluxo e armazena-os no bloco de memória especificada por ptr.

            fread ( tabela, tamanho a ser lido, quantidade minima a ser contada, arquivo );

            */
            leitura = fread(&Tab[indice], sizeof(struct Agenda), 1, fp); //le novamento com um novo indice
        }
        //caso ocontador seja 0 retorna que não houve resultados.
        if(cont == 0){
                     printf("Nao ha contatos com este nome!\n");
                     }
        getch();
        fclose(fp);
   }

//função responsavel por listar o conteudo da agenda

void Listar(void){


    /* funciona como a função de pesquisa sem o strcmp */
int indice = 0, leitura;

    if ((fp = fopen("agenda.txt", "r")) == NULL)
    {
    printf ("O arquivo da lista não pode ser aberto!\n");
    printf ("Insira dados!\n");
    getch();
    exit(1);
    }

    leitura = fread(&Tab[indice], sizeof(struct Agenda), 1, fp);
   // fread lê e retorna a quantidade de itens ...

   while ( leitura == 1) {
      printf("\n Nome ......: %s",   Tab[indice].nome);
      printf("\n Telefone ..: %s",   Tab[indice].tel);
      printf("\n");
      indice++;
      leitura = fread(&Tab[indice], sizeof(struct Agenda), 1, fp);
    }
      printf(" \n\n %d Contatos salvos!\n", indice);
      getch();
      fclose(fp);
}

// Menu

void Menu(void){
    char op;
    do{
        system("cls"); //Limpa a tela
        printf("\n Escolha uma op%c%co: \n");
        printf("\n1 - Incluir\n2 - Listar\n3 - Ordenar\n4 - Pesquisar\n");
        printf("5 - Sair\n\n"); //Não seria necessario, mas por estetica coloquei
        op = getch();
            switch(op){
                case '1':
                     Inclusao();
                break;
                case '2':
                     Listar();
                break;
                case '3':
                     Ordenar();
                break;
                case '4':
                     Pesquisar();
                break;

                default: // por default qualquer tecla diferente das citadas faz o programa fechar
                exit(1);
            }
    }while (op < '5');

}

