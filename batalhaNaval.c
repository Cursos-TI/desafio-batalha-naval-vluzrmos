#include <stdio.h>

int TAMANHO_TABULEIRO_HORIZONTAL = 10;
int TAMANHO_TABULEIRO_VERTICAL = 10;
int AGUA=0;
int NAVIO=3;
int TAMANHO_NAVIO_1=3;
int TAMANHO_NAVIO_2=3;


void inicializa_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO_VERTICAL][TAMANHO_TABULEIRO_HORIZONTAL]) {
    for (int i = 0; i < TAMANHO_TABULEIRO_VERTICAL; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO_HORIZONTAL; j++) {
            tabuleiro[i][j] = AGUA; // Inicializa o tabuleiro com água
        }
    }
}
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Iniciando o tabuleiro com zeros (0 representa posição vazia, água)
    int tabuleiro[TAMANHO_TABULEIRO_VERTICAL][TAMANHO_TABULEIRO_HORIZONTAL];

    inicializa_tabuleiro(tabuleiro);
    int navio1[TAMANHO_NAVIO_1]; // Navio vertical
    int navio2[TAMANHO_NAVIO_2]; // Navio horizontal

    for (int i = 0; i < TAMANHO_NAVIO_1; i++) {
        navio1[i] = NAVIO;
    }

    for (int i = 0; i < TAMANHO_NAVIO_2; i++) {
        navio2[i] = NAVIO;
    }

    // inicializa 

    for (int i = 0; i < TAMANHO_NAVIO_1; i++) {
        tabuleiro[i][0] = navio1[i]; // Posicionando navio vertical na coluna 0
    }

    for (int i = 0; i < TAMANHO_NAVIO_2; i++) {
        tabuleiro[0][i+2] = navio2[i]; // Posicionando navio horizontal na linha 0
    }

    for (int i = 0; i < TAMANHO_TABULEIRO_VERTICAL; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO_HORIZONTAL; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
