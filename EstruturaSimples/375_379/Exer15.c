#include <stdio.h>


typedef struct Cozinheiro {
    int cod;
    char nome [50];
} Cozinheiro;

typedef struct Receita {
    int cod;
    char nome[50];
    int calorias;
    int codCozinheiro;
} Receita;


typedef struct Ingrediente {
    int cod;
    char descricao[15];
} Ingrediente;

typedef struct IngredienteReceita {
    int codIngrediente;
    int codReceita;
    int quantidade;
    char unMedida[5];
} IngredienteReceita;


void cadastrarCozinheiro(Cozinheiro* cozinheiro, int posicao) {
    cozinheiro->cod = posicao + 1;  
    printf(cozinheiro->nome,50, "Cozinheiro %d", cozinheiro->cod);  
}


void cadastrarIngrediente(Ingrediente* ingrediente, int posicao) {
    ingrediente->cod = posicao + 1;  
    printf(ingrediente->descricao,50, "Ingrediente %d", ingrediente->cod);  
}


void cadastrarReceita(Receita* receita, int posicao, Cozinheiro* cozinheiros) {
    receita->cod = posicao + 1; 
    
    printf("Digite o nome da receita %d: ", receita->cod);
    fgets(receita->nome, 50, stdin);
    receita->nome[strcspn(receita->nome, "\n")] = 0;  
    
   
    printf("Digite o número de calorias da receita %d: ", receita->cod);
    scanf("%d", &receita->calorias);
    getchar();  

    
    printf("Digite o código do cozinheiro responsável pela receita (1 a %d): ", 3);
    scanf("%d", &receita->codCozinheiro);
    getchar(); 

    if (receita->codCozinheiro < 1 || receita->codCozinheiro > 3) {
        printf("Código do cozinheiro inválido! Atribuindo o cozinheiro 1 como responsável.\n");
        receita->codCozinheiro = 1;  
    }
}

void exibirReceitasPorCozinheiro(Receita* receitas, int numReceitas, Cozinheiro* cozinheiros, int codCozinheiro) {

    printf("\nReceitas do cozinheiro %d (%s):\n", codCozinheiro, cozinheiros[codCozinheiro - 1].nome);

    for (int i = 0; i < numReceitas; i++) {
        if (receitas[i].codCozinheiro == codCozinheiro) {
            printf("Código: %d, Nome: %s, Calorias: %d\n", receitas[i].cod, receitas[i].nome, receitas[i].calorias);
        }
    }
}

void exibirReceitasPorCalorias(Receita* receitas, int numReceitas, int minCalorias, int maxCalorias) {

    printf("\nReceitas dentro do intervalo de calorias (%d - %d):\n", minCalorias, maxCalorias);

    for (int i = 0; i < numReceitas; i++) {
        if (receitas[i].calorias >= minCalorias && receitas[i].calorias <= maxCalorias) {
            printf("Código: %d, Nome: %s, Calorias: %d\n", receitas[i].cod, receitas[i].nome, receitas[i].calorias);
        }
    }
}

void contarReceitasPorCozinheiro(Receita* receitas, int numReceitas) {
    int contadores[3] = {0}; 

    for (int i = 0; i < numReceitas; i++) {
        contadores[receitas[i].codCozinheiro - 1]++; 
    }
    
    printf("\nTotal de receitas por cozinheiro:\n");
    for (int i = 0; i < 3; i++) {
        printf("Cozinheiro %d (Código %d): %d receitas\n", i + 1, i + 1, contadores[i]);
    }
}

int main() {

    Cozinheiro cozinheiros[3];
    Ingrediente ingredientes[15];
    Receita receitas[20];
    IngredienteReceita ingredienteReceita[20 * 3];
    
    for (int i = 0; i < 3; i++) {
        cadastrarCozinheiro(&cozinheiros[i], i);
    }
    
    for (int i = 0; i < 15; i++) {
        cadastrarIngrediente(&ingredientes[i], i);
    }
    
    for (int i = 0; i < 20; i++) {
        cadastrarReceita(&receitas[i], i, cozinheiros);
    }
    
    int codCozinheiro;

    printf("\nInforme o código do cozinheiro para ver suas receitas: ");
    scanf("%d", &codCozinheiro);
    exibirReceitasPorCozinheiro(receitas, 20, cozinheiros, codCozinheiro);
    
    int minCalorias, maxCalorias;

    printf("\nInforme o intervalo de calorias (min e max): ");
    scanf("%d %d", &minCalorias, &maxCalorias);
    exibirReceitasPorCalorias(receitas, 20, minCalorias, maxCalorias);
    
    contarReceitasPorCozinheiro(receitas, 20);

    return 0;
}
