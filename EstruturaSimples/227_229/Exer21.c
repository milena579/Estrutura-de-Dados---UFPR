#include <stdio.h>
#include <string.h>

int main()
{
    int matriz[7][10];
    int number, soma=0;

    srand(time(NULL));


    printf("\nCadastro de alunos\n");
    
    printf("\nVetor: ");

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            number = rand() % 9 + 1;
            matriz[i][j] = number;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        soma = 0;
        for (int j = 0; j < 6; j++)
        {
            soma = soma + matriz[j][i];  
            matriz[6][i] = soma;
        }
    }
    
    for (int i = 0; i < 7; i++)
    {
        printf("\n");
        for (int j = 0; j < 10; j++)
        {
            printf(" %i ", matriz[i][j]);
        }
    }

    return 0;
}