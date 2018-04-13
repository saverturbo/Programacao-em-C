#include <stdio.h>
#include <stdlib.h>

    void triangular (){
        int l1, l2, l3;
    do{
        printf("Digite os lados do triangulo.\nLado 1:");
        scanf("%d",&l1);
        printf("Lado 2:");
        scanf("%d",&l2);
        printf("Lado 3:");
        scanf("%d",&l3);
    if(((l1 + l2) > l3) && ((l1 + l3) > l2) && ((l2 + l3) > l1)){

        if(l1 == l2 && l2 == l3 && l1 == l3){
            printf("TRIANGULO EQUILATERO");
        }else{
            if(l1 == l2 || l2 == l3 || l1 == l3){
                printf("TRIANGULO ISOCELES!");
            }else{
                printf("TRIANGULO ESCALENO!");
            }
        }
    }else{
        printf("Estes valores nao formam um triangulo!\n");
    }


    }while(l1 <= 0 || l2 <= 0 || l3 <= 0);


    }

int main()
{
    triangular();

    return 0;
}
