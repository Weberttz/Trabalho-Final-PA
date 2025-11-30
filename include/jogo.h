#ifndef JOGO_H_
#define JOGO_H_

#include <wchar.h>
#include "modulos.h"
#include "tabuleiro.h"
#include "navios.h"

//Função que cria um novo jogo
void novojogo();
//Função que alterna os turnos dos jogadores
int trocarVez(int vezAtual);
//Função que imprime as instruções
void instrucoes();
//Função dos palpites dos jogdores
void realizarPalpite(Player *jogador, Celulas tabuleiro_adversario[tamanho][tamanho]);

#endif
