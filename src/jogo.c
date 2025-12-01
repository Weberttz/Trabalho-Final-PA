#include "../include/jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void novojogo(){
    montarTabuleiros();
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    partida.turno = 1;
    partida.rodada_alocacao = 0;
    partida.fim = 0;

    clear();
    while(partida.rodada_alocacao == 0){
        if(partida.turno == 1)
            alocacaoInicial(partida.turno, tabuleiro_j1, &jogador1);
        else{
            alocacaoInicial(partida.turno, tabuleiro_j2, &jogador2);
            partida.rodada_alocacao = 1;
        }   
        printf("Pressione Enter para continuar...");
        getchar();
        getchar();
        partida.turno = trocarVez(partida.turno);   
    }   

    salvarJogo();
    execJogo();
}

void execJogo(){
    int opc, sair = 0;

    while(!partida.fim && sair == 0){

        printf("Vez do jogador %d\n", partida.turno);
        wprintf(L"Tabuleiro do jogador %d\n\n", 3 - partida.turno); 

        if(partida.turno == 1)
            imprimirTabuleiro(tabuleiro_j2);
        else
            imprimirTabuleiro(tabuleiro_j1);
        wprintf(L"\n[1] Realizar Palpite\n[0] Sair\nDigite uma opção: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                if(partida.turno == 1)
                    realizarPalpite(&jogador1, &jogador2, tabuleiro_j2);
                else
                    realizarPalpite(&jogador2, &jogador1 , tabuleiro_j1);

                printf("Pressione Enter para continuar...");
                getchar();
                partida.turno = trocarVez(partida.turno);
                break;
            case 0:
                salvarJogo();
                sair = 1;
                break;
            default:
                wprintf(L"Opção inválida. Tente novamente.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                getchar();
                break;
        }
        clear();
    }
}

void realizarPalpite(Player *jogador, Player *jogador_adversario, Celulas tabuleiro_adversario[tamanho][tamanho]){
    int x,y;
    do {
        printf("Digite a linha do palpite (0-%d): " , tamanho-1);
        if(scanf("%d", &x) != 1) {
            printf("Entrada inválida! Digite um número!\n");
            clearBuffer();
            continue;
        }

        printf("Digite a coluna do palpite (0-%d): " , tamanho-1);
        if(scanf("%d", &y) != 1) {
            printf("Entrada inválida! Digite um número!\n");
            clearBuffer();
            continue;
        }
        if(x < 0 || x >= tamanho || y < 0 || y >= tamanho ){
            printf("Posição fora do tabuleiro! Tente novamente.\n");
            continue; 
        }
        if(tabuleiro_adversario[x][y].impressao == '#' || tabuleiro_adversario[x][y].impressao == '%' || tabuleiro_adversario[x][y].impressao == 'x'){
            printf("Você já tentou essa posição! Escolha outra. \n");
            continue;
        }
        break;
        
    }
    while(1);        
        
    if(tabuleiro_adversario[x][y].valor != 0){
        int id = tabuleiro_adversario[x][y].valor;
        printf("ACERTOU!\n");
        jogador->acertos++;
        tabuleiro_adversario[x][y].impressao = '%';
        if(danosNavais(tabuleiro_adversario[x][y].valor, tabuleiro_adversario[x][y].impressao, tabuleiro_adversario, jogador)){
            printf("\nO navio %d foi afundado!", id);
            jogador_adversario->navios_restantes--;
        }
        if(jogador_adversario->navios_restantes == 0){
            printf("\nFim de jogo, jogador %d venceu!!", partida.turno);
            partida.fim = 1;
        }
    }
    else{
        wprintf(L"Água!\n");
        tabuleiro_adversario[x][y].impressao = 'x';
    }
    printf("\nPressione enter para continuar");
    getchar();
    getchar();
    clear();
    imprimirTabuleiro(tabuleiro_adversario);
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

void clearBuffer(){
    while (getchar() != '\n');
}

void instrucoes(){
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    clear();
    FILE *arquivo; 

    arquivo = fopen("../data/instrucoes.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
    }
    wchar_t linha[256];
    while (fgetws(linha, sizeof(linha), arquivo)) {
        wprintf(L"%s", linha);
    }

    fclose(arquivo);

    printf("\nPressione Enter para voltar...");
    getchar();
    //getchar();
    clear();
}
