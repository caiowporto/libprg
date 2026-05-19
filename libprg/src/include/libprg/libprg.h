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
typedef struct lista_encadeada lista_encadeada_t;
no_t* criar_no(int dado);
lista_encadeada_t* criar_lista_encadeada(bool ordenada);
void inserir_encadeada(lista_encadeada_t* inicio, int dado);
bool remover_encadeada(lista_encadeada_t* lista, int dado);
no_t* buscar(lista_encadeada_t* lista, int dado);
void destruir_encadeada(lista_encadeada_t* lista);

// === LISTA ENCADEADA DUPLA ===

typedef struct nod nod_t;
nod_t* criar_lista_encadeada_dupla(int dado);
void inserir_encadeada_dupla(nod_t** inicio, int dado);
bool remover_encadeada_dupla(nod_t** inicio, int dado);
nod_t *buscar_encadeada_dupla(nod_t **inicio, int dado);
void destruir_encadeada_dupla(nod_t** inicio);

// === ALGORITMOS DE ORDENAÇÃO ===

int* bubble_sort(int* vetor, int tamanho);
int* merge_sort(int* vetor, int esquerda, int direita);

// === TABELA DE DISPERSÃO(HASH) ===

typedef struct noh noh_t;
typedef struct dicionario dicionario_t;
dicionario_t* criar_dicionario(int m);
int inserir_hash(dicionario_t* d, char* chave, int valor);

// === ÁRVORE ===

typedef struct noa noa_t;
noa_t* criar_noa(int dado);
noa_t* adicionar_noa(noa_t* raiz, int dado);

#endif
