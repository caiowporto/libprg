
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

noa_t* remover_valor(noa_t* raiz, int dado) {
    if (raiz == NULL) return raiz;
    if (valor < raiz->dado) {
        raiz->esquerda = remover_valor(raiz->esquerda, dado);
    } else if (valor > raiz->dado) {
        raiz->direita = remover_valor(raiz->direita, dado);
    } else {
        // IF nó folha ou nó com um filho
        if (raiz->esquerda == NULL) {
            noa_t* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            noa_t* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // ELSE nó com dois filhos
        else {
            // Encontra o menor nó da direita direto aqui dentro
            noa_t* atual = raiz->direita;
            while (atual->esquerda != NULL) {
                atual = atual->esquerda;
            }
            // Copia o valor do menor da direita para o nó atual
            raiz->dado = atual->dado;                
            // Remove o nó copiado da subárvore direita
            raiz->direita = remover_valor(raiz->direita, atual->dado);
        }
    }
    return raiz;
}

bool busca(noa_t* raiz, int dado) {
    if (raiz == NULL) return false;
    if (dado == raiz->dado) return true;
    if (dado < raiz->dado) return busca(raiz->esquerda, dado);
    return busca(raiz->direita, dado);
}

bool busca_it(noa_t* raiz, int dado) {
    noa_t* atual = raiz;
    while (atual != NULL) {
        if (dado == atual->dado) {
            return true;
        }
        if (dado < atual->dado) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }
    return false;
}
