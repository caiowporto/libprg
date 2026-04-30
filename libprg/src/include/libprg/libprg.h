#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

// === PILHA ===

typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int pilha_vazia(pilha_t* pilha);
int pilha_cheia(pilha_t *pilha);
void pilha_destruir(pilha_t* pilha);
int empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t *pilha);
int topo_pilha(pilha_t *pilha);
int tamanho_pilha(pilha_t *pilha);

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

// === LISTA LINEAR ===

typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista_linear(int capacidade, int ordenada);
void lista_adicionar(lista_linear_t* lista, int valor);
int lista_busca(lista_linear_t* lista, int valor);
int lista_busca_bin(lista_linear_t* lista, int valor);
bool removel(lista_linear_t* lista, int valor);
void lista_destruir(lista_linear_t* lista);
int lista_tamanho(lista_linear_t* lista);
int lista_first(lista_linear_t* lista);
int lista_percorrer(lista_linear_t* lista, int i);

// === LISTA ENCADEADA SIMPLES ===

typedef struct no no_t;
no_t* criar_lista_encadeada(int dado);
void inserir_encadeada(no_t** inicio, int dado);
bool remover_encadeada(no_t** inicio, int dado);
no_t* buscar(no_t** inicio, int dado);
void destruir_encadeada(no_t** inicio);

// === LISTA ENCADEADA DUPLA ===

typedef struct nod nod_t;


#endif
