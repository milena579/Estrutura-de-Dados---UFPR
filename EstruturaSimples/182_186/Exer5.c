#include <stdio.h>

int main()
{
    int logica[15] = {5291, 3476, 7834, 6215, 8921, 1543, 4732, 9608, 2137, 8049, 3584, 4910, 6573, 2801, 9327};
    int linguagemProgramacao[10] = {5291, 1234, 5598, 3476, 8745, 7834, 6215, 8882, 1496, 6732};
    int conflito = 0;
    int * matriculasConflito = (int*) malloc(conflito * sizeof(int));

    printf("\n\nAlunos de logica: \n");
    for (int i = 0; i < 15; i++)
    {
        printf("%i | ", logica[i]);
    }
    
    printf("\n\nAlunos de linguagem de programacao: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%i | ", linguagemProgramacao[i]);
        for (int j = 0; j < 15; j++)
        {
            if(linguagemProgramacao[i] == logica[j]) {
                conflito++;
                matriculasConflito = (int*) realloc(matriculasConflito, conflito * sizeof(int));
                matriculasConflito[conflito-1] = linguagemProgramacao[i];
            }
        }
        
    }

    printf("\n\nMatriculas em conflito: \n");
    for (int i = 0; i < sizeof(matriculasConflito); i++)
    {
        printf("%i | ", matriculasConflito[i]);
    }

    free(matriculasConflito);
}