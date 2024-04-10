//
// Created by aluno on 08/04/24.
//
#include <stdio.h>
#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila {
    int *vetor;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;

} fila_t;

fila_t* cria_fila(int capacidade) {
    fila_t* fila = (fila_t*) malloc(sizeof(fila_t));
    if (fila != NULL) {
        fila->fim = 0;
        fila->inicio = 0;
        fila->tamanho = 0;
        fila->capacidade = capacidade;
    } else {
        printf("Não é possível criar a fila.");
    }
}

void enqueue(fila_t* fila) {

}
