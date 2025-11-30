#include <stdio.h>
#include "salvar.h"

void salvarJogo(){
    FILE *arquivo_salvo;

    arquivo_salvo = fopen("../partidas/save.txt", "w");
    if(arquivo_salvo == NULL){
        printf("Erro ao abrir o arquivo");
    }

    for(int i=0; i<tamanho; i++)
    {
        for(int j = 0; i<tamanho; j++){
            fscanf(arquivo_salvo, "%c", tabuleiro_j1[i][j].impressao);
        }
    }
    
}