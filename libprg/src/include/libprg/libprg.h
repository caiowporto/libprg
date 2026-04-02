#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

// === PILHA ===

typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
bool vazia_p(pilha_t* pilha);

// === FILA ===

typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
int desenfileirar(fila_t* fila);
int destruir_fila(fila_t* fila);
bool fila_cheia(fila_t* fila);
bool fila_vazia(fila_t* fila);
int fila_inicio(fila_t* fila);
int fila_fim(fila_t* fila);
int fila_tamanho(fila_t* fila);

// === LISTA ===

typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista_linear(int capacidade, int ordenada);

#endif
