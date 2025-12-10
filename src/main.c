#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "../include/jogo.h"

int main() {
    
    int resposta;
    FILE *menu;
    char linha[256];
    setlocale(LC_ALL, "Portuguese");

    while (1) {  
        menu = fopen("../data/menu.txt", "r");
        while(fgets(linha, 256, menu)){
            printf("%s", linha);
        }
        printf("[1] Novo jogo \n");
        printf("[2] Continuar jogo \n");
        printf("[3] Instrucoes \n");
        printf("[0] Sair \n");
        printf("Selecione a opcao que voce deseja: ");

        if(!scanf("%d", &resposta)){
            clearBuffer();
            printf("Entrada invalida. Digite um numero!\n");
            printf("Pressione Enter para continuar...");
            getchar();
            clear();
            continue;
        }

        switch (resposta){
            case 1:                 
                novojogo();
                break;
            case 2:
                carregarJogo();
                execJogo();
                break;
            case 3:
                instrucoes();
                break;
            case 0:
                printf("Saindo...\n");
                return 0;    
            default:
                printf("Opcao invalida! Tente novamente.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                getchar();
                break;
        }
        clear();
    }

    return 0;
}
