#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numExemplar;
    char dataCompra[20];
} Obra;

typedef struct {
    int numTombo;
    char nomeObra[50];
    char nomeAutor[50];
    char nomeEditora[50];
    int codArea;
    Obra* obras;
    int qtdObras;
} Tombo;

int main() {
    int limiteTombos = 20;
    int limiteObras = 3;
    int totalTombos = 0;
    int op = -1;

    Tombo* tombos = (Tombo*)malloc(limiteTombos * sizeof(Tombo));

    while (op != 0) {
        printf("\nMenu:\n");
        printf("1 - Cadastrar tombos\n");
        printf("2 - Cadastrar obras\n");
        printf("3 - Mostrar obras por área\n");
        printf("4 - Mostrar obras por autor\n");
        printf("5 - Mostrar obras por editora\n");
        printf("0 - Sair\n");
        scanf("%i", &op);

        if (op == 1) {
            if (totalTombos < limiteTombos) {
                printf("Número do tombo: ");
                scanf("%i", &tombos[totalTombos].numTombo);
                printf("Nome da obra: ");
                scanf("%s", tombos[totalTombos].nomeObra);
                printf("Nome do autor: ");
                scanf("%s", tombos[totalTombos].nomeAutor);
                printf("Nome da editora: ");
                scanf("%s", tombos[totalTombos].nomeEditora);
                printf("Código da área: ");
                scanf("%i", &tombos[totalTombos].codArea);
                tombos[totalTombos].qtdObras = 0;
                tombos[totalTombos].obras = (Obra*)malloc(limiteObras * sizeof(Obra));
                totalTombos++;
            } else {
                printf("Limite de tombos atingido.\n");
            }

        } else if (op == 2) {
            int numTombo;
            printf("Informe o número do tombo: ");
            scanf("%i", &numTombo);
            int encontrado = 0;

            for (int i = 0; i < totalTombos; i++) {
                if (tombos[i].numTombo == numTombo) {
                    encontrado = 1;
                    if (tombos[i].qtdObras < limiteObras) {
                        int pos = tombos[i].qtdObras;
                        tombos[i].obras[pos].numExemplar = pos + 1;
                        printf("Data de compra: ");
                        scanf("%s", tombos[i].obras[pos].dataCompra);
                        tombos[i].qtdObras++;
                    } else {
                        printf("Já existem %i exemplares cadastrados.\n", limiteObras);
                    }
                    break;
                }
            }
            if (!encontrado) {
                printf("Tombo não encontrado.\n");
            }

        } else if (op == 3) {
            int cod;
            printf("Informe o código da área: ");
            scanf("%i", &cod);
            for (int i = 0; i < totalTombos; i++) {
                if (tombos[i].codArea == cod) {
                    printf("Obra: %s\n", tombos[i].nomeObra);
                }
            }

        } else if (op == 4) {
            char autor[50];
            printf("Informe o nome do autor: ");
            scanf("%s", autor);
            for (int i = 0; i < totalTombos; i++) {
                if (strcmp(tombos[i].nomeAutor, autor) == 0) {
                    printf("Obra: %s\n", tombos[i].nomeObra);
                }
            }

        } else if (op == 5) {
            char editora[50];
            printf("Informe o nome da editora: ");
            scanf("%s", editora);
            for (int i = 0; i < totalTombos; i++) {
                if (strcmp(tombos[i].nomeEditora, editora) == 0) {
                    printf("Obra: %s\n", tombos[i].nomeObra);
                }
            }

        } else if (op == 0) {
            printf("Saindo...\n");
        } else {
            printf("Opção inválida.\n");
        }
    }

    for (int i = 0; i < totalTombos; i++) {
        free(tombos[i].obras);
    }
    free(tombos);

    return 0;
}