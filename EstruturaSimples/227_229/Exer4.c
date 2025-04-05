#include <stdio.h>
#include <string.h>

int main()
{
    char alunos[15][50];
    float notas[15][6];
    char situacao[10];
    float somaMedias=0, media=0, perAprovados=0, perExame=0, perReprovados=0, countAprovados=0, countExame=0, countReprovados=0;
    
    printf("\nCadastro de alunos\n");
    
    for(int i = 0; i < 3; i++) {
        printf("\nAluno %i: ", i+1);
        scanf("%s", alunos[i]);
        printf("Nota 1: ");
        scanf("%f", &notas[i][0]);
        printf("Nota 2: ");
        scanf("%f", &notas[i][1]);
        printf("Nota 3: ");
        scanf("%f", &notas[i][2]);
        printf("Nota 4: ");
        scanf("%f", &notas[i][3]);
        printf("Nota 5: ");
        scanf("%f", &notas[i][4]);
    
        notas[i][5] = (notas[i][0] + notas[i][1] + notas[i][2] + notas[i][3] + notas[i][4]) / 5; 
        somaMedias += notas[i][5];
    }
    
    media = somaMedias / 15;
    
    printf("\nRelatorio individual");
    for(int i = 0; i < 15; i++) {
        if(notas[i][5] <= 5.0) {
            strcpy(situacao, "Reprovado");
            countReprovados++;
        }
        else if(notas[i][5] > 5.0 && notas[i][5] < 7.0) {
            strcpy(situacao, "Em exame");
            countExame++;
        }
        else {
            strcpy(situacao, "Aprovado");
            countAprovados++;
        }

        printf("\nNome: %s", alunos[i]);
        printf("Nota 1: %.2f | Nota 2: %.2f | Nota 3: %.2f | Nota 4: %.2f | Nota 5: %.2f", notas[i][0], notas[i][1], notas[i][2], notas[i][3], notas[i][4]);
        printf("Media: %.2f | Situacao: %s", notas[i][5], situacao);
    }

    perAprovados = (countAprovados * 100) / 15;
    perReprovados = (countReprovados * 100) / 15;
    perExame = (countExame * 100) / 15;
    
    printf("\n\nRelatorio da classe");
    printf("\nMedia: %.2f", media);
    printf("\nPercentual de alunos aprovados: %.2f %", perAprovados);
    printf("\nPercentual de alunos em exame: %.2f %", perExame);
    printf("\nPercentual de alunos reprovados: %.2f %", perReprovados);
    

    return 0;
}