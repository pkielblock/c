#include<stdio.h> 
int main() { 
    int a;  
    
    FILE *arq; // define a variável Arq, que fará referência ao arquivo a ser gravado 
    arq = fopen("08-EscritaeLeitura.txt", "w"); // abre o arquivo dados.txt, o parâmetro "w" indica gravação 
    
    a = 945;
    printf("%d\n", a); // mostra na tela o valor de A (945) 
    fprintf(arq, "%d\n", a); // grava no arquivo o valor de A seguido de um pulo de linha 

    a = 1691;  
    printf("%d\n", a); // mostra na tela o novo valor de A (1691) 
    fprintf(arq, "%d\n", a); //grava no arquivo o valor de A seguido de um pulo de linha 

    fclose(arq); // ao final é preciso fechar o arquivo  
    return 0;
}