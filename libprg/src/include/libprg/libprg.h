#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//------------------------ LISTA -------------------------------------------------

typedef struct lista lista_t;


// função para criar lista
int criar_lista(lista_t *lista);

// função inserir
int inserir_lista();


//------------------------ FILA --------------------------------------------------

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


//----------------------- PROJETO CONTATOS --------------------------------------
#define num_max_contatos 10
#define num_max_carac_fone 15
#define num_max_carac_nome 50
#define num_max_carac_email 50

typedef struct {
    char fone[num_max_carac_fone];
    char nome[num_max_carac_nome];
    char email[num_max_carac_email];
} Contato;


//----------------------- LISTA ENCADEADA ---------------------------------------

typedef struct no no_t;

void adicionarno(no_t** inicio, int dado);

no_t* buscarno(no_t* inicio, int dado);

bool removerno(no_t** inicio, int dado);

void destruirlistaenc(no_t** inicio);

void adicionarnocirc(no_t** inicio, int dado);
















//-------------------------------------------------------------------------------

#endif
















