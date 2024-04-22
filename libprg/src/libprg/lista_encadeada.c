//
// Created by aluno on 15/04/24.
//
#include "libprg/libprg.h"

typedef struct no{
    int dado;
    struct no* proximo;
} no_t;

//adicionar novo nó
void adicionarno(no_t** inicio, int dado){
    no_t* novo = (no_t*) malloc(sizeof (no_t));
    novo->dado = dado;
    novo->proximo = *inicio;
    *inicio = novo;
}

//buscar nó
no_t* buscarno(no_t* inicio, int dado){
    no_t* atual = inicio;
    while (atual != NULL){
        if (atual->dado == dado) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}


//remover nó
bool removerno(no_t** inicio, int dado){
    no_t* atual = *inicio;
    no_t* anterior = NULL;
    while(atual != NULL) {
        if (atual->dado == dado){
            if (anterior == NULL) {
                *inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}


//destruir lista
void destruirlistaenc(no_t** inicio){
    no_t* atual = *inicio;
    no_t* prox;
    while(atual != NULL){
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}