//Nome: Bruno Antico Galin RA: 10417318
//Nome: Ismael de Sousa Silva RA: 10410870
#include <stdio.h>
#include <stdlib.h>

#define Lin 9
#define Col 9

int main(void) {
    int i, j; 
    char mat[Lin][Col];
    FILE *arquivo; 

    arquivo = fopen("tabuleiro.txt", "r");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }
    
    for(i = 0; i < Lin; i++) {
        for(j = 0; j < Col; j++) {
            fscanf(arquivo, "%c", &mat[i][j]);
        }
        fgetc(arquivo);
    }

    fclose(arquivo);

    for(i = 0; i < Lin; i++) {
        for(j = 0; j < Col; j++) {
            if(mat[i][j] == '#' || mat[i][j] == 'o' || mat[i][j] == ' '){
                printf("%c", mat[i][j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}