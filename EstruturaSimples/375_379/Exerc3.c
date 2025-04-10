#include <stdio.h>
#include <string.h>

typedef struct Habitante {
  char sexo[20];
  float altura;
  int idade;
  char corOlhos[20];
} Habitante;

int main()
{
    Habitante habitantes[50];
    float mediaIdade = 0;
    int somaIdade = 0;
    int countPessoa = 0;
    int maiorIdade = 0;
    int qtdMulheres = 0;
    int countHomens = 0;
    float perHomens = 0;

    printf("\nColeta de dados");

    for(int i = 0; i < 50; i++) {
        printf("\n\n>>>> Habitante %i", i+1);
        printf("\nSexo: ");
        scanf("%s", habitantes[i].sexo);
        printf("Altura: ");
        scanf("%f", &habitantes[i].altura);
        printf("Idade: ");
        scanf("%i", &habitantes[i].idade);
        printf("Cor dos olhos: ");
        printf("\n  A - Azuis");
        printf("\n  V - Verdes");
        printf("\n  C - Castanhos");
        printf("\n>> ");
        scanf("%s", habitantes[i].corOlhos);
        
        if(strcmp(habitantes[i].corOlhos, "C") == 0 && habitantes[i].altura > 1.60) {
            somaIdade += habitantes[i].idade;
            countPessoa++;
        }
        
        if(habitantes[i].idade > maiorIdade) {
            maiorIdade = habitantes[i].idade;
        }
        
        if(strcmp(habitantes[i].sexo, "Feminino") == 0 && 
           ((habitantes[i].idade < 45 && habitantes[i].idade > 20) || 
            (strcmp(habitantes[i].corOlhos, "V") == 0 && habitantes[i].altura < 1.70))) {
            qtdMulheres++;
        }
        
        if(strcmp(habitantes[i].sexo, "Masculino") == 0) {
            countHomens++;
        }
    }
    
    if (countPessoa > 0) {
        mediaIdade = (float)somaIdade / countPessoa;
    }
    
    perHomens = (float)(countHomens * 100) / 50;

    for(int i = 0; i < 50; i++) {
        printf("\nsexo: %s", habitantes[i].sexo);
        printf("\naltura: %.2f", habitantes[i].altura);
        printf("\nidade: %i", habitantes[i].idade);
        printf("\ncor: %s", habitantes[i].corOlhos);
    }
    
    printf("\n\nResultados: ");
    printf("\nMédia de idade das pessoas com olhos castanhos e altura superior a 1,60m: %.2f anos", mediaIdade);
    printf("\nMaior idade entre os habitantes: %i", maiorIdade);
    printf("\nQuantidade de indivíduos do sexo feminino com idade entre 20 e 45 anos ou que tenham olhos verdes e altura inferior a 1,70m: %i", qtdMulheres);
    printf("\nPercentual de homens: %.2f%%", perHomens);
    
    return 0;
}