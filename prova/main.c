#include <stdio.h>
#include <stdlib.h>

int main()
{
    int menu = 0;

    printf("Digite 1 para ver numeros decrescente\n Digite 2 para ver quem tirou a menor nota\n Digite 3 para soma de vetores\n Digite 4 para sair\n");
    scanf("%i",&menu);

    switch(menu){
    case 1:
        printf("Voce Clicou a opcao 1 digte um numero\n");
        int numero = 0;
        scanf("%i",&numero);
        int numeroFinal = numero;
        int i;

        for(i = 0; i <= numeroFinal ; i++){
            printf("O numero é %i\n",numero);
            numero--;
        }
        main();
        break;
    case 2:
        printf("Voce clicou a opcao 2 digite os alunos e suas notas 2\n");

        int notas[10][3];
        int count;
        int countNota;

        int menorNota1 = 0;
        int menorNota2 = 0;
        int menorNota3 = 0;

        int qtdMenorNota1 = 0;
        int qtdMenorNota2 = 0;
        int qtdMenorNota3 = 0;

        int flag = 0;


        for(count = 0; count <= 9 ;count++){
                printf("Digite o numero do aluno:\n\n");

                scanf("%i",&notas[count]);

            for(countNota = 0; countNota <= 2 ;countNota++){

                    flag = countNota;

                    printf("Digita a nota  do aluno\n", notas[count]);
                    scanf("%i",&notas[count][countNota]);

                    if(flag == 0){
                        menorNota1 = notas[count][countNota];
                    }

                     if(flag == 1){
                        menorNota2 = notas[count][countNota];
                    }

                     if(flag == 2){
                        menorNota3 = notas[count][countNota];
                    }

                     if( notas[count][countNota] < menorNota1 && flag == 0){
                        menorNota1 = notas[count][countNota];
                    }else if( notas[count][countNota] < menorNota1 && flag == 1){
                        menorNota2 = notas[count][countNota];
                    }else if(notas[count][countNota] < menorNota1 && flag == 2){
                        menorNota3 = notas[count][countNota];
                    }

                    if((menorNota1 < menorNota2) && (menorNota1 < menorNota3) && flag == 2 ){
                        qtdMenorNota1++;
                    }else if((menorNota2 < menorNota1) && (menorNota2 < menorNota3) && flag == 2){
                        qtdMenorNota2++;
                    }else if((menorNota3 < menorNota1) && (menorNota3 < menorNota2) && flag == 2){
                        qtdMenorNota3++;
                    }

            }
        }



        printf("Quantidade de Alunos com menor nota na 1 %i\n", qtdMenorNota1);

        printf("Quantidade de Alunos com menor nota na 2 %i\n", qtdMenorNota2);

        printf("Quantidade de Alunos com menor nota na 3 %i\n", qtdMenorNota3);
        main();
        break;
    case 3:

        printf("Voce clicou na opcao 3 digite a posicao e o valores para soma\n");

        int soma[3][3];
        int resultado[2];
        int countS;
        int countSoma;
        int countResultado = 0;

        int valor1 = 0;
        int valor2 = 0;
        int valor3 = 0;


        int flagPosicao = 0;
        int flagSoma = 0;

        for(countS = 0; countS <= 2 ;countS++){

            scanf("%i", &soma[countS]);

            for(countSoma = 0; countSoma <= 2 ;countSoma++){

                    flagSoma = countSoma;

                    if(flagSoma < 2){
                    printf("Digite o valor\n");
                    scanf("%i",&soma[countS][countSoma]);
                    if(flagSoma == 0){
                       valor1 =  soma[countS][countSoma];
                    }else if(flagSoma == 1){
                        valor2 = soma[countS][countSoma];
                    }else if(flag == 2){
                        valor3 = soma[countS][countSoma];
                    }
                    }

                 if(flagSoma == 2){
                    resultado[countResultado] = valor1 + valor2 + valor3;
                     valor1 = 0;
                     valor2 = 0;
                     valor3 = 0;
                     countResultado++;

                  }

            }

        }

        int e;

        for(e = 0; e <= 2 ;e++){
          printf("%i\n",resultado[e]);

        }
        main();
        break;
        case 4:
        printf("Sair");
        break;

    }
}
