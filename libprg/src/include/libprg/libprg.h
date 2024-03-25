#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <libprg/libprg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct lista lista_t;


// função para criar lista
int criar_lista(lista_t *lista);

// função inserir
int inserir_lista();




typedef struct fila fila_t;

//enfileirar - Adiciona um elemento no final da fila
fila_t enqueue(int capacidade);

//desenfileirar - Remove o elemento que está no início da fila
int dequeue(fila_t* f);

//início - Retorna o elemento que está no início da fila
int head(fila_t) {
};

//fim - Retorna o elemento que está no final da fila
int tail(fila_t);

//tamanho - Retorna o total de elementos na fila
int size();

//vazia - Indica se a fila está vazia ou não
int empty(fila_t* f);

//cheia - Indica se a fila está cheia ou não
int full();




#endif