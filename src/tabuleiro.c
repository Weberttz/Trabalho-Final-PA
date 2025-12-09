#include "../include/tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

Celulas tabuleiro_j1[tamanho][tamanho], tabuleiro_j2[tamanho][tamanho];

void montarTabuleiros() {
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            tabuleiro_j1[i][j].impressao = '~';
            tabuleiro_j2[i][j].impressao = '~';

            tabuleiro_j1[i][j].valor = 0;
            tabuleiro_j2[i][j].valor = 0;
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
            switch(tabuleiro[i][j].impressao){
                case '~':
                    printf("\033[34m%c  \33[0m", tabuleiro[i][j].impressao);
                break;
                case 'b':
                    printf("\033[32m%c  \33[0m", tabuleiro[i][j].impressao);
                break;
                case 'n':
                    printf("\033[32m%c  \33[0m", tabuleiro[i][j].impressao);
                break;
                case 'p':
                    printf("\033[32m%c  \33[0m", tabuleiro[i][j].impressao);
                break;
                case 's':
                    printf("\033[32m%c  \33[0m", tabuleiro[i][j].impressao);
                break;
                case '%':
                    printf("\033[31m%c  \33[0m", tabuleiro[i][j].impressao);
                break;
                case 'x':
                    printf("\033[37m%c  \33[0m", tabuleiro[i][j].impressao);
                break;
                case '#':
                    printf("\033[31m%c  \33[0m", tabuleiro[i][j].impressao);
                break;
            }
            
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

void mudarRepNavio(int id, Celulas tabuleiro[tamanho][tamanho])
{
    for(int i=0; i<tamanho; i++){
        for(int j=0; j<tamanho; j++){
            if(tabuleiro[i][j].valor == id)
                tabuleiro[i][j].impressao = '#';
        }
    }
}

