#include "../include/tabuleiro.h"
#include <stdio.h>

struct tabuleiros tabuleiro_j1, tabuleiro_j2;

void montarTabuleiros() {
    for(int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            tabuleiro_j1.matriz_tabuleiro[i][j] = '~';
            tabuleiro_j2.matriz_tabuleiro[i][j] = '~';
        }
    }
}

void imprimirTabuleiroj1() {
    printf("Jogador 1:\n");
    for(int i = 0; i< TAMANHO; i++){
        for(int j=0; j< TAMANHO; j++){
            printf("%c ", tabuleiro_j1.matriz_tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void imprimirTabuleiroj2() {
      printf("\nJogador 2:\n");
    for(int i = 0; i< TAMANHO; i++){
        for(int j=0; j< TAMANHO; j++){
            printf("%c ", tabuleiro_j2.matriz_tabuleiro[i][j]);
        }
        printf("\n");
    }
}