#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "../include/jogo.h"

int main() {
    int resposta;
    FILE *menu;
    char linha[256];
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

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

        scanf("%d%*c", &resposta);

        switch (resposta){
            case 1:                 
                novojogo();
                break;
            case 2:
                wprintf(L"Carregar jogo ainda não implementado.\n");
                clear();
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
                //getchar();
                clear();
                break;
        }
    }

    return 0;
}
