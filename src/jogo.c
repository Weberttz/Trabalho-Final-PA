#include "../include/jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void novojogo(){
    montarTabuleiros();
    partida.rodada = 1;
    partida.vez = 1;
    partida.rodada_alocacao = 0;
    partida.fim = 0;

    clear();
    while(partida.rodada_alocacao == 0){
        if(partida.vez == 1)
            alocacaoInicial(partida.vez, tabuleiro_j1, &jogador1);
        else{
            alocacaoInicial(partida.vez, tabuleiro_j2, &jogador2);
            partida.rodada_alocacao = 1;
        }   
        printf("Pressione Enter para continuar...");
        getchar();
        getchar();
        partida.vez = trocarVez(partida.vez);
    }   
    salvarJogo();
    execJogo();
}

void execJogo(){
    int opc, sair = 0;
    while(!partida.fim && sair == 0){
        do{
        clear();
        printf("Rodada: %d\n", partida.rodada);
        printf("Vez do jogador %d\n", partida.vez);
        wprintf(L"Tabuleiro do jogador %d\n\n", 3 - partida.vez); 

        if(partida.vez == 1)
            imprimirTabuleiro(tabuleiro_j2);
        else
            imprimirTabuleiro(tabuleiro_j1);
        
        wprintf(L"\n[1] Realizar Palpite\n[0] Sair\nDigite uma opção: ");
        scanf("%d", &opc);
        clearBuffer();
            if(opc !=1 && opc !=0){
                wprintf(L"Opção inválida, tecle enter para continuar");
                getchar();
            }
        }while(opc !=1 && opc !=0);

        switch (opc) {
            case 1:
                if(partida.vez == 1)
                    realizarPalpite(&jogador1, &jogador2, tabuleiro_j2);
                else{
                    realizarPalpite(&jogador2, &jogador1 , tabuleiro_j1);
                    partida.rodada++;   
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                partida.vez = trocarVez(partida.vez);
                salvarJogo();
                break;
            case 0:
                //salvarJogo();
                sair = 1;
                break;
            default:
                wprintf(L"Opção inválida. Tente novamente.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }
        clear();
    }

    printf("Partida encerrada. Inicie uma nova partida.");
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

void realizarPalpite(Player *jogador, Player *jogador_adversario, Celulas tabuleiro_adversario[tamanho][tamanho]){
    int x,y, soma = 3; //Jogadores ( 1 + 2 )
    do {
        printf("Digite a linha do palpite (0-%d): " , tamanho-1);
        if(scanf("%d", &x) != 1) {
            wprintf(L"Entrada inválida! Digite um número!\n");
            clearBuffer();
            continue;
        }

        printf("Digite a coluna do palpite (0-%d): " , tamanho-1);
        if(scanf("%d", &y) != 1) {
            wprintf(L"Entrada inválida! Digite um número!\n");
            clearBuffer();
            continue;
        }
        if(x < 0 || x >= tamanho || y < 0 || y >= tamanho ){
            wprintf(L"Posição fora do tabuleiro! Tente novamente.\n");
            continue; 
        }
        if(tabuleiro_adversario[x][y].impressao == '#' || tabuleiro_adversario[x][y].impressao == '%' || tabuleiro_adversario[x][y].impressao == 'x'){
            wprintf(L"Você já tentou essa posição! Escolha outra. \n");
            continue;
        }
        break;
        
    }
    while(1);        
        
    if(tabuleiro_adversario[x][y].valor != 0){
        int id = tabuleiro_adversario[x][y].valor;

        printf("ACERTOU!\n");
        jogador->acertos++;
        tabuleiro_adversario[x][y].impressao = '%';

        if(verificarVida(tabuleiro_adversario[x][y].valor, tabuleiro_adversario, jogador)){
            printf("\nO navio %d foi afundado!", id);
            mudarRepNavio(id, tabuleiro_adversario);
            jogador_adversario->navios_restantes--;
        }
    }
    else{
        wprintf(L"Água!\n");
        tabuleiro_adversario[x][y].impressao = 'x';
        jogador->erros++;
    }
    printf("\nPressione enter para continuar");
    getchar();
    getchar();
    clear();
    wprintf(L"A configuração do tabuleiro do adversário ficou assim\n\n");
    imprimirTabuleiro(tabuleiro_adversario);

    if(jogador_adversario->navios_restantes == 0){
        printf("\nFim de jogo, jogador %d venceu!!", partida.vez);
        partida.vencedor = partida.vez;
        partida.perdedor = soma - partida.vez;
        partida.fim = 1;
        criarCreditos(jogador, jogador_adversario);
        chamarCreditos();
    }
}

int trocarVez(int vezAtual) {
    return (vezAtual == 1) ? 2 : 1;
}

void clear() {
    #ifdef _WIN32
    system("cls");
    #else 
    system("clear");
    #endif
}

void clearBuffer(){
    while (getchar() != '\n');
}

void instrucoes(){
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    clear();
    FILE *arquivo; 

    arquivo = fopen("../data/instrucoes.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
    }
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);

    printf("\nPressione Enter para voltar...");
    getchar();
    getchar();
    clear();
}

void criarCreditos(Player *jogador, Player *jogador_adversario){
    FILE *arquivo;
    const char *historico = "../data/partidas/historico_partida.txt";
    arquivo = fopen(historico, "w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo %s", historico);
    }


    fprintf(arquivo, "Quantidade de rodadas: %d\n", partida.rodada);
    fprintf(arquivo, "Jogador vencedor: %d\n", partida.vencedor);
    fprintf(arquivo, "Acertos: %d\n", jogador->acertos);
    fprintf(arquivo,"Erros: %d\n\n", jogador->erros);
    fprintf(arquivo, "Jogador perderdor %d\n", partida.perdedor);
    fprintf(arquivo, "Acertos: %d\n", jogador_adversario->acertos);
    fprintf(arquivo,"Erros: %d", jogador_adversario->erros);
    
    fclose(arquivo);
}

void chamarCreditos(){
    clear();
    FILE *arquivo;
    const char *historico = "../data/partidas/historico_partida.txt";
    char linha[256];
    arquivo = fopen(historico, "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo %s", historico);
    }

    while(fgets(linha, sizeof(linha), arquivo)){
        printf("%s", linha);
    }

    fclose(arquivo);
}
