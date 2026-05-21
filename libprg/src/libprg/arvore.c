
#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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

void travessia_emordem(noa_t* raiz) {
    if (raiz != NULL) {
        travessia_emordem(raiz->esquerda);
        printf("%d ", raiz->dado);
        travessia_emordem(raiz->direita);
    }
}

void travessia_preordem(noa_t* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        travessia_preordem(raiz->esquerda);
        travessia_preordem(raiz->direita);
    }
}

void travessia_posordem(noa_t* raiz) {
    if (raiz != NULL) {
        travessia_posordem(raiz->esquerda);
        travessia_posordem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}