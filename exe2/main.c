#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sal, pres, porc;
    printf("Digite o salario: ");
    scanf("%f",&sal);
    printf("Digite o valor da prestação: ");
    scanf("%f",&pres);
    porc = sal * 0.30;
    if (pres <= porc){
        printf("Emprestimo concedido");
    }else{
        printf("Emprestimo nao pode ser concedido");
    }
    return 0;
}
