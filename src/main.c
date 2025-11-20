#include <stdio.h>
#include "../include/jogo.h"


int main() {

    int resposta;

    printf("Selecione a opção que você deseja : \n");
    printf("1. Novo jogo \n");
    printf("2. Continuar jogo \n");
    printf("3. Instruções \n");
    printf("0. Sair \n");
    
    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1: novojogo();
    case 2: 
    case 3: instrucoes();
    case 0: 
    default:
        break;
    }

    return 0;
}