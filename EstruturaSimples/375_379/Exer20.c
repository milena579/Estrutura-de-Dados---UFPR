#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Servico {
    int codServico;
    char descricao[50];
    float valor;
} Servico;

typedef struct OrdemServico {
    int codOS;
    char data[20];
    int servico;
    char cliente[50];
    float valor;
} OrdemServico;

int main() {
    int sair = 1;
    int op;
    float soma = 0;
    float media = 0;
    int maiorValor = 0;
    int ordensCount = 0;

    OrdemServico *ordensServico = (OrdemServico*) malloc(sizeof(OrdemServico) * 10);

    Servico servicos[10] = {
        {1, "Troca de Óleo", 120.00},
        {2, "Alinhamento e Balanceamento", 150.00},
        {3, "Troca de Pneu", 300.00},
        {4, "Revisão Completa", 450.00},
        {5, "Troca de Pastilhas de Freio", 180.00},
        {6, "Troca de Amortecedores", 550.00},
        {7, "Descarbonização de Motor", 200.00},
        {8, "Substituição de Bateria", 250.00},
        {9, "Limpeza de Injetores", 160.00},
        {0, "Troca de Filtro de Ar", 70.00}
    };

    printf("\n\nOFICINA MECANICA");

    while (sair == 1) {
        printf("\n\nMenu");
        printf("\n1 - Registrar nova ordem de servico");
        printf("\n2 - Mostrar servicos");
        printf("\n3 - Mostrar ordens de servico");
        printf("\n0 - Sair\n");

        scanf("%i", &op);

        switch (op) {
            case 1:
                printf("\n\nNova Ordem de Servico");
                printf("\nCodigo: ");
                scanf("%i", &ordensServico[ordensCount].codOS);
                printf("Data: ");
                scanf("%s", ordensServico[ordensCount].data);
                printf("Código Servico: ");
                scanf("%i", &ordensServico[ordensCount].servico);
                printf("Cliente: ");
                scanf("%s", ordensServico[ordensCount].cliente);
                for (int j = 0; j < 10; j++) {
                    if (servicos[j].codServico == ordensServico[ordensCount].servico) {
                        ordensServico[ordensCount].valor = servicos[j].valor;
                    }
                }
                printf(">>>> Ordem de servico registrada!");
                soma += ordensServico[ordensCount].valor;

                if (ordensServico[ordensCount].valor > maiorValor) {
                    maiorValor = ordensServico[ordensCount].valor;
                }
                ordensCount++;
                break;

            case 2:
                printf("\n\nLista de Servicos:\n\n");
                for (int i = 0; i < 10; i++) {
                    printf("Codigo: %i\n", servicos[i].codServico);
                    printf("Descricao: %s\n", servicos[i].descricao);
                    printf("Valor: %.2f\n", servicos[i].valor);
                    printf("-------------------------\n");
                }
                break;

            case 3:
                printf("\n\nLista de Ordens de Servicos:\n\n");
                for (int i = 0; i < ordensCount; i++) {
                    printf("Codigo: %i\n", ordensServico[i].codOS);
                    printf("Data: %s\n", ordensServico[i].data);
                    for (int j = 0; j < 10; j++) {
                        if (servicos[j].codServico == ordensServico[i].servico) {
                            printf("Servico: %s\n", servicos[j].descricao);
                        }
                    }
                    printf("Cliente: %s\n", ordensServico[i].cliente);
                    printf("Valor total: %.2f\n", ordensServico[i].valor);
                    printf("-------------------------\n");
                }
                break;

            case 0:
                sair = 0;
                break;
        }
    }

    media = soma / ordensCount;
    printf("\nMedia de valores: %.2f", media);

    char clienteMaisCaro[50];
    float valorMaisCaro = 0;
    for (int i = 0; i < ordensCount; i++) {
        if (ordensServico[i].valor > valorMaisCaro) {
            valorMaisCaro = ordensServico[i].valor;
            strcpy(clienteMaisCaro, ordensServico[i].cliente);
        }
    }
    printf("\nCliente que realizou o servico mais caro: %s\n", clienteMaisCaro);

    free(ordensServico); 
    return 0;
}