#ifndef JOGO_H_
#define JOGO_H_

#include <wchar.h>
#include "modulos.h"
#include "tabuleiro.h"
#include "navios.h"
#include "salvar.h"

//Função que cria um novo jogo
void novojogo();

//Função que alterna os turnos dos jogadores
int trocarVez(int vezAtual);

//Função que imprime as instruções
void instrucoes();

//Função dos palpites dos jogdores
void realizarPalpite(Player *jogador, Player *jogador_adversario, Celulas tabuleiro_adversario[tamanho][tamanho]);

//Função que executa o jogo
void execJogo();

//Função que cria o arquivo txt com as informações de quem venceu, perdeu, acertos e erros dos dois jogadores
void criarCreditos();

//Função que lê as informações do arquivo txt com o histórico da partida
void chamarCreditos();

#endif
