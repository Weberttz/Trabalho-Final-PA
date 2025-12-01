#include <stdio.h>
#include "../include/salvar.h"

/*
A ordem dos saves é importante, pois da forma que a gente salvar influencia na forma de carregar

1 - quantidade de rodadas           |   struct Jogo

2 - acertos do jogador 1            |
3 - erros do jogador 1              |   struct Player que contém o struct Navios
4 - navios restantes do jogador 1   |
5 - struct de navios do jogador 1   |

5- impressoes de cada célula do tabuleiro do joagdor 1  |   struct Celulas
6 - valores de cada célula do tabuleiro do jogador 1    |

Análogo para o jogador 2
*/

//olha lákkkkk, como que tá ai? o save.txt sério? Aqui tá estranho, olha lá no zap
// 
const char *nomeArquivo = "../data/partidas/save.txt"; 

void salvarJogo() {
    FILE *arquivo = fopen(nomeArquivo, "w");
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

    printf("Jogo salvo com sucesso em '%s'.\n", nomeArquivo);
}

void carregarJogo() {
    FILE *arquivo = fopen (nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar o jogo.\n");
        return;
    }

    fread(&partida, sizeof(Jogo), 1, arquivo);
    fread(&jogador1, sizeof(Player), 1, arquivo);
    fread(&tabuleiro_j1, sizeof(Celulas), tamanho * tamanho, arquivo);
    fread(&jogador2, sizeof(Player), 1, arquivo);
    fread(&tabuleiro_j2, sizeof(Celulas), tamanho * tamanho, arquivo);
    fclose(arquivo);

    printf("Jogo carregado do local '%s'.\n", nomeArquivo);
}