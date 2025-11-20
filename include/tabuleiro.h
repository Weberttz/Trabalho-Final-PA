#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#define TAMANHO 5

struct tabuleiros {
    int jogador;
    char matriz_tabuleiro[TAMANHO][TAMANHO];
};

extern struct tabuleiros tabuleiro_j1;
extern struct tabuleiros tabuleiro_j2;

void montarTabuleiros();
void imprimirTabuleiroj1();
void imprimirTabuleiroj2();

#endif
