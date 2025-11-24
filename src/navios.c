#include <stdio.h>
#include "../include/navios.h"

void preparaIds(Player *jogador){
    for(int i = 0; i<total_navios; i++){
       jogador->navios[i].id = -1;
    }
}

int verificarId(int i, Player *jogador){
    if(jogador->navios[i].id < 1 || jogador->navios[i].id > total_navios){
        printf("Esse navio não existe\n");
        return 0;
    }
    for(int j=0; j<total_navios; j++){
            if(j != i && jogador->navios[j].id == jogador->navios[i].id){
                printf("Esse navio ja foi alocado, tente outro\n");
                return 0;
        }
    }
    return 1;
}

int verificarPosicao(char direcao, int tamanho_navio, int x, int y, Celulas tabuleiro[tamanho][tamanho]){
    switch (direcao)
    {
        case 's':
            for(int l = 0; l< tamanho_navio; l++){
                if(x + l >= tamanho) return 0;
                if(tabuleiro[x+l][y].valor != 0) return 0;
            }
            break;
        case 'n':
            for(int l = 0; l < tamanho_navio; l++){
                if(x - l < 0) return 0;
                if(tabuleiro[x-l][y].valor != 0) return 0;
            }
            break;
        case 'l':
            for(int l = 0; l < tamanho_navio; l++){
                if(y + l >= tamanho) return 0;
                if(tabuleiro[x][y+l].valor != 0) return 0;
            }
            break;
        case 'o':
            for(int l = 0; l < tamanho_navio; l++){
                if(y - l < 0) return 0;
                if(tabuleiro[x][y-l].valor != 0) return 0;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void alocarNavio(int i, Celulas tabuleiro[tamanho][tamanho], Player jogador){
    int x = jogador.navios[i].pos_incial[0];
    int y = jogador.navios[i].pos_incial[1];
    
    for(int l = 0; l< jogador.navios[i].tamanho_navio; l++){
        
        switch (jogador.navios[i].direcao)
        {
        case 's':
            tabuleiro[x + l][y].impressao = jogador.navios[i].representante;
            tabuleiro[x + l][y].valor = jogador.navios[i].id;
            break;
        case 'n':
            tabuleiro[x - l][y].impressao = jogador.navios[i].representante;
            tabuleiro[x - l][y].valor = jogador.navios[i].id;
            break;
        case 'l':
            tabuleiro[x][y + l].impressao = jogador.navios[i].representante;
            tabuleiro[x][y + l].valor = jogador.navios[i].id;
            break;
        case 'o':
            tabuleiro[x][y - l].impressao = jogador.navios[i].representante;
            tabuleiro[x][y-l].valor = jogador.navios[i].id;
            break;
        default:
            break;
        }
    }
}

void alocacaoInicial(int vezAtual, Celulas tabuleiro[tamanho][tamanho], Player jogador){
    
    int i = 0, valor[total_navios] = {0};
    preparaIds(&jogador);
    char *nomes[] = {"Bote", "Submarino", "Navio-tanque", "Porta-aviões"};

    do{
        clear();
        printf("---Período de alocação dos barcos---\n\n");
        printf("Vez do jogador %d\n\n", vezAtual);
        imprimirTabuleiro(tabuleiro);

        printf("\nsExistem %d barcos restantes para alocação.\n\n", total_navios - i);

        for(int j = 0; j < total_navios; j++){
            if(valor[j] == 0){
                printf("# ID %d -> %s\n", j+1, nomes[j]);
            }
        }
        id:
        printf("\nDigite o id do navio que vc quer alocar:");
        scanf("%d", &jogador.navios[i].id);
        if(!verificarId(i, &jogador)){
            goto id;
        };
        valor[jogador.navios[i].id-1] = jogador.navios[i].id;
        switch (jogador.navios[i].id)
        {
        case 1:
            jogador.navios[i].representante = 'b';
            jogador.navios[i].tamanho_navio = 2;
            break;
        case 2:
            jogador.navios[i].representante = 's';
            jogador.navios[i].tamanho_navio = 3;
            break;
        case 3:
            jogador.navios[i].representante = 'n';
            jogador.navios[i].tamanho_navio = 4;
            break;
        case 4:
            jogador.navios[i].representante = 'p';
            jogador.navios[i].tamanho_navio = 5;
            break;  
        default:
            printf("Valor inválido.");
            goto id;
            break;
        }
        pos:
        printf("Digite a posicao inicial do seu navio, x e y separados por espaco: ");
        scanf("%d %d%*c", &jogador.navios[i].pos_incial[0], &jogador.navios[i].pos_incial[1]);
        if(jogador.navios[i].pos_incial[0] > tamanho-1 || jogador.navios[i].pos_incial[0] < 0 ||
            jogador.navios[i].pos_incial[1] > tamanho-1 ||jogador.navios[i].pos_incial[1] < 0){
            printf("Posicao fora do mapa\n");
            goto pos;
        }
        if(tabuleiro[jogador.navios[i].pos_incial[0]][jogador.navios[i].pos_incial[1]].valor != 0)
        {
            printf("Ja possui um barco nessa posicao\n");
            goto pos;
        }

        direcao:
        printf("Digite a direção do seu navio (s, n, l, o): ");
        scanf("%c%*c", &jogador.navios[i].direcao);
        if(!verificarPosicao(jogador.navios[i].direcao, jogador.navios[i].tamanho_navio, 
            jogador.navios[i].pos_incial[0], jogador.navios[i].pos_incial[1], tabuleiro)){
            printf("Impossível colocar navio nessa direção!\n");
            goto direcao;
        }
        alocarNavio(i, tabuleiro, jogador);
        
        i++;
    }while(i < total_navios);
    mudarRepresentantes(tabuleiro); 
}
