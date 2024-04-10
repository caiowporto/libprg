#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct lista lista_t;


// função para criar lista
int criar_lista(lista_t *lista);

// função inserir
int inserir_lista();



typedef struct fila fila_t;

//criar - Criar a lista
fila_t* fila (int capacidade);

//enfileirar - Adiciona um elemento no final da fila
void enqueue(fila_t* fila, int elemento);

//desenfileirar - Remove o elemento que está no início da fila
int dequeue(fila_t* fila);

//início - Retorna o elemento que está no início da fila
int gethead(fila_t* fila);

//fim - Retorna o elemento que está no final da fila
int gettail(fila_t* fila);

//tamanho - Retorna o total de elementos na fila
int getsize(fila_t* fila);

//vazia - Indica se a fila está vazia ou não
bool isempty(fila_t* fila);

//cheia - Indica se a fila está cheia ou não
bool isfull(fila_t* fila);


#endif