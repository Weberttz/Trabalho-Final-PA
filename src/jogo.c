#include "../include/jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

Player jogador1, jogador2;
Jogo partida;

void novojogo(){
    montarTabuleiros();
    partida.tam_historico = 1;
    partida.historico = malloc((partida.tam_historico+1) * sizeof(char*));
    partida.rodada = 1;
    partida.vez = 1;
    partida.rodada_alocacao = 0;
    partida.fim = 0;

    clear();
    while(partida.rodada_alocacao == 0){
        if(partida.vez == 1)
            alocarInicialmente(partida.vez, tabuleiro_j1, &jogador1);
        else{
            alocarInicialmente(partida.vez, tabuleiro_j2, &jogador2);
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

void mostrarNaviosRestantes(Player *jogador){
    char *nomes[] = {"Bote", "Submarino", "Navio-tanque", "Porta-avioes"};

    printf("\n--- Navios restantes para acertar ---\n");
    printf("\nTotal: %d\n", jogador->navios_restantes);

    for(int i = 0; i < total_navios; i++){
        if(jogador->navios[i].id <= 0) continue;

        int id = jogador->navios[i].id;
        int vida = jogador->navios[i].vida;
        //int total = jogador->navios[i].tamanho_navio;
        
        printf("# %s (ID %d): %s\n",nomes[id - 1],id, vida == 0 ? "[AFUNDADO]" : "[VIVO]");
    }

    printf("\n");
}

void execJogo(){
    int opc, sair = 0;
    while(!partida.fim && sair == 0){
        do{
            clear();
            printf("-> Rodada: %d\n", partida.rodada);
            printf("-> Vez do jogador: %d\n\n", partida.vez);
            printf("--> Tabuleiro do jogador %d \n", 3 - partida.vez); 

            if(partida.vez == 1)
                imprimirTabuleiro(tabuleiro_j2);
            else 
                imprimirTabuleiro(tabuleiro_j1);

            if(partida.vez == 1)
            mostrarNaviosRestantes(&jogador1);
            else
            mostrarNaviosRestantes(&jogador2);

            printf("\n[1] Realizar Palpite\n[0] Sair\nDigite uma opcao: ");
            scanf("%d", &opc);
            clearBuffer();
            if(opc !=1 && opc !=0){
                printf("Opção invalida, tecle enter para continuar");
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
                    
                partida.vez = trocarVez(partida.vez);
                salvarJogo();
                break;
            case 0:
                sair = 1;
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }
        clear();
    }
    if(partida.fim){
        chamarCreditos();
        printf("\n\nPartida encerrada. Inicie uma nova partida.");
        printf("\nPressione Enter para continuar...");
        getchar();
        getchar();
    }
}

void realizarPalpite(Player *jogador, Player *jogador_adversario, Celulas tabuleiro_adversario[tamanho][tamanho]){
    int x,y, soma = 3; //Jogadores ( 1 + 2 )
    do {
        printf("Digite a linha do palpite (0-%d): " , tamanho-1);
        if(scanf("%d", &x) != 1) {
            printf("Entrada invalida! Digite um número!\n");
            clearBuffer();
            continue;
        }

        printf("Digite a coluna do palpite (0-%d): " , tamanho-1);
        if(scanf("%d", &y) != 1) {
            printf("Entrada invalida! Digite um numero!\n");
            clearBuffer();
            continue;
        }
        if(x < 0 || x >= tamanho || y < 0 || y >= tamanho ){
            printf("Posicao fora do tabuleiro! Tente novamente.\n");
            continue; 
        }
        if(tabuleiro_adversario[x][y].impressao == '#' || tabuleiro_adversario[x][y].impressao == '%' || tabuleiro_adversario[x][y].impressao == 'x'){
            printf("Voce ja tentou essa posicao! Escolha outra. \n");
            continue;
        }
        break;
        
    }
    while(1);

 
    if(tabuleiro_adversario[x][y].valor != 0){
        int id = tabuleiro_adversario[x][y].valor;
        tabuleiro_adversario[x][y].impressao = '%';
        printf("\nACERTOU!\n");
        partida.historico[partida.tam_historico-1] = "Acertou";
        jogador->acertos++;

        if(verificarVida(tabuleiro_adversario[x][y].valor, tabuleiro_adversario, jogador)){
            printf("\nO navio %d foi afundado!", id);
            mudarRepNavio(id, tabuleiro_adversario);
            jogador_adversario->navios_restantes--;
        }
    }
    else{
        tabuleiro_adversario[x][y].impressao = 'x';
        printf("\nAcertou... na Agua! :p\n");
        partida.historico[partida.tam_historico-1] = "Errou";
        jogador->erros++;
    }
    printf("\nPressione enter para continuar");
    getchar();
    getchar();
    clear();
    printf("A configuracao do tabuleiro do inimigo ficou assim");
    imprimirTabuleiro(tabuleiro_adversario);
    printf("\nPressione enter para continuar");
    getchar();
    clear();

    if(jogador_adversario->navios_restantes == 0){
        printf("\nFim de jogo, jogador %d venceu!!", partida.vez);
        partida.vencedor = partida.vez;
        partida.perdedor = soma - partida.vez;
        partida.fim = 1;
        criarCreditos(jogador, jogador_adversario);
    }
    partida.tam_historico +=1;
    partida.historico = realloc(partida.historico, partida.tam_historico * sizeof(char*));
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
    fprintf(arquivo,"Erros: %d\n\n", jogador_adversario->erros);

    int k = 0;
    fprintf(arquivo, "Rodada\t   Jogador1     Jogador2\n");
    for(int i=0; i<partida.tam_historico; i++){
        if(i%2 == 0)
            fprintf(arquivo, "%d\t   %s", k+1, partida.historico[i]);
        else{
            fprintf(arquivo, "\t%s\n", partida.historico[i]);
            k++;
        }
    }
    
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
