#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[3][3];
    int i, j, somadp=0;

    printf("Digite os elementos da matriz: \n\n");
    for (i=0; i<=2; i++){
        for(j=0; j<=2; j++){
                printf("Elemento da posicao: (%d, %d):", i+1 , j+1);
                scanf("%d",&matriz[i][j]);
           if(i == j){
                somadp = somadp + matriz[i][j];
           }

        }
    }
    system("cls");
    for (i=0; i<=2; i++){
        for(j=0; j<=2; j++){
            printf("\t%d\   ",matriz[i][j]);
        }
        printf("\n\n");
    }
    printf("Soma dos elementos da diagonal principal: %d\n", somadp);
    return 0;
}
