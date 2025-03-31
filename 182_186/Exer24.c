#include <stdio.h>
#include <stdlib.h>

int main(){
    int numeros[15] = {5, 4, 10, 3, 2, 8, 9, 12, 15, 17, 150, 60, 18, 44, 23};
    int tamanho = 1;
    int i, j;

    int* primos = (int *)malloc(tamanho * sizeof(int));

    for ( i = 0; i < 15; i++){
        int contador = 0;

        for ( j = 1; j < numeros[i]; j++)
        {
            if(numeros[i] %j == 0){
                contador++;
            }   

            if(contador > 2){
                break;
            }
        }

        if(contador <= 2){
            primos[tamanho - 1] = numeros[i];
            tamanho = tamanho + 1;
            primos = (int *)realloc(primos, tamanho * sizeof(int));
        }
        
    }

    for ( i = 0; i < tamanho - 1; i++){
        printf("[ %i]", primos[i]);
    }
    

    free(primos);

    return 0;
    
}