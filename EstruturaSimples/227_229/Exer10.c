
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int matriz[5][5];
    int soma = 0;
    
    for(int i = 0; i < 5; i++){
        int num = rand() % 100 + 1;
        matriz[i][i] = num;
        
        for(int j = 0; j < 5; j++){
            int num = rand() % 100 + 1;

            matriz[i][j] = num;
        }
    }
    
    for(int i = 0; i < 5; i++){
        printf("\n");
        for(int j = 0; j < 5; j++){
            printf("[%i]", matriz[i][j]);
            soma  = soma + matriz[i][j];
        }
    }
    
    printf("\nA soma Total da matriz eh: %i", soma);
    soma = 0;
    
    printf("\n");
    printf("\nElementos linha 4\n");
    //linha 4 
    for(int i = 0; i < 5; i++){
        printf("[%i]", matriz[3][i]);
        soma = soma + matriz[3][i];
    }
    
    printf("\nA soma eh: %i", soma);
    soma = 0;
    
    printf("\n");
    printf("\nElementos coluna 2\n");
    //linha 4 
    for(int i = 0; i < 5; i++){
        printf("[%i]", matriz[i][1]);
        soma  = soma + matriz[i][1];
    }
    
    printf("\nA soma eh: %i", soma);
    soma = 0;
    
    printf("\n");
    printf("\nElementos Diagonal principal \n");
    //linha 4 
    for(int i = 0; i < 5; i++){
        printf("[%i]", matriz[i][i]);
        soma  = soma + matriz[i][i];
    }
    printf("\nA soma eh: %i", soma);
    soma = 0;
    
    printf("\n");
    printf("\nElementos Diagonal secundária \n");
    //linha 4 
    int count = 0;
    for(int i = 4; i >= 0; i--){
        printf("[%i]", matriz[count][i]);
        soma  = soma + matriz[count][i];
        count = count + 1;
    }
    
    printf("\nA soma eh: %i", soma);
    soma = 0;
    

    return 0;
}