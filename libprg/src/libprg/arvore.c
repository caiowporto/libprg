
#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noa {
    int dado;
    noa_t* esquerda;
    noa_t* direita;
} noa_t;


noa_t* criar_noa(int dado) {
    noa_t* no = malloc(sizeof(noa_t));
    no->dado = dado;
    no->esquerda = no->direita = NULL;
    return no;
}

noa_t* adicionar_noa(noa_t* raiz, int dado) {
    if (raiz == NULL) return criar_noa(dado);
    if (dado < raiz->dado) {
        raiz->esquerda = adicionar_noa(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = adicionar_noa(raiz->direita, dado);
    }
    return raiz;
}

// remover

void destruir_no(noa_t* no) {
    if (no != NULL) {
        destruir_no(no->esquerda);
        destruir_no(no->direita);
        free(no);
    }
}