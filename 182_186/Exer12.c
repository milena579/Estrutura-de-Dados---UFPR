#include <stdio.h>

int main() {
    int numeros[5];
    int soma;

    for (int i = 0; i < 5; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    printf("A soma dos itens foi: \n");

    for (int i = 0; i < 5; i ++){
        if(i == 4 ){
            printf("%i = ", numeros[i]);
        }
        else{
            printf("%i + ", numeros[i]);   
        }

        soma = soma + numeros[i];
    }
    
    printf("%i", soma);
   
    
}
