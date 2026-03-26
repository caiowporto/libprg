#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

// === PILHA ===

typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);

// === FILA ===

typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
int destruir_fila(fila_t* fila);

#endif
