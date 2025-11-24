#include "../include/jogo.h"
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void novojogo(){

    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    int vez = 1, sair = 0;
    partida.rodada_alocacao = 0;

    while (!sair) {
        clear();
        while(partida.rodada_alocacao == 0){
            if(vez == 1)
                alocacaoInicial(vez, tabuleiro_j1, jogador1);
            else{
                alocacaoInicial(vez, tabuleiro_j2, jogador2);
                partida.rodada_alocacao = 1;
            }   
            printf("Pressione Enter para continuar...");
            getchar();
            getchar();
            vez = trocarVez(vez);   
        }   
        printf("Vez do jogador %d", vez);
        wprintf(L"Mapa do jogador adversário\n");
        
        int opc;
        clear();
        if(vez == 1)
            imprimirTabuleiro(tabuleiro_j1);
        else
            imprimirTabuleiro(tabuleiro_j2);
        wprintf(L"Digite uma opção: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Palpite");
                break;
            case 0:
                sair = 1;
                break;
            default:
                wprintf(L"Opção inválida. Tente novamente.\n");
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

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
    }
    wchar_t linha[256];
    while (fgetws(linha, sizeof(linha), arquivo)) {
        wprintf(L"%ls", linha);
    }

    fclose(arquivo);

        printf("\nPressione Enter para voltar...");
        getchar();
        //getchar();
        clear();
}
