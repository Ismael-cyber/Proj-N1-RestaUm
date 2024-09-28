#include <stdio.h>

#define Lin 9
#define Col 9

// Imprimir tabuleiro
void imprimiTabuleiro(int vetor[Lin][Col]) {
    for (int i = 0; i < Lin; i++) {
        for (int j = 0; j < Col; j++) {
            if (vetor[i][j] == 2) {
                printf("# ");  // Delimitador do tabuleiro
            } else if (vetor[i][j] == 1) {
                printf("o ");  // Pinos
            } else if (vetor[i][j] == 0) {
                printf("  ");  // Espaço vazio
            }
        }
        printf("\n");
    }
    printf("\n");  // Para separar diferentes estados do tabuleiro
}


void percorrer(int v[Lin][Col], int pino, int i, int j) {
    //Caso base para que só tenha uma peça(1) no centro e outros espaços vazios(0)
    if(pino == v[4][4] && pino == 1) {
        printf("Jogadas terminadas!\n");
        return;
    }

    pino = 1;

    //Percorrendo o Vetor e ao mesmo tempo verificando movimentos válidos
    for(i = 0; i < Lin; i++) {
       for(j = 0; j < Col; j++) {
          //Valida os Movimentos Apenas com os elementos de valor 1
          if(v[i][j] == 1) {
                if(i + 2 < Lin && v[i + 2][j] == 0 && v[i + 1][j] == 1) {
                    printf("Movendo pino da posicao [%d][%d] para [%d][%d]\n", i, j, i + 2, j);
                    v[i][j] = 0;
                    v[i + 2][j] = pino;
                    v[i + 1][j] = 0; // Marca o pino "pulando" o outro
                    imprimiTabuleiro(v);
                    percorrer(v, pino, i + 2, j); // Continua recursivamente
                }

                if(j + 2 < Col && v[j + 2][j] == 0 && v[i][j + 2] == 1) {
                    printf("Movendo pino da posicao [%d][%d] para [%d][%d]\n", i, j, i, j + 2);
                    v[i][j] = 0;
                    v[i][j + 2] = pino;
                    v[i][j + 1] = 0; // Marca o pino "pulando" o outro
                    imprimiTabuleiro(v);
                    percorrer(v, pino, i, j + 2); // Continua recursivamente
                }

                if(i - 2 >= 0 && v[i - 2][j] == 0 && v[i - 1][j] == 1) {
                    printf("Movendo pino da posicao [%d][%d] para [%d][%d]\n", i, j, i - 2, j);
                    v[i][j] = 0;
                    v[i - 2][j] = pino;
                    v[i - 1][j] = 0; // Marca o pino "pulando" o outro
                    imprimiTabuleiro(v);
                    percorrer(v, pino, i - 2, j); // Continua recursivamente
                }

                if(j - 2 >= 0 && v[i][j - 2] == 0 && v[i][j - 2] == 1) {
                    printf("Movendo pino da posicao [%d][%d] para [%d][%d]\n", i, j, i, j - 2);
                    v[i][j] = 0;
                    v[i][j - 2] = pino;
                    v[i][j - 1] = 0; // Marca o pino "pulando" o outro
                    imprimiTabuleiro(v);
                    percorrer(v, pino, i, j - 2); // Continua recursivamente
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

    int pino, i, j;

    // Imprimir tabuleiro inicial
    printf("Tabuleiro inicial:\n");
    imprimiTabuleiro(matriz);

    // Chamar função para percorrer
    percorrer(matriz, pino, i, j);
    return 0;
}