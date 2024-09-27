#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 31
#define LINHAS 9
#define COLUNAS 9

struct stack {
    int top;
    int (*valores[TAM_MAX])[COLUNAS];
};

struct stack* createStack() {
    struct stack* nova_pilha = (struct stack*) malloc(sizeof(struct stack));
    nova_pilha->top = -1;
    return nova_pilha;
}

int isEmptyStack(struct stack* stack) {
    return stack->top == -1;
}

int isFullStack(struct stack* stack) {
    return stack->top == TAM_MAX - 1;
}

void push(struct stack* stack, int matriz[LINHAS][COLUNAS]) {
    if (isFullStack(stack)) {
        printf("Erro: a stack está cheia.\n");
    } else {
        stack->top++;
        stack->valores[stack->top] = malloc(sizeof(int[LINHAS][COLUNAS]));
        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                stack->valores[stack->top][i][j] = matriz[i][j];
            }
        }
    }
}

int (*pop(struct stack* stack))[COLUNAS] {
    if (isEmptyStack(stack)) {
        printf("Erro: a stack está vazia.\n");
        return NULL;
    } else {
        int (*matriz_removida)[COLUNAS] = stack->valores[stack->top];
        stack->top--;
        return matriz_removida;
    }
}

int (*top(struct stack* stack))[COLUNAS] {
    if (isEmptyStack(stack)) {
        printf("Erro: a stack está vazia.\n");
        return NULL;
    } else {
        return stack->valores[stack->top];
    }
}

void imprimirMatriz(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct stack* stack = createStack();

    int matriz1[LINHAS][COLUNAS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    int matriz2[LINHAS][COLUNAS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 5, 0, 0, 0, 1},
        {1, 0, 0, 0, 5, 0, 0, 0, 1},
        {1, 0, 0, 0, 5, 0, 0, 0, 1},
        {1, 0, 0, 0, 5, 0, 0, 0, 1},
        {1, 0, 0, 0, 5, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    int matriz3[LINHAS][COLUNAS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 9, 0, 0, 0, 1},
        {1, 0, 0, 0, 9, 0, 0, 0, 1},
        {1, 0, 0, 0, 9, 0, 0, 0, 1},
        {1, 0, 0, 0, 9, 0, 0, 0, 1},
        {1, 0, 0, 0, 9, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    push(stack, matriz1);
    push(stack, matriz2);
    push(stack, matriz3);

    printf("Matriz no topo da pilha:\n");
    imprimirMatriz(*top(stack));

    int (*matriz_removida)[COLUNAS] = pop(stack);
    if (matriz_removida) {
        printf("Matriz removida da pilha:\n");
        imprimirMatriz(matriz_removida);
        free(matriz_removida);
    }

    printf("Matriz no topo da pilha:\n");
    imprimirMatriz(*top(stack));

    free(stack);
    return 0;
}
