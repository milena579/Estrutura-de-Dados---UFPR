#include <stdio.h>

int main(){
    char estado[15][20];
    int acidente[15];
    int carro[15];
    int maior = 0;
    int menor = 0;
    float media;
    float percentual;

    for (int i = 0; i < 15; i++)
    {
      printf("\n");
       printf("\nEscreva o nome do %iº estado: ", i+1);
       scanf("%s", estado[i]);

       printf("Numero de carros em 2006: ");
       scanf("%i", &carro[i]);

       printf("Numero de acidentes: ");
       scanf("%i", &acidente[i]);
    }

    for (int i = 1; i < 15; i++)
    {
       if(acidente[i] > acidente[maior]){
            maior = i;
       }
       if(acidente[i] < acidente[menor]){
            menor = i;
       }
    }

    printf("\nO estado com maior numero de acidentes foi %s com: %i\n", estado[maior], acidente[maior]);
    printf("O estado com menor numero de acidentes foi %s com: %i\n", estado[menor], acidente[menor]);
    
    for (int i = 0; i < 15; i++)
    {
        percentual = (acidente[i] * 100.0) / carro[i];
        media = (float)acidente[i] / carro[i];
        printf("\nPercentual de acidentes em %s: %.2f%%\n", estado[i], percentual);
        printf("Media de acidentes em %s: %.2f\n", estado[i], media);
    }

    return 0;
}
