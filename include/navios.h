#ifndef NAVIOS_H_
#define NAVIOS_H_

#pragma once

#include "tabuleiro.h"
#include "modulos.h"

//Função que aloca os navios nas células
void alocarNavio(int i, Celulas tabuleiro[tamanho][tamanho], Player *jogador);

//Função que aloca os navios incialmente
void alocacaoInicial(int vezAtual, Celulas tabuleiro[tamanho][tamanho], Player *jogador);

//Função que prepara os navios para uma verificação de id
void prepararIds(Player *jogador);

//Função que verifica se o id não foi utilizado
int verificarAlocacao(int navio, Player *jogador);

//Função que verifica se é possível alocar navios naquela posição
int verificarPosicao(char direcao, int tamanho_navio, int x, int y, Celulas tabuleiro[tamanho][tamanho]);

//Função que verifica se a célula é viável para fazer alocação
int verificarViabilidade(int tamanho_navio, int x, int y, Celulas tabuleiro[tamanho][tamanho]);

//Função que verifica se o navio foi afundado
int verificarVida(int id, Celulas tabuleiro[tamanho][tamanho], Player *jogador);

#endif