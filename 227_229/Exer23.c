
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int matriz[4][5];
    int somaMatriz[5];

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
        }
    }
    
   

    return 0;
}