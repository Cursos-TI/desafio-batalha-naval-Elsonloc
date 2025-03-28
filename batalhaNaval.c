#include <stdio.h>

// Desafio Batalha Naval - Elson dev
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.



#define TAMANHO_TABULEIRO 10
#define TAMANHO_PECA 3
// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '0';  // Representa água no tabuleiro
        }
    }
}

// Função para imprimir o tabuleiro com as colunas identificadas por letras e as linhas por números
void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Imprimir as letras das colunas
    printf("    ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2c ", 'A' + i);  // Colunas identificadas pelas letras A, B, C, ...
    }
    printf("\n");

    // Imprimir as linhas numeradas de 1 a 10
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);  // Exibe o número da linha (de 1 a 10)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2c ", tabuleiro[i][j]);  // Exibe o conteúdo da célula
        }
        printf("\n");
    }
}

// Função para colocar uma peça no tabuleiro (horizontal, vertical ou diagonal)
int colocarPeca(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    // Direção 0 = Horizontal, 1 = Vertical, 2 = Diagonal principal, 3 = Diagonal secundária
    if (direcao == 0) { // Horizontal
        if (coluna + TAMANHO_PECA > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_PECA; i++) {
            if (tabuleiro[linha][coluna + i] != '0') return 0;
        }
        for (int i = 0; i < TAMANHO_PECA; i++) {
            tabuleiro[linha][coluna + i] = '3';
        }
    } else if (direcao == 1) { // Vertical
        if (linha + TAMANHO_PECA > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_PECA; i++) {
            if (tabuleiro[linha + i][coluna] != '0') return 0;
        }
        for (int i = 0; i < TAMANHO_PECA; i++) {
            tabuleiro[linha + i][coluna] = '3';
        }
    } else if (direcao == 2) { // Diagonal principal (↘)
        if (linha + TAMANHO_PECA > TAMANHO_TABULEIRO || coluna + TAMANHO_PECA > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_PECA; i++) {
            if (tabuleiro[linha + i][coluna + i] != '0') return 0;
        }
        for (int i = 0; i < TAMANHO_PECA; i++) {
            tabuleiro[linha + i][coluna + i] = '3';
        }
    } else if (direcao == 3) { // Diagonal secundária (↙)
        if (linha + TAMANHO_PECA > TAMANHO_TABULEIRO || coluna - TAMANHO_PECA < 0) return 0;
        for (int i = 0; i < TAMANHO_PECA; i++) {
            if (tabuleiro[linha + i][coluna - i] != '0') return 0;
        }
        for (int i = 0; i < TAMANHO_PECA; i++) {
            tabuleiro[linha + i][coluna - i] = '3';
        }
    }
    return 1;
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    srand(time(NULL));
    inicializarTabuleiro(tabuleiro);

    // Posicionando as peças
    if (!colocarPeca(tabuleiro, 4, 0, 0)) printf("Erro ao colocar a primeira peça.\n");
    if (!colocarPeca(tabuleiro, 6, 7, 1)) printf("Erro ao colocar a segunda peça.\n");
    if (!colocarPeca(tabuleiro, 2, 2, 2)) printf("Erro ao colocar a terceira peça (diagonal principal).\n");
    if (!colocarPeca(tabuleiro, 1, 8, 3)) printf("Erro ao colocar a quarta peça (diagonal secundária).\n");

    // Exibindo o tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;


    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

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

    
}
