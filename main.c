#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define Lin 9
#define Col 9

int cont = 0; // Contador global para os movimentos válidos

// Imprimir tabuleiro
void imprimirTabuleiro(int vetor[Lin][Col]) {
    printf("Movimento %d\n", cont);
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
        printf("\n"); // Quebra de linhas no tabuleiro
    }
    Sleep(1000); // Timeout de 1 segundo entre jogadas
    printf("\n");  // Quebra de linha entre diferentes movimentos do tabuleiro
}

int contarPinos(int v[Lin][Col]) { // Contagem de pinos restantes
    int count = 0;

    for(int i = 0; i < Lin; i++) {
        for(int j = 0; j < Col; j++) {
            if(v[i][j] == 1) { // Se o elemento for um pino, incrementa a contagem
                count++;
            }
        }
    }
    return count;
}

bool percorrer(int v[Lin][Col], int pino) {
    // Verifica se existe apenas um pino no tabuleiro
    int Umpino = contarPinos(v);
    // Caso base para que só tenha um pino no centro e outros espaços vazios
    if(Umpino == 1 && v[4][4] == 1) {
        printf("Jogadas terminadas! Movimentos válidos: %d\n", cont);
        imprimirTabuleiro(v);
        return true;
    }

    // Verifica se o contador atingiu 31
    if (cont >= 31) {
        return true; // Termina se atingir 31 movimentos
    }

    // Percorrendo a matriz do tabuleiro
    for(int i = 0; i < Lin; i++) {
       for(int j = 0; j < Col; j++) {
          // Valida os movimentos com os elementos de valor 1 (pinos)
          if(v[i][j] == 1) { // Se for um pino, temos que tirá-lo analisando suas direções
                for (int k = 0; k < 4; k++){
                // Tentativas válidas em quatro direções
                    if(i + 2 < Lin && v[i + 2][j] == 0 && v[i + 1][j] == 1) { // Baixo
                        printf("Movendo pino da posicao [%d][%d] para [%d][%d]\n", i, j, i + 2, j);
                        v[i][j] = 0;
                        v[i + 2][j] = pino;
                        v[i + 1][j] = 0; // Marca o pino "pulando" o outro
                        cont++; // Incrementa o contador
                        imprimirTabuleiro(v);
                        if (percorrer(v, pino)){ // Backtracking
                            return true;
                        }
                    }

                    if(j + 2 < Col && v[i][j + 2] == 0 && v[i][j + 1] == 1) { // Direita
                        printf("Movendo pino da posicao [%d][%d] para [%d][%d]\n", i, j, i, j + 2);
                        v[i][j] = 0;
                        v[i][j + 2] = pino;
                        v[i][j + 1] = 0; // Marca o pino "pulando" o outro
                        cont++; // Incrementa o contador
                        imprimirTabuleiro(v);
                        if (percorrer(v, pino)){ // Backtracking
                            return true;
                        }
                    }

                    if(i - 2 >= 0 && v[i - 2][j] == 0 && v[i - 1][j] == 1) { // Cima
                        printf("Movendo pino da posicao [%d][%d] para [%d][%d]\n", i, j, i - 2, j);
                        v[i][j] = 0;
                        v[i - 2][j] = pino;
                        v[i - 1][j] = 0; // Marca o pino "pulando" o outro
                        cont++; // Incrementa o contador
                        imprimirTabuleiro(v);
                        if (percorrer(v, pino)){ // Backtracking
                            return true;
                        }
                    }

                    if(j - 2 >= 0 && v[i][j - 2] == 0 && v[i][j - 1] == 1) { // Esquerda
                        printf("Movendo pino da posicao [%d][%d] para [%d][%d]\n", i, j, i, j - 2);
                        v[i][j] = 0;
                        v[i][j - 2] = pino;
                        v[i][j - 1] = 0; // Marca o pino "pulando" o outro
                        cont++; // Incrementa o contador
                        imprimirTabuleiro(v);
                        if (percorrer(v, pino)){ // Backtracking
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
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

    int pino = 1; 

    // Imprimir tabuleiro inicial
    printf("Tabuleiro inicial:\n");
    imprimirTabuleiro(matriz);

    bool tentativas[Lin][Col] = {false};

    // Chamar função para percorrer
    if (!percorrer(matriz, pino)){
        printf("Não foram encontradas jogadas.");
    }
    return 0;
}
