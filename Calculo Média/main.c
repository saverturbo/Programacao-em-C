#include <stdio.h>
#include <stdlib.h>

int main()
{

   float nota1, nota2, media;
    printf("Por favor digita a 1ª nota: ");
    scanf("%f",&nota1);
    printf("Digite a 2ª nota: ");
    scanf("%f",&nota2);
    media = (nota1 + nota2)/2;
    printf("Sua media foi: %.2f ",media);



    return 0;
}


