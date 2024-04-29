#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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


//----------------------- PROJETO LISTA CONTATOS --------------------------------

typedef struct {
    char fone[20];
    char nome[50];
    char email[100];
} listacontato;

#define max_contatos 20

void adicionarcontato(listacontato *contatos, int *num_contatos, const char *nome, const char *telefone, const char *email);

void visualizarcontatos(listacontato *contatos, int num_contatos);

listacontato buscarcontato(listacontato *contatos, int num_contatos, const char *busca);

void editar_contato(listacontato *contatos, int num_contatos, const char *nome, const char *novo_telefone, const char *novo_email);

void excluir_contato(listacontato *contatos, int *num_contatos, const char *nome);

void salvarcontatosbinario(listacontato *contatos, int num_contatos);

//----------------------- LISTA ENCADEADA ---------------------------------------

typedef struct no no_t;

void adicionarno(no_t** inicio, int dado);

no_t* buscarno(no_t* inicio, int dado);

bool removerno(no_t** inicio, int dado);

void destruirlistaenc(no_t** inicio);

void adicionarnocirc(no_t** inicio, int dado);
















//-------------------------------------------------------------------------------

#endif
















