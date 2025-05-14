// Calcule o comprimento da string
// Inverta a string original
// Imprima o comprimento, a string invertida e a string original em maiúsculas

#include <stdio.h>  
#include <stdlib.h>  

// Função para calcular o comprimento da string  
int my_strlen(char *str) {  
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}  

// Função para inverter a string  
void my_reverse(char *str) {  

    int tamanho = my_strlen(str);

    for (int i = 0; i < tamanho/2; i++){
        char temp = str[i]; 
        str[i] = str[tamanho - i -1];
        str[tamanho - i - 1] = temp;
    }
}  

// Função para converter para maiúsculas  
void my_toupper(char *str) {  
    int tamanho = my_strlen(str);

    for (int i = 0; i < tamanho; i++){
        if(str[i]  >= 'a' && str[i]  <= 'z'){
            str[i]  = str[i]  - 32;
        }
    }
}  

int main() {  
    char str[100];  
    scanf("%99[^\n]", str); // Lê até 99 caracteres ou nova linha  

    int len = my_strlen(str);  
    printf("Comprimento: %d\n", len);  

    my_reverse(str);  
    printf("Invertida: %s\n", str);  

    my_reverse(str); // Reverte de volta para original  
    my_toupper(str);  
    printf("Maiúsculas: %s\n", str);  

    return 0;  
}  
