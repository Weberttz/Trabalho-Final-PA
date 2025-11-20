#include <stdio.h>
#include <stdlib.h>
#include "../include/jogo.h"

int main() {
    int resposta;

    while (1) {  
        printf("Selecione a opção que você deseja : \n");
        printf("[1] Novo jogo \n");
        printf("[2] Continuar jogo \n");
        printf("[3] Instruções \n");
        printf("[0] Sair \n");

        scanf("%d", &resposta);

        switch (resposta) {
            case 1:                 
                montarTabuleiros();
                novojogo();
                break;

            case 2:
                printf("Carregar jogo ainda não implementado.\n");
                break;

            case 3:
                clear();
                instrucoes();
                clear();
                break;

            case 0:
                printf("Saindo...\n");
                return 0;        
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
