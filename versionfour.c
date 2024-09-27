#include <stdio.h>

#define Lin 9
#define Col 9

// Imprimir tabuleiro
void imprimiTabuleiro(int vetor[Lin][Col]) {
    for(int i = 0; i < Lin; i++) {
        for(int j = 0; j < Col; j++) {
            printf("%d ", vetor[i][j]);
        }
        printf("\n");
    }
    printf("\n");  // Para separar diferentes estados do tabuleiro
}

// Percorrer com Backtrack
void percorrer(int v[Lin][Col], int pino, int i, int j) {
    int movimentosPossiveis = 0;

    // Verificar se há movimentos possíveis
    for(int x = 0; x < Lin; x++) {
        for(int y = 0; y < Col; y++) {
            if(v[x][y] == 1) {
                // Verificar movimentos possíveis para o pino
                if((x + 2 < Lin && v[x + 2][y] == 0) || (y + 2 < Col && v[x][y + 2] == 0)) {
                    movimentosPossiveis++;
                }
            }
        }
    }

    if(movimentosPossiveis == 0) {
        printf("Jogadas terminadas!\n");
        return;
    }

    // Percorrer o tabuleiro
    for(i = 0; i < Lin; i++) {
        for(j = 0; j < Col; j++) {
            if(v[i][j] == 1) {
                pino = v[i][j];

                // Movimento vertical (para baixo)
                if(i + 2 < Lin && v[i + 2][j] == 0) {
                    printf("Movendo pino da posicao [%d][%d] para [%d][%d]\n", i, j, i + 2, j);
                    v[i][j] = 0;
                    v[i + 2][j] = pino;
                    v[i + 1][j] = 0; // Marca o pino "pulando" o outro
                    imprimiTabuleiro(v);
                    percorrer(v, pino, i + 2, j); // Continua recursivamente
                }

                // Movimento horizontal (para a direita)
                if(j + 2 < Col && v[i][j + 2] == 0) {
                    printf("Movendo pino da posicao [%d][%d] para [%d][%d]\n", i, j, i, j + 2);
                    v[i][j] = 0;
                    v[i][j + 2] = pino;
                    v[i][j + 1] = 0; // Marca o pino "pulando" o outro
                    imprimiTabuleiro(v);
                    percorrer(v, pino, i, j + 2); // Continua recursivamente
                }
            }
        }
    }
}

int main(void) {
    int matriz[Lin][Col] = 
    {
        {2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 1, 1, 1, 2, 2, 2},
        {2, 2, 2, 1, 1, 1, 2, 2, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 1, 1, 1, 0, 1, 1, 1, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 2, 2, 1, 1, 1, 2, 2, 2},
        {2, 2, 2, 1, 1, 1, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2},
    };

    int pino = 1;  // Inicialização do pino
    int i = 4, j = 4;  // Iniciar a partir da posição central onde o pino está localizado

    // Imprimir tabuleiro inicial
    printf("Tabuleiro inicial:\n");
    imprimiTabuleiro(matriz);

    // Chamar função para percorrer
    percorrer(matriz, pino, i, j);

    return 0;
}