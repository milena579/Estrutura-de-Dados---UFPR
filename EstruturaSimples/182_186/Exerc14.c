#include <stdio.h>
#include <string.h>

int main()
{
    char alunos[6][50];
    float notas[6][3];
    char situacao[10];
    float somaMedias=0, media=0, perAprovados=0, perExame=0, perReprovados=0, countAprovados=0, countExame=0, countReprovados=0;
    
    printf("\nCadastro de alunos\n");
    
    for(int i = 0; i < 6; i++) {
        printf("\nAluno %i: ", i+1);
        scanf("%s", alunos[i]);
        printf("Nota 1: ");
        scanf("%f", &notas[i][0]);
        printf("Nota 2: ");
        scanf("%f", &notas[i][1]);
        
        notas[i][2] = (notas[i][0] + notas[i][1]) / 2; 
        somaMedias += notas[i][2];
    }
    
    media = somaMedias / 6;
    
    printf("\nRelatorio individual");
    for(int i = 0; i < 6; i++) {
        if(notas[i][2] <= 5.0) {
            strcpy(situacao, "Reprovado");
            countReprovados++;
        }
        else if(notas[i][2] > 5.0 && notas[i][2] < 7.0) {
            strcpy(situacao, "Em exame");
            countExame++;
        }
        else {
            strcpy(situacao, "Aprovado");
            countAprovados++;
        }

        printf("\nNome: %s | Nota 1: %.2f | Nota 2: %.2f | Media: %.2f | Situacao: %s", alunos[i], notas[i][0], notas[i][1], notas[i][2], situacao);
    }

    perAprovados = (countAprovados * 100) / 6;
    perReprovados = (countReprovados * 100) / 6;
    perExame = (countExame * 100) / 6;
    
    printf("\n\nRelatorio da classe");
    printf("\nMedia: %.2f", media);
    printf("\nPercentual de alunos aprovados: %.2f %", perAprovados);
    printf("\nPercentual de alunos em exame: %.2f %", perExame);
    printf("\nPercentual de alunos reprovados: %.2f %", perReprovados);
    

    return 0;
}