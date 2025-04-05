#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matriz[3][4];
    int i, j;
    int pares = 0;
    int soma_impares = 0;
    int soma_total = 0;

    srand(time(NULL));

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            matriz[i][j] = rand() % 100;
            printf("%4d", matriz[i][j]);

            if (matriz[i][j] % 2 == 0)
                pares++;
            else
                soma_impares += matriz[i][j];

            soma_total += matriz[i][j];
        }
        printf("\n");
    }

    printf("\nQuantidade de pares: %d\n", pares);
    printf("Soma dos ímpares: %d\n", soma_impares);
    printf("Média dos elementos: %.2f\n", soma_total / 12.0);

    return 0;
}
