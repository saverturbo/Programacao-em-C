#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"


int main()
{
    top = 0;
    setlocale(LC_ALL,"");

    do{
        menu();
            switch (option){
                case 1:
                    empilhar();
                    break;
                case 2:
                    desempilhar();
                    break;
                case 3:
                    listar_todos();
                    break;
            }



    }while(option != 4);

    return 0;
}
