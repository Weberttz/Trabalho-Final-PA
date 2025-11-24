#ifndef MODULOS_H_
#define MODULOS_H_

#define total_navios 4

//struct que contém os conteúdos de cada célula do tabuleiro
typedef struct{
    char impressao;
    int valor;
    int aberto;
}Celulas;

typedef struct{
    int id, vida, tamanho_navio, pos_incial[2];
    char representante, direcao;
    int colocado;
}Navios;

typedef struct {  
    // TODO : ver isso em algum momento. 
    //! Opção mais usual seria Tamanho_navio
    Navios navios[total_navios];
    int acertos, erros, navios_restantes;
}Player;

typedef struct {
    //Player p1, p2;
    int turno, rodada, rodada_alocacao;
}Jogo;

Player jogador1, jogador2;
Jogo partida;

//Função que limpa o terminal
void clear();

#endif