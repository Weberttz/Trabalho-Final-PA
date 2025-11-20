#ifndef JOGO_H_
#define JOGO_H_

#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

void novojogo(){
    montarTabuleiro();    
}

void instrucoes(){
    FILE *arquivo; 
    arquivo = fopen("../data/instrucoes.txt", "r");
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo))
    {    
    printf("%s", linha);
    }
}

#endif