#include "../include/tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

void montarTabuleiros() {
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            tabuleiro_j1[i][j].impressao = '~';
            tabuleiro_j2[i][j].impressao = '~';

            tabuleiro_j1[i][j].valor = 0;
            tabuleiro_j2[i][j].valor = 0;
            
            tabuleiro_j1[i][j].aberto = 0;
            tabuleiro_j2[i][j].aberto = 0;
        }
    }
}

void imprimirTabuleiro(Celulas tabuleiro[tamanho][tamanho]) {
    printf("    ");
    
    for(int j = 0; j< tamanho; j++){
        printf("%d  ", j);
    }
    printf("\n");

    for(int i = 0; i< tamanho; i++){
        printf("%2d  ", i);
        for(int j=0; j< tamanho; j++){
                printf("%c  ", tabuleiro[i][j].impressao);
        }
        printf("\n");
    }
}

void mudarRepresentantes(Celulas tabuleiro[tamanho][tamanho]){

    for(int i=0; i<tamanho; i++){
        for(int j=0; j<tamanho; j++){
            tabuleiro[i][j].impressao = '~';
        }
    } 
}


