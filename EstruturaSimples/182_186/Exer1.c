#include <stdio.h>


int main(){
    int numeros[6];
    int qtdPares = 0;
    int qtdImpares = 0;
    int somaPar = 0 ;
    int somaImpar = 0;
    int i;
    
    for (i = 0; i < 6; i++){
        printf("Digite o %iº numero: ", i+1);
        scanf("%i", &numeros[i]);
    }

    for (i = 0; i < 6; i++){
        if(numeros[i] %2 == 0){
            qtdPares++;
            somaPar = somaPar + numeros[i];
        } 
        else{
            qtdImpares++;
            somaImpar = somaImpar + numeros[i];
        }
    }

    printf("A quantidade de numeros pares eh: %i -  Calculo dos PARES: %i", qtdPares, somaPar);
    printf("\nA quantidade de numeros impares eh: %i -  Calculo dos IMPARES: %i", qtdImpares, somaImpar);

    return 0;
}