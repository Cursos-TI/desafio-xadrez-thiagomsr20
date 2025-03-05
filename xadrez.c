#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 8

// Função para inicializar o tabuleiro com espaços vazios
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiro[i][j] = '.';
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para mover a Torre
void moverTorre(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y)
{
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        tabuleiro[x][i] = 'T';
        tabuleiro[i][y] = 'T';
    }
}

// Função para mover o Bispo
void moverBispo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y)
{
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        if (x + i < TAMANHO_TABULEIRO && y + i < TAMANHO_TABULEIRO)
            tabuleiro[x + i][y + i] = 'B';

        if (x - i >= 0 && y - i >= 0)
            tabuleiro[x - i][y - i] = 'B';

        if (x + i < TAMANHO_TABULEIRO && y - i >= 0)
            tabuleiro[x + i][y - i] = 'B';
        if (x - i >= 0 && y + i < TAMANHO_TABULEIRO)
            tabuleiro[x - i][y + i] = 'B';
    }
}

// Função para mover a Rainha
void moverRainha(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y)
{
    moverTorre(tabuleiro, x, y);
    moverBispo(tabuleiro, x, y);
}

// Função para mover o Cavalo
void moverCavalo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y)
{
    int movimentos[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    for (int i = 0; i < 8; i++)
    {
        int novoX = x + movimentos[i][0];
        int novoY = y + movimentos[i][1];
        if (novoX >= 0 && novoX < TAMANHO_TABULEIRO && novoY >= 0 && novoY < TAMANHO_TABULEIRO)
        {
            tabuleiro[novoX][novoY] = 'C';
        }
    }
}

int main()
{
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    int x, y;
    char peca;

    printf("Digite a peça (T para Torre, B para Bispo, R para Rainha, C para Cavalo): ");
    scanf(" %c", &peca);
    printf("Digite a posição inicial (x y): ");
    scanf("%d %d", &x, &y);

    switch (peca)
    {
    case 'T':
        moverTorre(tabuleiro, x, y);
        break;
    case 'B':
        moverBispo(tabuleiro, x, y);
        break;
    case 'R':
        moverRainha(tabuleiro, x, y);
        break;
    case 'C':
        moverCavalo(tabuleiro, x, y);
        break;
    default:
        printf("Peça inválida!\n");
        return 1;
    }

    imprimirTabuleiro(tabuleiro);
    return 0;
}