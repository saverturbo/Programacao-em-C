#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "funcoes.h"



int main(){


    int i;
for (i=0; i<=100; i++){

        //Sleep(10);
        system("cls");
        printf("\n%c   Carregando    ",219);
        printf("%d%%  %c\n",i,219);

        barras(i/4);
        printf("\n");
}



    return 0;
}
