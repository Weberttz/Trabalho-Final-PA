#include "../include/jogo.h"
#include <stdio.h>
#include <stdlib.h>

void novojogo(){
    int vez = 1;
    int sair = 0;
    while (!sair) {
        clear();
        printf("\nVez do Jogador %d\n\n", vez);
        printf("Mapa do jogador adversario\n\n");
        if (vez == 1) {
            imprimirTabuleiroj2();
        } else {
            imprimirTabuleiroj1();
        }
        printf("\nEscolha uma ação:\n");
        printf("[1] Testar jogada\n");
        printf("[0] Sair para o menu\n");
        printf("Digite a opção: ");

        int opc;
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Jogador %d realizou uma ação (simulada).\n", vez);
                printf("Pressione Enter para continuar...");
                getchar();
                getchar();
                vez = trocarVez(vez);
                break;

            case 0:
                sair = 1;
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                getchar();
                break;
        }
    }

    clear();
}


int trocarVez(int vezAtual) {
    return (vezAtual == 1) ? 2 : 1;
}

void clear() {
    #ifdef _WIN32
    system("cls");
    #else 
    system("clear");
    #endif
}

void instrucoes(){
    FILE *arquivo; 

    arquivo = fopen("../data/instrucoes.txt", "r");
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {    
        printf("%s", linha);
    }

    fclose(arquivo);

        printf("\nPressione Enter para voltar...");
        getchar();
        getchar();
        clear();

}
