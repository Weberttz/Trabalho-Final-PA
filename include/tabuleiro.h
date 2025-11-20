#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#include <stdio.h>
int tamanho = 5;
struct tabuleiros
{
    int jogador;
    char matriz_tabuleiro[5][5];
};
struct tabuleiros tabuleiro_j1, tabuleiro_j2;

void montarTabuleiros() {
    for(int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++)
        {
            tabuleiro_j1.matriz_tabuleiro[i][j] = '~';
        }
    }
       for(int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++)
        {
            tabuleiro_j2.matriz_tabuleiro[i][j] = '~';
        }
    }
}
void imprimirTabuleiro() {
    printf("Jogador 1 : \n");
    for(int i = 0; i< tamanho; i++){
        for(int j=0; j< tamanho; j++){
            printf("%c ", tabuleiro_j1.matriz_tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("Jogador 2 : \n");
    for(int i = 0; i< tamanho; i++){
        for(int j=0; j< tamanho; j++){
            printf("%c ", tabuleiro_j2.matriz_tabuleiro[i][j]);
        }
        printf("\n");
    }
}

#endif