#include <stdio.h>

int TAMANHO_TABULEIRO_HORIZONTAL = 10;
int TAMANHO_TABULEIRO_VERTICAL = 10;

int VALOR_AGUA=0;
int VALOR_NAVIO=3;
int VALOR_HABILIDADE=5;

int TAMANHO_NAVIO_1=3;
int TAMANHO_NAVIO_2=3;
int TAMANHO_NAVIO_3=3;
int TAMANHO_NAVIO_4=3;

void inicializa_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO_VERTICAL][TAMANHO_TABULEIRO_HORIZONTAL]) {
    for (int i = 0; i < TAMANHO_TABULEIRO_VERTICAL; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO_HORIZONTAL; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

void inicializa_navio(int navio[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        navio[i] = VALOR_NAVIO;
    }
}

void posiciona_navio_vertical(int tabuleiro[TAMANHO_TABULEIRO_VERTICAL][TAMANHO_TABULEIRO_HORIZONTAL], int navio[], int tamanho, int linha, int coluna) {
    if (tamanho + linha > TAMANHO_TABULEIRO_VERTICAL) {
        printf("Erro: O navio não pode ser posicionado verticalmente nessa posição.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha + i][coluna] != VALOR_AGUA) {
            printf("Erro: O navio não pode ser posicionado verticalmente nessa posição, pois há um navio já presente.\n");
            return;
        }
    }

    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha + i][coluna] = navio[i];
    }
}

void posiciona_navio_horizontal(int tabuleiro[TAMANHO_TABULEIRO_VERTICAL][TAMANHO_TABULEIRO_HORIZONTAL], int navio[], int tamanho, int linha, int coluna) {
    if (tamanho + coluna > TAMANHO_TABULEIRO_HORIZONTAL) {
        printf("Erro: O navio não pode ser posicionado horizontalmente nessa posição.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha][coluna + i] != VALOR_AGUA) {
            printf("Erro: O navio não pode ser posicionado horizontalmente nessa posição, pois há um navio já presente.\n");
            return;
        }
    }

    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha][coluna + i] = navio[i];
    }
}

void posiciona_navio_diagonal(int tabuleiro[TAMANHO_TABULEIRO_VERTICAL][TAMANHO_TABULEIRO_HORIZONTAL], int navio[], int tamanho, int linha, int coluna) {
    if (tamanho + linha > TAMANHO_TABULEIRO_VERTICAL || tamanho + coluna > TAMANHO_TABULEIRO_HORIZONTAL) {
        printf("Erro: O navio não pode ser posicionado diagonalmente nessa posição.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha + i][coluna + i] != VALOR_AGUA) {
            printf("Erro: O navio não pode ser posicionado diagonalmente nessa posição, pois há um navio já presente.\n");
            return;
        }
    }

    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha + i][coluna + i] = navio[i];
    }
}

void exibe_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO_VERTICAL][TAMANHO_TABULEIRO_HORIZONTAL]) {
    for (int i = 0; i < TAMANHO_TABULEIRO_VERTICAL; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO_HORIZONTAL; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


void ataque_habilidade(int tabuleiro[TAMANHO_TABULEIRO_VERTICAL][TAMANHO_TABULEIRO_HORIZONTAL], int habilidade[3][5], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {
                int alvo_linha = linha + i - 1; // Centraliza a habilidade
                int alvo_coluna = coluna + j - 2; // Centraliza a habilidade

                if (alvo_linha >= 0 && alvo_linha < TAMANHO_TABULEIRO_VERTICAL &&
                    alvo_coluna >= 0 && alvo_coluna < TAMANHO_TABULEIRO_HORIZONTAL) {
                    tabuleiro[alvo_linha][alvo_coluna] = VALOR_HABILIDADE;
                }
            }
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

    int tabuleiro[TAMANHO_TABULEIRO_VERTICAL][TAMANHO_TABULEIRO_HORIZONTAL];
    int navio1[TAMANHO_NAVIO_1]; // Navio vertical
    int navio2[TAMANHO_NAVIO_2]; // Navio horizontal
    int navio3[TAMANHO_NAVIO_3]; // Navio diagonal
    int navio4[TAMANHO_NAVIO_4]; // Navio diagonal
    
    inicializa_tabuleiro(tabuleiro);
    inicializa_navio(navio1, TAMANHO_NAVIO_1);
    inicializa_navio(navio2, TAMANHO_NAVIO_2);
    inicializa_navio(navio3, TAMANHO_NAVIO_3);
    inicializa_navio(navio4, TAMANHO_NAVIO_4);

    posiciona_navio_horizontal(tabuleiro, navio2, TAMANHO_NAVIO_2, 0, 0);
    posiciona_navio_vertical(tabuleiro, navio1, TAMANHO_NAVIO_1, 2, 1);

    // posiciona navios errados
    // Exemplos de navios posicionado fora dos limites do tabuleiro
    // posiciona_navio_horizontal(tabuleiro, navio2, TAMANHO_NAVIO_2, 0, 8);
    // posiciona_navio_vertical(tabuleiro, navio1, TAMANHO_NAVIO_1, 8, 1);
    //posiciona_navio_diagonal(tabuleiro, navio3, TAMANHO_NAVIO_3, 8, 8);

    printf("Tabuleiro após posicionamento dos navios iniciais:\n\n");
    exibe_tabuleiro(tabuleiro);
    printf("\n------\n\n");

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    posiciona_navio_diagonal(tabuleiro, navio3, TAMANHO_NAVIO_3, 5, 5);
    posiciona_navio_diagonal(tabuleiro, navio4, TAMANHO_NAVIO_4, 7, 2);
    printf("Tabuleiro após posicionamento dos navios diagonais:\n\n");
    exibe_tabuleiro(tabuleiro);

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    int habilidade_cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    int habilidade_octaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    int habilidade_cruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };
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

    ataque_habilidade(tabuleiro, habilidade_cone, 0, 0);
    ataque_habilidade(tabuleiro, habilidade_octaedro, 5, 5);
    ataque_habilidade(tabuleiro, habilidade_cruz, 7, 2);
    printf("Tabuleiro após ataque com habilidades:\n\n");
    exibe_tabuleiro(tabuleiro);

    return 0;
}
