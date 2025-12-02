#include <stdio.h>
#include <ctype.h>
#include "../include/navios.h"

void prepararIds(Player *jogador){
    for(int i = 0; i<total_navios; i++){
       jogador->navios[i].id = -1;
    }
}

int verificarAlocacao(int i, Player *jogador){
    for(int j=0; j<total_navios; j++){
            if(j != i && jogador->navios[j].id == jogador->navios[i].id){
                printf("Esse navio ja foi alocado, tente outro\n");
                return 0;
        }
    }
    return 1;
}

int verificarViabilidade(int tamanho_navio, int x, int y, Celulas tabuleiro[tamanho][tamanho]) {
    if (verificarPosicao('s', tamanho_navio, x, y, tabuleiro)) return 1;
    if (verificarPosicao('n', tamanho_navio, x, y, tabuleiro)) return 1;
    if (verificarPosicao('l', tamanho_navio, x, y, tabuleiro)) return 1;
    if (verificarPosicao('o', tamanho_navio, x, y, tabuleiro)) return 1;
    return 0;
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

void alocarNavio(int i, Celulas tabuleiro[tamanho][tamanho], Player *jogador){
    int x = jogador->navios[i].pos_incial[0];
    int y = jogador->navios[i].pos_incial[1];
    
    for(int l = 0; l< jogador->navios[i].tamanho_navio; l++){
        
        switch (jogador->navios[i].direcao)
        {
        case 's':
            tabuleiro[x + l][y].impressao = jogador->navios[i].representante;
            tabuleiro[x + l][y].valor = jogador->navios[i].id;
            break;
        case 'n':
            tabuleiro[x - l][y].impressao = jogador->navios[i].representante;
            tabuleiro[x - l][y].valor = jogador->navios[i].id;
            break;
        case 'l':
            tabuleiro[x][y + l].impressao = jogador->navios[i].representante;
            tabuleiro[x][y + l].valor = jogador->navios[i].id;
            break;
        case 'o':
            tabuleiro[x][y - l].impressao = jogador->navios[i].representante;
            tabuleiro[x][y-l].valor = jogador->navios[i].id;
            break;
        default:
            break;
        }
    }
}

void alocacaoInicial(int vezAtual, Celulas tabuleiro[tamanho][tamanho], Player *jogador){

    int i = 0, valor[total_navios] = {0};
    jogador->navios_restantes = total_navios;
    prepararIds(jogador);
    char *nomes[] = {"Bote", "Submarino", "Navio-tanque", "Porta-avioes"};

    do{
        clear();
        wprintf(L"---Período de alocação dos navios---\n\n");
        printf("Vez do jogador %d\n\n", vezAtual);
        imprimirTabuleiro(tabuleiro);

        wprintf(L"\nExistem %d navios restantes para alocação.\n\n", total_navios - i);

        for(int j = 0; j < total_navios; j++){
            if(valor[j] == 0){
                printf("# ID %d -> %s\n", j+1, nomes[j]);
            }
        }
        
        do{
            printf("\nDigite o id do navio que vc quer alocar:");
            if(scanf("%d", &jogador->navios[i].id) != 1){
                wprintf(L"Entrava inválida. Digite um número!\n");
                clearBuffer();
                continue;
            }
            if(jogador->navios[i].id < 1 || jogador->navios[i].id > total_navios){
                printf("ID fora do intervalo! Digite entre 1 e %d \n", total_navios);
                continue;
            }
            if(!verificarAlocacao(i, jogador)){
                continue;
            }
            break;
        }while(1);

        valor[jogador->navios[i].id-1] = jogador->navios[i].id;
        switch (jogador->navios[i].id)
        {
        case 1:
            jogador->navios[i].representante = 'b';
            jogador->navios[i].tamanho_navio = 2;
            jogador->navios[i].vida = 2;
            break;
        case 2:
            jogador->navios[i].representante = 's';
            jogador->navios[i].tamanho_navio = 3;
            jogador->navios[i].vida = 3;
            break;
        case 3:
            jogador->navios[i].representante = 'n';
            jogador->navios[i].tamanho_navio = 4;
            jogador->navios[i].vida = 4;
            break;
        case 4:
            jogador->navios[i].representante = 'p';
            jogador->navios[i].tamanho_navio = 5;
            jogador->navios[i].vida = 5;
            break;  
        default:
            wprintf(L"Valor inválido.");    
            continue;
            break;
        }
        do{
            wprintf(L"Digite a linha da posição incial do seu navio: ");
             if(scanf("%d", &jogador->navios[i].pos_incial[0]) != 1){
                wprintf(L"Entrava inválida. Digite um número!\n");
                clearBuffer(); 
                continue;
            }
            wprintf(L"Digite a coluna da posição incial do seu navio: ");
             if(scanf("%d", &jogador->navios[i].pos_incial[1]) != 1){
                wprintf(L"Entrava inválida. Digite um número!\n");
                clearBuffer(); 
                continue;
            } 
            int l = jogador->navios[i].pos_incial[0];
            int c = jogador->navios[i].pos_incial[1];
                     
            if(l >= tamanho || l < 0 ||
            c >= tamanho ||c < 0){
                printf("Posicao fora do mapa. D:<\n");
                continue;
            }
            if(tabuleiro[l][c].valor != 0)
            {
                printf("Ja possui um navio nessa posicao. =/\n");
                continue;
            }
            if(!verificarViabilidade(jogador->navios[i].tamanho_navio, l, c, tabuleiro)) { 
                wprintf(L"Impossível alocar o navio de tamanho %d a partir desta posição em QUALQUER direção. Escolha outra posição, bobão! \n", jogador->navios[i].tamanho_navio);
                continue;
            }
            break;
        }while(1);
        
        do{
            printf("Digite a direção do seu navio (n, s, l, o): ");
            scanf(" %c", &jogador->navios[i].direcao);
            jogador->navios[i].direcao = tolower(jogador->navios[i].direcao); 
            
            if(!verificarPosicao(jogador->navios[i].direcao, jogador->navios[i].tamanho_navio, 
                jogador->navios[i].pos_incial[0], jogador->navios[i].pos_incial[1], tabuleiro)){
                wprintf(L"Impossível colocar navio nessa direção!\n"); 
            }else {
                break;
            }
        }while(1);
        
        alocarNavio(i, tabuleiro, jogador);
        i++;
        
    }while(i < total_navios);
    clear();
    printf("Tabuleiro do jogador %d\n\n", vezAtual);
    imprimirTabuleiro(tabuleiro);
    mudarRepresentantes(tabuleiro);
    wprintf(L"\nConfiguração bem sucedida.\n");
}

int verificarNavio(int id, char impressao, Celulas tabuleiro[tamanho][tamanho], Player *jogador){
    int contador = 0;
    for(int i=0; i<tamanho; i++){
        for(int j = 0; j<tamanho; j++){
            if(tabuleiro[i][j].valor == id && tabuleiro[i][j].impressao == impressao){ 
                contador++;
            }
        }
    }
    for(int i = 0; i<total_navios; i++){
        if(jogador->navios[i].id == id && contador == jogador->navios[i].tamanho_navio)
            return 1;
        
    }
    return 0;
}
