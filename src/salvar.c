#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/salvar.h"

const char *nomeArquivo = "../data/partidas/save.bin"; 

void salvarJogo() {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar o jogo.\n");
        return;
    }
    fwrite(&partida, sizeof(Jogo), 1, arquivo);
    fwrite(&jogador1, sizeof(Player), 1, arquivo);
    fwrite(&tabuleiro_j1, sizeof(Celulas), tamanho * tamanho, arquivo);
    fwrite(&jogador2, sizeof(Player), 1, arquivo);
    fwrite(&tabuleiro_j2, sizeof(Celulas), tamanho * tamanho, arquivo);
    fclose(arquivo);

    //printf("Jogo salvo com sucesso em '%s'.\n", nomeArquivo);
}

void carregarJogo() {
    FILE *arquivo = fopen (nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para carregar o jogo.\n");
    }

    fread(&partida, sizeof(Jogo), 1, arquivo);
    fread(&jogador1, sizeof(Player), 1, arquivo);
    fread(&tabuleiro_j1, sizeof(Celulas), tamanho * tamanho, arquivo);
    fread(&jogador2, sizeof(Player), 1, arquivo);
    fread(&tabuleiro_j2, sizeof(Celulas), tamanho * tamanho, arquivo);
    fclose(arquivo);
    
    //printf("Jogo carregado do local '%s'.\n", nomeArquivo);
}