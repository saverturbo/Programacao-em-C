#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x, *nums;
    printf("Digite a qtd de numeros:");
    scanf("%d",&n);

    nums = (int *) malloc(n * sizeof(int));

    for(x=0; x<n; x++){
        printf("Digite o %d numero: ",x+1);
        scanf("%d",&nums[x]);
    }

    for(x=0; x<n; x++){
        printf("O %d numero digitado: %d \n",x+1, nums[x]);

    }
    return 0;
}
