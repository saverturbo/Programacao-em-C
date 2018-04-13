#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
     int *ponteiro;
        int x;
    ptr = (int *) malloc(sizeof(int));
    printf("Digite a qtd de numeros:");
    scanf("%d",ptr);
    ponteiro = (int *) malloc((*ptr) * sizeof(int));

    int v[*ptr];
    v[0] = 0;
    for(x=1; x<= (*ptr); x++){
        printf("Digite o %d valor: ", x);
        scanf("%d",ponteiro);

        v[0] = v[0] + (*ponteiro);
        ponteiro++;
    }

   printf("\nMedia: %d", v[0]/(*ptr));




    return 0;
}
