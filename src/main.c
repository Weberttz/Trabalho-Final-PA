#include <stdio.h>
#include <stdlib.h>
#include "../include/jogo.h"

int main() {
    
    int resposta;
    inicio:
    printf("Selecione a opção que você deseja : \n");
    printf("[1] Novo jogo \n");
    printf("[2] Continuar jogo \n");
    printf("[3] Instruções \n");
    printf("[0] Sair \n");
    
    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1: 
        novojogo(); 
        break;

    case 2: 

        break;
    case 3:     
        clear();
        instrucoes();
        clear();
        goto inicio;
        break;
    case 0: 
        printf("Saindo...\n");
    default:
        printf("Opção Inválida! Tente novamente. \n");
    }
    return 0;
}