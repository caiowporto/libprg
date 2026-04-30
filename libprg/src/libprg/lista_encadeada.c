//
// Created by aluno on 30/04/2026.
//
#include <libprg/libprg.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    no_t* proximo;
} no_t;

typedef struct nod {
    int dado;
    nod_t* anterior;
    nod_t* proximo;
} nod_t;

no_t* criar_lista_encadeada(int dado) {
    no_t* no = malloc(sizeof(no_t));
    no->dado = dado;
    no->proximo = NULL;
    return no;
}

nod_t* criar_lista_encadeada_dupla(int dado) {
    nod_t* nod = malloc(sizeof(nod_t));
    nod->dado = dado;
    nod->anterior = NULL;
    nod->proximo = NULL;
    return nod;
}

void inserir_encadeada(no_t** inicio, int dado) {
    no_t* novo = criar_lista_encadeada(dado);
    novo->proximo = *inicio;
    *inicio = novo;
}

void inserir_encadeada_dupla(nod_t** inicio, int dado) {
    nod_t* novo = criar_lista_encadeada_dupla(dado);
    novo->proximo = *inicio;
    (*inicio)->anterior = novo;
    *inicio = novo;
}

bool remover_encadeada(no_t** inicio, int dado) {
    no_t* atual = *inicio;
    no_t* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == dado) {
            if (anterior == NULL) *inicio = atual->proximo;
            else anterior->proximo = atual->proximo;
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

no_t* buscar(no_t** inicio, int dado) {
    no_t* atual = *inicio;
    while (atual != NULL) {
        if (atual->dado == dado) return atual;
        atual = atual->proximo;
    }
    return NULL;
}
void destruir_encadeada(no_t** inicio) {
    no_t* atual = *inicio;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}