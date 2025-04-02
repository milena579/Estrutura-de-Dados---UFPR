
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int matriz[4][5];
    int somaMatriz[5];
    int soma;
    
    for(int i = 0; i < 4; i++){
        int num = rand() % 100 + 1;
        matriz[i][i] = num;
        
        for(int j = 0; j < 5; j++){
            int num = rand() % 100 + 1;

            matriz[i][j] = num;
        }
    }
    
    for(int i = 0; i < 4; i++){
        printf("\n");
        for(int j = 0; j < 5; j++){
            printf("[%i]", matriz[i][j]);
            soma  = soma + matriz[i][j];
        }
    }
    
    printf("\n");
    printf("\n");
    
    int coluna = 4;
    
    for(int i = 0; i < 5; i++){
        soma = 0;
        for(int j = 0; j < 4; j++){
            printf("[%i]", matriz[j][i]);
            soma = soma + matriz[j][i];

        }
        printf("\n");
        somaMatriz[i] = soma;
    }
    
    for(int i = 0; i < 5; i++){
        if(somaMatriz[i] > 10){
            printf(" - Soma coluna %i : %i", i+1, somaMatriz[i]);
        }
        printf("\n");
    }
  
   

    return 0;
}