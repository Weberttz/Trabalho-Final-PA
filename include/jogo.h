#ifndef JOGO_H_
#define JOGO_H_

#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

void novojogo(){
    montarTabuleiros();
    imprimirTabuleiro(); 
}

void clear() {
    #ifdef _WIN32
    system("cls");
    #else 
    system("clear");
    #endif
}

void instrucoes(){
    FILE *arquivo; 
    int resposta = 1;
    inicio_instrucoes:
    arquivo = fopen("../data/instrucoes.txt", "r");
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo))
    {    
    printf("%s", linha);
    }
    
    while(resposta != 0){
        printf("\nDigite 0 para voltar.\n");
        scanf("%d", &resposta);
        clear();
        goto inicio_instrucoes;
    }
}
#endif