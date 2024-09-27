#include <stdio.h>

#define Lin 9
#define Col 9

//Imprimir tabuleiro
void imprimiTabuleiro(int vetor[Lin][Col]) {
    for(int i = 0; i < Lin; i++) {
        for(int j = 0; j < Col; j++) {
            printf("%d ", vetor[i][j]);
        }
        printf("\n");
    }
}

//Percorrer com Backtrack
void percorrer(int v[Lin][Col], int pino, int i, int j) {
    int movimentosValidos = 0;

    for(int x = 0; x < Lin; x++) {
        for(int y = 0; y < Col; y++) {
            if(v[x][y] == 1) {
                if((x + 2 < Lin && v[x + 2][y] == 0 || x + 2 < Lin && v[x + 2][y] == 0)) {
                    movimentosValidos++;
                }
            }
        }
    }

    if(movimentosValidos == 0) {
        printf("Jogadas terminadas!\n");
        return;
    }

    for(i = 0; i < Lin; i++) {
        for(j = 0; j < Col; j++) {
            if(v[i][j] == 1) {
                pino = v[i][j];

                if(i + 2 < Lin && v[i + 2][j] == 0) {
                    percorrer(v, pino, i + 2, j);
                    v[i + 2][j] = pino;
                    v[i + 1][j] = -1;
                    imprimiTabuleiro(v);
                }

                if(j + 2 < Col && v[i][j + 2] == 0) {
                    percorrer(v, pino, i, j + 2);
                    v[i][j + 2] = pino;
                    v[i][j + 1] = -1;
                    imprimiTabuleiro(v);
                }
            }
        }
    }
}

int main(void) {
    int matriz[Lin][Col] = 
    {
        {2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 0, 0, 0, 2, 2, 2},
        {2, 2, 2, 0, 0, 0, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 1, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 2, 2, 0, 0, 0, 2, 2, 2},
        {2, 2, 2, 0, 0, 0, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2},
    };
    int pino = 1;
    int i = 4, j = 4;

    percorrer(matriz, pino, i, j);
    return 0;
}