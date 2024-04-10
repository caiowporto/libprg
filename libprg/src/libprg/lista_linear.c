//
// Created by aluno on 06/03/24.

#include <stdio.h>
#include <libprg/libprg.h>


struct fila {
    int capacidade;
    int inicio;
    int fim;
    int tamanho;

};

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

//void enqueue(fila_t* fila) {
//
//}
