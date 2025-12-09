#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#pragma once

#include "modulos.h"

#define tamanho 10

extern Celulas tabuleiro_j1[tamanho][tamanho], tabuleiro_j2[tamanho][tamanho];

//Função que monta os tabuleiros
void montarTabuleiros();

//Função que imprime o tabuleiro do jogador1
void imprimirTabuleiro(Celulas tabuleiro[tamanho][tamanho]);

//Função que muda os representantes das células(tabuleiro);
void mudarRepresentantes(Celulas tabuleiro[tamanho][tamanho]);

//Função que muda os representantes do tabuleiro, caso o navio seja destruído
void mudarRepNavio(int id, Celulas tabuleiro[tamanho][tamanho]);

#endif 