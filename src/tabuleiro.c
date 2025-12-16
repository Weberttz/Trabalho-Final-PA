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
    printf("\n    ");
    
    for(int j = 0; j< tamanho; j++){
        printf("%d  ", j);
    }
    printf("\n");

    for(int i = 0; i< tamanho; i++){
        printf("%2d  ", i);
        // 34 -> Azul do mar
        // 32 -> Verde do j1
        // 33 -> Amarelo do j2
        for(int j=0; j< tamanho; j++){
            switch(tabuleiro[i][j].impressao){
                case '~':
                    printf("\033[34m%c  \33[0m", tabuleiro[i][j].impressao);
                break;
                case 'b':
                if (partida.vez == 1)
                    printf("\033[32m%c  \033[0m", tabuleiro[i][j].impressao);  
                else
                    printf("\033[33m%c  \033[0m", tabuleiro[i][j].impressao);   
                break;
                case 'n':
                if (partida.vez == 1)
                    printf("\033[32m%c  \033[0m", tabuleiro[i][j].impressao);
                else
                    printf("\033[33m%c  \033[0m", tabuleiro[i][j].impressao);
                break;
                case 'p':
                if (partida.vez == 1)
                    printf("\033[32m%c  \033[0m", tabuleiro[i][j].impressao);
                else
                    printf("\033[33m%c  \033[0m", tabuleiro[i][j].impressao);
                break;
                case 's':
                if (partida.vez == 1)
                    printf("\033[32m%c  \033[0m", tabuleiro[i][j].impressao);
                else
                    printf("\033[33m%c  \033[0m", tabuleiro[i][j].impressao);
                break;
                case '%':
                if (partida.vez == 1)
                    printf("\033[32m%c  \033[0m", tabuleiro[i][j].impressao);  
                else
                    printf("\033[33m%c  \033[0m", tabuleiro[i][j].impressao); 
                break;
                case 'x':
                if (partida.vez == 1)
                    printf("\033[32m%c  \033[0m", tabuleiro[i][j].impressao);  
                else
                    printf("\033[33m%c  \033[0m", tabuleiro[i][j].impressao);  
                break;
                case '#':
                if (partida.vez == 1)
                    printf("\033[32m%c  \033[0m", tabuleiro[i][j].impressao);  
                else
                    printf("\033[33m%c  \033[0m", tabuleiro[i][j].impressao);  
                break;

            }
            
        }
        printf("\n");
    }
}

void mudarRepTabuleiro(Celulas tabuleiro[tamanho][tamanho]){
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