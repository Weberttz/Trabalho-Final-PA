#ifndef MODULOS_H_
#define MODULOS_H_

#define total_navios 4

//struct que contém as informações de cada célula do tabuleiro
typedef struct{
    char impressao;
    int valor;
    int aberto;
}Celulas;

//Struct que contém as informações dos navios
typedef struct{
    int id, vida, tamanho_navio, pos_incial[2];
    char representante, direcao;
    int colocado;
}Navios;

//struct que contém as infomações de cada jogador
typedef struct {  
    Navios navios[total_navios];
    int acertos, erros, navios_restantes;
}Player;
//Struct que contém as informações do jogo
typedef struct {
    //Player p1, p2;
    int turno, rodada, rodada_alocacao;
}Jogo;

Player jogador1, jogador2;
Jogo partida;

//Função que limpa o terminal 
void clear();
//Função que limpa o buffer
void clearBuffer();

#endif