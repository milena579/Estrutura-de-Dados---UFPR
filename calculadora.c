#include <stdio.h>

int main()
{   int num1 = 0;
    int num2 = 0;
    double total;
    int op;
    double modulo = 0;
    
    printf("-----Escolha a operacao------");
    printf("\n ------ 1 - SOMA -------------");
    printf("\n ------ 2 - SUBTRACAO -------------");
    printf("\n ------ 3 - MULTIPLICACAO -------------");
    printf("\n------ 4 - DIVISAO -------------");
    
    printf("\nOpcao: ");
    scanf("%i", &op);

    printf("Digite o primeiro valor: ");
    scanf("%i", &num1);
    
    printf("Digite o segundo valor: ");
    scanf("%i", &num2);
    
    switch(op){
       case 1: 
            total = (double) num1 + num2;
            break;
        case 2: 
            total = (double) num1 - num2;
            break;
        case 3: 
            total = (double) num1 * num2;
            break;
        case 4: 
            if(num1 == 0 || num2 == 0 ){
                printf("Não é possível fazer divisão em zero");
                break;
            }
            total = (double) num1 / num2;
            modulo = num1 % num2;
            printf("O modulo dessa operacao eh: %f \n", modulo);

            break;
        default:
            break;
   }
   
   printf("O resultado da operacao eh: %f", total);
}