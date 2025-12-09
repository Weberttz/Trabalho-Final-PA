#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
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
        wprintf(L"[3] Instruções \n");
        printf("[0] Sair \n");
        wprintf(L"Selecione a opção que você deseja: ");

        if(!scanf("%d", &resposta)){
            clearBuffer();
            wprintf(L"Entrava inválida. Digite um número!\n");
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
                wprintf(L"Opção inválida! Tente novamente.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                getchar();
                break;
        }
        clear();
    }

    return 0;
}
